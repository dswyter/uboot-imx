/*
 * Copyright 2021 NXP
 * Copyright 2021 Variscite Ltd.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX8MP_VAR_DART_ANDROID_H
#define __MX8MP_VAR_DART_ANDROID_H

#define CONFIG_CMD_READ

#define FSL_FASTBOOT_FB_DEV "mmc"

#ifdef CONFIG_SYS_MALLOC_LEN
#undef CONFIG_SYS_MALLOC_LEN
#define CONFIG_SYS_MALLOC_LEN           (32 * SZ_1M)
#endif

#define CONFIG_SERIAL_TAG

#undef CONFIG_EXTRA_ENV_SETTINGS
#undef CONFIG_BOOTCOMMAND

#define CONFIG_EXTRA_ENV_SETTINGS		\
	"splashpos=m,m\0"			\
	"fdt_high=0xffffffffffffffff\0"		\
	"initrd_high=0xffffffffffffffff\0"	\
	"bootargs=" \
		"init=/init " \
		"consoleblank=0 " \
		"androidboot.hardware=nxp " \
		"cma=960M@0x400M-0x1000M " \
		"loop.max_part=7 " \
		"swiotlb=65536 " \
		"androidboot.vendor.sysrq=1 " \
		"firmware_class.path=/vendor/firmware " \
		"transparent_hugepage=never\0"

/* Enable mcu firmware flash */
#ifdef CONFIG_FLASH_MCUFIRMWARE_SUPPORT
#define ANDROID_MCU_FRIMWARE_DEV_TYPE DEV_MMC
#define ANDROID_MCU_FIRMWARE_START 0x500000
#define ANDROID_MCU_FIRMWARE_SIZE  0x40000
#define ANDROID_MCU_FIRMWARE_HEADER_STACK 0x20020000
#endif

#if !defined(CONFIG_IMX_TRUSTY_OS) || !defined(CONFIG_DUAL_BOOTLOADER)
#undef CONFIG_FSL_CAAM_KB
#endif

#ifdef CONFIG_DUAL_BOOTLOADER
#define CONFIG_SYS_SPL_PTE_RAM_BASE    0x41580000

#ifdef CONFIG_IMX_TRUSTY_OS
#define BOOTLOADER_RBIDX_OFFSET  0x3FE000
#define BOOTLOADER_RBIDX_START   0x3FF000
#define BOOTLOADER_RBIDX_LEN     0x08
#define BOOTLOADER_RBIDX_INITVAL 0
#endif

#endif

#ifdef CONFIG_IMX_TRUSTY_OS
#define AVB_RPMB
#define KEYSLOT_HWPARTITION_ID 2
#define KEYSLOT_BLKS             0x1FFF
#define NS_ARCH_ARM64 1

#ifdef CONFIG_ID_ATTESTATION
#define ATTESTATION_ID_BRAND "Android"
#define ATTESTATION_ID_DEVICE "dart_8mp"
#define ATTESTATION_ID_MANUFACTURER "Variscite"
#define ATTESTATION_ID_MODEL "EVK_8MP"
#ifdef CONFIG_ATTESTATION_ID_PRODUCT
#undef CONFIG_ATTESTATION_ID_PRODUCT
#endif
#define CONFIG_ATTESTATION_ID_PRODUCT "dart_8mp"
#endif

#endif

#endif /* __MX8MP_VAR_DART_ANDROID_H */
