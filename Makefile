#
# Utility to generate an image tree blob (ITB) comprising a signed System
# Firmware (SYSFW) binary image as released by TI as well as domain-specific
# SYSFW configuration fragments provided in the form of C sources.
#
# Copyright (C) 2018-2019 Texas Instruments Incorporated - http://www.ti.com/
#	Andreas Dannenberg <dannenberg@ti.com>
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#
#    Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
#    Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the
#    distribution.
#
#    Neither the name of Texas Instruments Incorporated nor the names of
#    its contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

SOC ?= am65x
ifdef HS
SOC_TYPE ?= hs
else
SOC_TYPE ?= gp
endif
CONFIG ?= evm

BASE_SOC = $(firstword $(subst _, ,${SOC}))

include soc/$(BASE_SOC)/Makefile

ifeq ($(SOC_TYPE),gp)
ifeq ($(SOC), j721e_sr1_1)
override SOC = j721e
endif
endif

BUILD_SRC ?= .
O ?= out
BIN_DIR ?= .

srcroot = $(BUILD_SRC)
soc_srcroot = $(srcroot)/soc/${BASE_SOC}/${CONFIG}
objroot = $(O)
soc_objroot = $(objroot)/soc/${BASE_SOC}/${CONFIG}

binroot = $(BIN_DIR)

# The HS SYSFW will only work on HS hardware when signed with valid
# keys, warn HS users if the SECDEV environment variable is not set
ifneq ($(SOC_TYPE),gp)
ifeq ($(TI_SECURE_DEV_PKG),)
$(error TI_SECURE_DEV_PKG must be set for HS, defaults will not work)
endif
# On HS board configuration binaries must be individually signed when not using a combined boot image
ifeq (,$(SBL))
SIGN_BRDCFG = 1
endif
endif

# If using the default SYSFW make sure to manually copy/populate the unsigned
# image into the root folder of this repository.
SYSFW_DIR ?= .
ifeq ($(SOC_TYPE),gp)
SYSFW_PATH               ?= $(SYSFW_DIR)/ti-$(SCIFS)-firmware-$(SOC)-$(SOC_TYPE).bin
else
SYSFW_PATH               ?= $(SYSFW_DIR)/ti-$(SCIFS)-firmware-$(SOC)-$(SOC_TYPE)-enc.bin
SYSFW_HS_INNER_CERT_PATH ?= $(SYSFW_DIR)/ti-$(SCIFS)-firmware-$(SOC)-$(SOC_TYPE)-cert.bin
endif

SYSFW_HS_CERTS_PATH ?= ti-$(SCIFS)-firmware-$(SOC)-$(SOC_TYPE)-certs.bin

# Must use FULL Git hash below, as it is used as part of an URL for direct DL
SYSFW_GIT_HASH ?= 2d9a1002663a20673d942826c558ba4b472ffe9a

# URL to download SYSFW release binary from if not provided otherwise
SYSFW_DL_URL ?= https://git.ti.com/processor-firmware/ti-linux-firmware/blobs/raw/$(SYSFW_GIT_HASH)/ti-sysfw/$(SYSFW_PATH)
SYSFW_HS_INNER_CERT_DL_URL ?= https://git.ti.com/processor-firmware/ti-linux-firmware/blobs/raw/$(SYSFW_GIT_HASH)/ti-sysfw/$(SYSFW_HS_INNER_CERT_PATH)

# Set HS SYSFW image signing key
ifneq ($(SOC_TYPE),gp)
KEY ?= $(TI_SECURE_DEV_PKG)/keys/custMpk.pem
else
KEY ?= ti-degenerate-key.pem
endif

# Set HS Software Revision
ifneq ($(SOC_TYPE),gp)
SW_REV ?= $(shell cat $(TI_SECURE_DEV_PKG)/keys/swrv.txt)
else
SW_REV ?= 1
endif

CROSS_COMPILE ?= arm-none-linux-gnueabihf-

CFLAGS ?= \
	-fno-builtin \
	-Wall \
	-Iinclude/soc/${BASE_SOC} \
	-Isoc/${BASE_SOC}/${CONFIG} \
	-Iinclude

