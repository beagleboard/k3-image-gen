System Firmware (SYSFW) and Configuration Image Generator for AM65x
===================================================================

Overview
--------
This tool is intended to be a simple solution to allow users to create an image
tree blob (a.k.a. FIT image) comprising a signed System Firmware image as well
as the binary configuration artifacts needed to bring up SYSFW as part of the
U-Boot SPL startup. Note that the final SYSFW configuration itself is expected
to be performed by the end user by directly modifying different C source files
included into this project as needed for an application and board-specific use
case. The domain-specific configuration artifacts to be tailored are:

* *board-cfg.c* contains the general board configuration
* *pm-cfg.c* contains the power management / clock related configuration
* *rm-cfg.c* contains the resource management / allocation related configuration
* *sec-cfg.c* contains the security configuration

The build process consumes a raw (unsigned) SYSFW binary image as released by
the SYSFW development team and signs it by adding an X.509 certificate using a
random key.

The signed SYSFW image as well as the configuration artifacts will then all get
build into an ITB blob (FIT image) named **sysfw.itb** ready for consumption by
U-Boot SPL.


Building SYSFW Image and Configuration Data
-------------------------------------------
First, ensure you have a current mkimage tool and ARMv7 cross toolchain
installed. The SYSFW configuration generator was developed and tested using...

    $ mkimage -V
    mkimage version 2013.10

    $ arm-linux-gnueabihf-gcc --version
    arm-linux-gnueabihf-gcc (Linaro GCC 7.2-2017.11) 7.2.1 20171011
    Copyright (C) 2017 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Also make sure to have a proper unsigned SYSFW image populated at the root of
this project, otherwise a version specified in the Makefile via Git commit hash
will be downloaded from the TI SYSFW release URL (see download location below).

The default SYSFW image consumed by the build process is called
**ti-sci-firmware-am65x-gp.bin** however this may be overwritten and customized
using the **SYSFW_PATH** make variable. The build process will fail if the
image can't be downloaded or no such file is provided.

Further note by default the SYSFW image for use with general purpose (GP) devices
(as opposed to high security devices) is signed with the TI degenerate key to
optimize boot time (less processing time needed by ROM) but can also be signed
with a random cryptoraphic key or another user-provided key. This signing behavior
is controlled through the **KEY** make variable. Not explicitly setting **KEY**
will result in the use of the TI degenerate key. To use a custom key populate the
**KEY** variable to point to the key to get used. By clearing the default key
setting by passing in **KEY=""** a random key will get generated and used during
the build process.

In order to download the SYSFW release image (if needed) and build the final
**sysfw.itb** for consumption by U-Boot simply perform a make...

    $ make

To extract and show the release version of the SYSFW image being used...

    $ make sysfw_version
    SYSFW Version: v2018.08a (Curious Crow)

The workspace can be cleaned up by doing...

    $ make clean

To also remove the SYSFW image do this...

    $ make mrproper

Building SYSFW Image for High-Security(HS) devices
--------------------------------------------------
The process for building and image suitable for use with HS devices is similar
to the above process with the following differences:

The make commands should be appended with HS=1,

    $ make HS=1

The environment variable **TI_SECURE_DEV_PKG** should be defined to point to
the TI Secure Development Tools package.

There are two images downloaded and consumed by the build process.

    * ti-sci-firmware-am65x-hs-enc.bin: Encrypted HS SYSFW image
    * ti-sci-firmware-am65x-hs-cert.bin: Inner-certificate for HS SYSFW image

The inner-certificate is signed by the key provided by the **TI_SECURE_DEV_PKG**
path producing an outer-certificate. These images are then appended to produce
the final **sysfw.bin** which is bundled with the configuration data exactly as
the non-HS version above.

Important Notes
---------------
There is a strong dependency of the used System Firmware release version and
how the board configuration data needs to be structured and/or filled in. Using
config data that is not compatible with a given SYSFW release may lead to
failures during loading of the data by U-Boot SPL, or failures later downstream
in U-Boot or during Linux boot.

It is strongly recommended to review System Firmware release documentation in
great detail(!) to make sure suitable board configuration is provided. Common
pitfalls preventing proper system operation include but are not limited to using
an unsuitable or invalid resource management configuration.


References
----------
* [Latest SYSFW Release Documentation](http://software-dl.ti.com/tisci/esd/latest/)
* [Official SYSFW Release Download Location](https://git.ti.com/processor-firmware/ti-linux-firmware/trees/ti-linux-firmware-4.1.y/ti-sysfw)
