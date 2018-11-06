#
# Utility to generate an image tree blob (ITB) comprising a signed System
# Firmware (SYSFW) binary image as released by TI as well as domain-specific
# SYSFW configuration fragments provided in the form of C sources.
#
# Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

# If using the default SYSFW make sure to manually copy/populate the unsigned
# image into the root folder of this repository.
SYSFW_PATH ?= ti-sci-firmware-am65x-gp.bin

# Must use FULL Git hash below, as it is used as part of an URL for direct DL
SYSFW_GIT_HASH ?= cbb37f282017cb5b6bf42c26c0b5a5a8b818ec9e

# URL to download SYSFW release binary from if not provided otherwise
SYSFW_DL_URL ?= https://git.ti.com/processor-firmware/ti-linux-firmware/blobs/raw/$(SYSFW_GIT_HASH)/ti-sysfw/$(SYSFW_PATH)

CROSS_COMPILE ?= arm-linux-gnueabihf-

CFLAGS ?= \
	-fno-builtin \
	-Wall

BINS ?= \
	sysfw.bin \
	board-cfg.bin \
	pm-cfg.bin \
	rm-cfg.bin \
	sec-cfg.bin

ITB ?= sysfw.itb
ITS ?= $(basename $(ITB)).its

MKIMAGE ?= mkimage

.PHONY: all
all: $(ITB)

%.o: %.S
	$(CROSS_COMPILE)as -o $@ $<

%.o: %.c
	$(CROSS_COMPILE)gcc $(CFLAGS) -c -o $@ $<

%.bin: %.o
	$(CROSS_COMPILE)objcopy -S -O binary $< $@

$(SYSFW_PATH):
	@echo "Downloading SYSFW release image..."
	wget $(SYSFW_DL_URL)
	@echo "Download SUCCESS!"

sysfw.bin: $(SYSFW_PATH) sysfw_version
	@echo "Signing the SYSFW release image with random key..."
	./gen_x509_cert.sh -c m3 -b $< -o $@ -l 0x40000

$(ITS): $(BINS)
	./gen_its.sh $(BINS) > $@

$(ITB): $(ITS) $(BINS)
	$(MKIMAGE) -f $< -r $@

.PHONY: sysfw_version
sysfw_version: $(SYSFW_PATH)
	@echo "SYSFW Version:" `strings $(SYSFW_PATH) | grep -o 'v20[0-9][0-9]\.[0-9][0-9].*(.*'`

.PHONY: clean
clean:
	-rm $(BINS)
	-rm $(ITB)
	-rm $(ITS)

.PHONY: mrproper
mrproper: clean
	-rm $(SYSFW_PATH)