ifdef ENABLE_TRACE
CFLAGS += -DENABLE_TRACE
endif

SOURCES ?= \
	board-cfg.c \
	pm-cfg.c \
	rm-cfg.c \
	sec-cfg.c

SOC_BINS=$(soc_objroot)/sysfw.bin-$(SOC_TYPE)
ifdef SIGN_BRDCFG
SOC_BINS += $(SOURCES:%.c=$(soc_objroot)/%.bin-signed)
else
SOC_BINS += $(SOURCES:%.c=$(soc_objroot)/%.bin)
endif

ITB ?= $(binroot)/sysfw-$(SOC)-$(CONFIG).itb
ITS ?= $(soc_objroot)/$(basename $(notdir $(ITB))).its
COMBINED_SYSFW_BRDCFG ?= $(soc_objroot)/combined-sysfw-cfg.bin
COMBINED_TIFS_BRDCFG ?= $(soc_objroot)/combined-tifs-cfg.bin
COMBINED_DM_BRDCFG ?= $(soc_objroot)/combined-dm-cfg.bin
TIBOOT3 ?= $(binroot)/tiboot3-$(SOC)-$(SOC_TYPE)-$(CONFIG).bin

vpath %.itb $(soc_objroot)
vpath %.bin $(soc_objroot)
vpath %.o $(soc_objroot)
vpath %.c $(soc_srcroot)

MKIMAGE ?= mkimage

ifeq ($(shell which python3),)
$(error "No python3 in $(PATH), consider installing python3")
endif

.PHONY: all
ifeq (,$(SBL))
ifeq ($(BASE_SOC),$(findstring $(BASE_SOC),("am62x")))
all: ; $(error "Cannot build non-combined boot image for $(BASE_SOC), define SBL image")
else
all: _objtree_build sysfw.itb
endif
else
ifeq ($(BASE_SOC),$(findstring $(BASE_SOC),("j721e" "am65x")))
all: ; $(error "Cannot build combined boot image for $(BASE_SOC), do not define SBL image")
else
all: _objtree_build tiboot3.bin
endif
endif

.PHONY: _objtree_build
_objtree_build:
	@mkdir -p $(objroot) $(soc_objroot) $(binroot)

$(SYSFW_PATH):
	@echo "Downloading SYSFW release image..."
	wget $(SYSFW_DL_URL)
	@echo "Download SUCCESS!"

$(SYSFW_HS_INNER_CERT_PATH):
	@echo "Downloading HS SYSFW release certificate..."
	wget $(SYSFW_HS_INNER_CERT_DL_URL)
	@echo "Download SUCCESS!"

ifneq ($(SOC_TYPE),gp)
$(SYSFW_HS_CERTS_PATH): $(SYSFW_HS_INNER_CERT_PATH)
	@echo "Signing the SYSFW inner certificate with $(KEY) key...";
	./gen_x509_cert.sh -d -c m3 -b $< -o $@ -l $(LOADADDR) -k $(KEY) -r $(SW_REV);

$(soc_objroot)/sysfw.bin-$(SOC_TYPE): $(SYSFW_HS_CERTS_PATH) $(SYSFW_HS_PATH)
	cat $^ > $@
else
$(soc_objroot)/sysfw.bin-$(SOC_TYPE): $(SYSFW_PATH)
	@echo "Signing the SYSFW release image with $(KEY) key...";
	./gen_x509_cert.sh -c m3 -b $< -o $@ -l $(LOADADDR) -k $(KEY) -r $(SW_REV);
endif

$(ITS): $(SOC_BINS)
	./gen_its.sh $(SOC) $(SOC_TYPE) $(CONFIG) $(SOC_BINS) > $@

$(ITB): $(ITS)
	$(MKIMAGE) -f $< -r $@

sysfw.itb: $(ITB)
	@ln -sf $< $@

$(COMBINED_SYSFW_BRDCFG): $(soc_objroot)/board-cfg.bin $(soc_objroot)/sec-cfg.bin $(soc_objroot)/pm-cfg.bin $(soc_objroot)/rm-cfg.bin
	python3 ./scripts/sysfw_boardcfg_blob_creator.py -b $(soc_objroot)/board-cfg.bin -s $(soc_objroot)/sec-cfg.bin -p $(soc_objroot)/pm-cfg.bin -r $(soc_objroot)/rm-cfg.bin -o $@

$(COMBINED_TIFS_BRDCFG): $(soc_objroot)/board-cfg.bin $(soc_objroot)/sec-cfg.bin $(soc_objroot)/pm-cfg.bin $(soc_objroot)/rm-cfg.bin
	python3 ./scripts/sysfw_boardcfg_blob_creator.py -b $(soc_objroot)/board-cfg.bin -s $(soc_objroot)/sec-cfg.bin -p $(soc_objroot)/pm-cfg.bin -r $(soc_objroot)/rm-cfg.bin -o $@

$(COMBINED_DM_BRDCFG): $(soc_objroot)/pm-cfg.bin $(soc_objroot)/rm-cfg.bin
	python3 ./scripts/sysfw_boardcfg_blob_creator.py -p $(soc_objroot)/pm-cfg.bin -r $(soc_objroot)/rm-cfg.bin -o $@

ifneq (,$(COMBINED_SYSFW_BRDCFG_LOADADDR))
$(TIBOOT3): $(SBL) $(SYSFW_PATH) $(SYSFW_HS_INNER_CERT_PATH) $(COMBINED_SYSFW_BRDCFG)
	./scripts/gen_x509_combined_cert.sh -b $(SBL) -l $(SBL_LOADADDDR) -s $(SYSFW_PATH) -m $(LOADADDR) -c "$(SYSFW_HS_INNER_CERT_PATH)" -d $(COMBINED_SYSFW_BRDCFG) -n $(COMBINED_SYSFW_BRDCFG_LOADADDR) -k $(KEY) -r $(SW_REV) -o $@
else
$(TIBOOT3): $(SBL) $(SYSFW_PATH) $(SYSFW_HS_INNER_CERT_PATH) $(COMBINED_TIFS_BRDCFG) $(COMBINED_DM_BRDCFG)
	./scripts/gen_x509_combined_cert.sh -b $(SBL) -l $(SBL_LOADADDDR) -s $(SYSFW_PATH) -m $(LOADADDR) -c "$(SYSFW_HS_INNER_CERT_PATH)" -d $(COMBINED_TIFS_BRDCFG) -n $(COMBINED_TIFS_BRDCFG_LOADADDR) -t $(COMBINED_DM_BRDCFG) -y $(COMBINED_DM_BRDCFG_LOADADDR) -k $(KEY) -r $(SW_REV) -o $@
endif

tiboot3.bin: $(TIBOOT3)
	@ln -sf $< $@

$(soc_objroot)/%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c -o $@-pre-validated $<
	python3 ./scripts/sysfw_boardcfg_validator.py -b $@-pre-validated -i -o $@ -s $(BASE_SOC) -l $@.log

%.bin-signed: %.bin
	$(TI_SECURE_DEV_PKG)/scripts/secure-binary-image.sh $< $@

%.bin: %.o
	$(CROSS_COMPILE)objcopy -S -O binary $< $@

.PHONY: sysfw_version
sysfw_version: $(SYSFW_PATH)
	@echo "SYSFW Version:" `strings $(SYSFW_PATH) | grep -o '[0-9]\.[0-9]\.[0-9].*(.*'`

.PHONY: clean
clean:
	-rm -f $(SOC_BINS)
	-rm -f $(ITB) sysfw.itb
	-rm -f $(ITS)
	-rm -f $(TIBOOT3) tiboot3.bin
	-rm -f $(SYSFW_HS_CERTS_PATH)
	-rm -rf $(objroot)

.PHONY: mrproper
mrproper: clean
	-rm -f ti-$(SCIFS)-firmware-$(SOC)-$(SOC_TYPE).bin
	-rm -f ti-$(SCIFS)-firmware-$(SOC)-$(SOC_TYPE)-enc.bin
	-rm -f ti-$(SCIFS)-firmware-$(SOC)-$(SOC_TYPE)-cert.bin
