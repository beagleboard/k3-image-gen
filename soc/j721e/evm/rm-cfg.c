/*
 * K3 System Firmware Resource Management Configuration Data
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *	Andreas Dannenberg <dannenberg@ti.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "common.h"
#include <hosts.h>
#include <devices.h>
#include <resasg_types.h>

const struct boardcfg_rm_local j721e_boardcfg_rm_data = {
	.rm_boardcfg = {
		/* boardcfg_abi_rev */
		.rev = {
			.boardcfg_abi_maj = 0x0,
			.boardcfg_abi_min = 0x1,
		},

		/* boardcfg_rm_host_cfg */
		.host_cfg = {
			.subhdr = {
				.magic = BOARDCFG_RM_HOST_CFG_MAGIC_NUM,
				.size = sizeof (struct boardcfg_rm_host_cfg),
			},
			.host_cfg_entries = {{0}},
		},

		/* boardcfg_rm_resasg */
		.resasg = {
			.subhdr = {
				.magic = BOARDCFG_RM_RESASG_MAGIC_NUM,
				.size = sizeof (struct boardcfg_rm_resasg),
			},
			.resasg_entries_size =
				BOARDCFG_RM_RESASG_ENTRIES *
				sizeof (struct boardcfg_rm_resasg_entry),
			.reserved = 0,
			/* .resasg_entries is set via boardcfg_rm_local */
		},
	},

	/* This is actually part of .resasg */
	.resasg_entries = {

		/* GIC/CLEC slot assignment for NAVSS INTR */
		{
			.start_resource = 392,
			.num_resource = 56,
			.type = RESASG_UTYPE (J721E_DEV_COMPUTE_CLUSTER0_GIC500SS,
					RESASG_SUBTYPE_COMPUTE_CLUSTER0_GIC500SS_SPI_IRQ_GROUP0_FROM_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 960,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_COMPUTE_CLUSTER0_GIC500SS,
					RESASG_SUBTYPE_COMPUTE_CLUSTER0_GIC500SS_SPI_IRQ_GROUP0_FROM_WKUP_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 74,
			.num_resource = 54,
			.type = RESASG_UTYPE (J721E_DEV_COMPUTE_CLUSTER0_GIC500SS,
					RESASG_SUBTYPE_COMPUTE_CLUSTER0_GIC500SS_SPI_IRQ_GROUP0_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 448,
			.num_resource = 64,
			.type = RESASG_UTYPE (J721E_DEV_COMPUTE_CLUSTER0_GIC500SS,
					RESASG_SUBTYPE_COMPUTE_CLUSTER0_GIC500SS_SPI_IRQ_GROUP1_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 672,
			.num_resource = 44,
			.type = RESASG_UTYPE (J721E_DEV_COMPUTE_CLUSTER0_GIC500SS,
					RESASG_SUBTYPE_COMPUTE_CLUSTER0_GIC500SS_SPI_IRQ_GROUP2_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 716,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_COMPUTE_CLUSTER0_CLEC,
					RESASG_SUBTYPE_COMPUTE_CLUSTER0_GIC500SS_SPI_IRQ_GROUP2_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_C7X_1,
		},

		/* MCU_0_R5_0 CPU INTR */
		{
			.start_resource = 68U,
			.num_resource = 28U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE0,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_MCU_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 124U,
			.num_resource = 16U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE0,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_WKUP_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 160U,
			.num_resource = 64U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE0,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_MAIN2MCU_LVL_INTRTR0),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 224U,
			.num_resource = 48U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE0,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_MAIN2MCU_PLS_INTRTR0),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 376U,
			.num_resource = 8U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE0,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MCU_0_R5_0,
		},

		/* MCU_0_R5_2 CPU INTR */
		{
			.start_resource = 68U,
			.num_resource = 28U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE1,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_MCU_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 124U,
			.num_resource = 16U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE1,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_WKUP_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 160U,
			.num_resource = 64U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE1,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_MAIN2MCU_LVL_INTRTR0),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 224U,
			.num_resource = 48U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE1,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_MAIN2MCU_PLS_INTRTR0),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 376U,
			.num_resource = 8U,
			.type = RESASG_UTYPE(J721E_DEV_MCU_R5FSS0_CORE1,
					RESASG_SUBTYPE_MCU_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MCU_0_R5_2,
		},

		/* MAIN_0_R5_0 CPU INTR */
		{
			.start_resource = 176U,
			.num_resource = 16U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS0_CORE0,
					RESASG_SUBTYPE_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 228U,
			.num_resource = 28U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS0_CORE0,
					RESASG_SUBTYPE_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 256U,
			.num_resource = 256U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS0_CORE0,
					RESASG_SUBTYPE_R5FSS0_CORE0_INTR_IRQ_GROUP0_FROM_R5FSS0_INTROUTER0),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},

		/* MAIN_0_R5_2 CPU INTR */
		{
			.start_resource = 176U,
			.num_resource = 16U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS0_CORE1,
					RESASG_SUBTYPE_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 228U,
			.num_resource = 28U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS0_CORE1,
					RESASG_SUBTYPE_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 256U,
			.num_resource = 256U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS0_CORE1,
					RESASG_SUBTYPE_R5FSS0_CORE1_INTR_IRQ_GROUP0_FROM_R5FSS0_INTROUTER0),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* MAIN_1_R5_0 CPU INTR */
		{
			.start_resource = 176U,
			.num_resource = 16U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS1_CORE0,
					RESASG_SUBTYPE_R5FSS1_CORE0_INTR_IRQ_GROUP0_FROM_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 228U,
			.num_resource = 28U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS1_CORE0,
					RESASG_SUBTYPE_R5FSS1_CORE0_INTR_IRQ_GROUP0_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 256U,
			.num_resource = 256U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS1_CORE0,
					RESASG_SUBTYPE_R5FSS1_CORE0_INTR_IRQ_GROUP0_FROM_R5FSS1_INTROUTER0),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},

		/* MAIN_1_R5_2 CPU INTR */
		{
			.start_resource = 176U,
			.num_resource = 16U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS1_CORE1,
					RESASG_SUBTYPE_R5FSS1_CORE1_INTR_IRQ_GROUP0_FROM_GPIOMUX_INTRTR0),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 228U,
			.num_resource = 28U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS1_CORE1,
					RESASG_SUBTYPE_R5FSS1_CORE1_INTR_IRQ_GROUP0_FROM_NAVSS0_INTR_ROUTER_0),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 256U,
			.num_resource = 256U,
			.type = RESASG_UTYPE(J721E_DEV_R5FSS1_CORE1,
					RESASG_SUBTYPE_R5FSS1_CORE1_INTR_IRQ_GROUP0_FROM_R5FSS1_INTROUTER0),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},

		/* C6X_0_1 CPU INTR */
		{
			.start_resource = 8U,
			.num_resource = 1U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS0_CORE0,
					RESASG_SUBTYPE_C66SS0_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP0_FROM_C66SS0_INTROUTER0),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 15U,
			.num_resource = 81U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS0_CORE0,
					RESASG_SUBTYPE_C66SS0_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP1_FROM_C66SS0_INTROUTER0),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 99U,
			.num_resource = 1U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS0_CORE0,
					RESASG_SUBTYPE_C66SS0_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP2_FROM_C66SS0_INTROUTER0),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 102U,
			.num_resource = 8U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS0_CORE0,
					RESASG_SUBTYPE_C66SS0_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP3_FROM_C66SS0_INTROUTER0),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 114U,
			.num_resource = 2U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS0_CORE0,
					RESASG_SUBTYPE_C66SS0_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP4_FROM_C66SS0_INTROUTER0),
			.host_id = HOST_ID_C6X_0_1,
		},

		/* C6X_1_1 CPU INTR */
		{
			.start_resource = 8U,
			.num_resource = 1U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS1_CORE0,
					RESASG_SUBTYPE_C66SS1_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP0_FROM_C66SS1_INTROUTER0),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 15U,
			.num_resource = 81U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS1_CORE0,
					RESASG_SUBTYPE_C66SS1_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP1_FROM_C66SS1_INTROUTER0),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 99U,
			.num_resource = 1U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS1_CORE0,
					RESASG_SUBTYPE_C66SS1_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP2_FROM_C66SS1_INTROUTER0),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 102U,
			.num_resource = 8U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS1_CORE0,
					RESASG_SUBTYPE_C66SS1_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP3_FROM_C66SS1_INTROUTER0),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 114U,
			.num_resource = 2U,
			.type = RESASG_UTYPE(J721E_DEV_C66SS1_CORE0,
					RESASG_SUBTYPE_C66SS1_CORE0_C66_EVENT_IN_SYNC_IRQ_GROUP4_FROM_C66SS1_INTROUTER0),
			.host_id = HOST_ID_C6X_1_1,
		},

		/* AUTO GENERATED ENTRIES BELOW */

		/* Main Nav UHC TX Channel */
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_UHCHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 2,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_UHCHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav UHC RX Channel */
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_UHCHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 2,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_UHCHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav HC TX Channel */
		{
			.start_resource = 4,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 8,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 10,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 14,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav HC RX Channel */
		{
			.start_resource = 4,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 8,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 10,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 14,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav Total TX Channel */
		{
			.start_resource = 16,
			.num_resource = 36,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 52,
			.num_resource = 20,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 72,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 74,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 76,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 82,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 88,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 94,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 110,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 118,
			.num_resource = 7,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 125,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 133,
			.num_resource = 7,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav Total RX Channel */
		{
			.start_resource = 16,
			.num_resource = 36,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 52,
			.num_resource = 20,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 72,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 74,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 76,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 82,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 88,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 94,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 110,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 118,
			.num_resource = 7,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 125,
			.num_resource = 15,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav extended TX channels */
		{
			.start_resource = 140,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 156,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 162,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 168,
			.num_resource = 132,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav UHC TX ring */
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_UH),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 2,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_UH),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav UHC RX ring */
		{
			.start_resource = 300,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX_UH),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 302,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX_UH),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav HC TX ring */
		{
			.start_resource = 4,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 8,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 10,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 14,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav HC RX ring */
		{
			.start_resource = 304,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 308,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 310,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 314,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav TX ring */
		{
			.start_resource = 16,
			.num_resource = 36,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 52,
			.num_resource = 20,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 72,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 74,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 76,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 82,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 88,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 94,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 110,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 118,
			.num_resource = 7,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 125,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 133,
			.num_resource = 7,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav RX ring */
		{
			.start_resource = 316,
			.num_resource = 36,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 352,
			.num_resource = 20,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 372,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 374,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 376,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 382,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 388,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 394,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 410,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 418,
			.num_resource = 7,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 425,
			.num_resource = 15,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav TX Extended rings */
		{
			.start_resource = 140,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 156,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 162,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 168,
			.num_resource = 132,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},

		/* Main Nav Free RX Flow */
		{
			.start_resource = 140,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 156,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 172,
			.num_resource = 64,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 236,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 244,
			.num_resource = 56,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav Free Ring */
		{
			.start_resource = 440,
			.num_resource = 150,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 590,
			.num_resource = 40,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 630,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 636,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 642,
			.num_resource = 10,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 652,
			.num_resource = 10,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 662,
			.num_resource = 32,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 694,
			.num_resource = 38,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 732,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 744,
			.num_resource = 40,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 784,
			.num_resource = 182,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 966,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav IA VINT */
		{
			.start_resource = 38,
			.num_resource = 86,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 124,
			.num_resource = 32,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 156,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 168,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 180,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 192,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 204,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 216,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 224,
			.num_resource = 24,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 248,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_ALL,
		},

		/* Main Nav IA SEVT */
		{
			.start_resource = 38,
			.num_resource = 1024,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 1062,
			.num_resource = 512,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 1574,
			.num_resource = 32,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 1606,
			.num_resource = 32,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 1638,
			.num_resource = 256,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 1894,
			.num_resource = 256,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 2150,
			.num_resource = 256,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 2406,
			.num_resource = 256,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 2662,
			.num_resource = 256,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 2918,
			.num_resource = 256,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 3174,
			.num_resource = 512,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 3686,
			.num_resource = 922,
			.type = RESASG_UTYPE (J721E_DEV_NAVSS0_UDMASS_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav HC TX Channel */
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_MCU_0_R5_0,
		},

		/* MCU Nav HC RX Channel */
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_MCU_0_R5_0,
		},

		/* MCU Nav Total TX Channel */
		{
			.start_resource = 2,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 14,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 20,
			.num_resource = 5,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 25,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_1,
		},
		{
			.start_resource = 25,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 27,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 29,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 31,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 33,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 35,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 37,
			.num_resource = 3,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 40,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 42,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav Total RX Channel */
		{
			.start_resource = 2,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 14,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 20,
			.num_resource = 5,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 25,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_1,
		},
		{
			.start_resource = 25,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 27,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 29,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 31,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 33,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 35,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 37,
			.num_resource = 3,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 40,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 42,
			.num_resource = 3,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav HC Tx ring */
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_MCU_0_R5_0,
		},

		/* MCU Nav HC Rx ring */
		{
			.start_resource = 48,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_MCU_0_R5_0,
		},

		/* MCU Nav Tx ring */
		{
			.start_resource = 2,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 14,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 20,
			.num_resource = 5,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 25,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MCU_0_R5_1,
		},
		{
			.start_resource = 25,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 27,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 29,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 31,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 33,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 35,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 37,
			.num_resource = 3,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 40,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 42,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav Rx ring */
		{
			.start_resource = 50,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 62,
			.num_resource = 6,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 68,
			.num_resource = 5,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 73,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MCU_0_R5_1,
		},
		{
			.start_resource = 73,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 75,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 77,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 79,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 81,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 83,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 85,
			.num_resource = 3,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 88,
			.num_resource = 2,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 90,
			.num_resource = 3,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav Free RX Flow */
		{
			.start_resource = 48,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 56,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 60,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 68,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MCU_0_R5_1,
		},
		{
			.start_resource = 68,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 72,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 76,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 80,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 88,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 92,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_UDMAP_0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav Free Ring */
		{
			.start_resource = 96,
			.num_resource = 20,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 116,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 124,
			.num_resource = 32,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 156,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MCU_0_R5_1,
		},
		{
			.start_resource = 156,
			.num_resource = 12,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 168,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 176,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 184,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 192,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 200,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 208,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 224,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 232,
			.num_resource = 20,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_RINGACC_0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav IA VINT */
		{
			.start_resource = 8,
			.num_resource = 32,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 40,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 56,
			.num_resource = 64,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 120,
			.num_resource = 4,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 124,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 140,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 156,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 164,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 172,
			.num_resource = 8,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 180,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 196,
			.num_resource = 16,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 212,
			.num_resource = 44,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_ALL,
		},

		/* MCU Nav IA SEVT */
		{
			.start_resource = 16392,
			.num_resource = 128,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A72_2,
		},
		{
			.start_resource = 16520,
			.num_resource = 128,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A72_3,
		},
		{
			.start_resource = 16648,
			.num_resource = 256,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MCU_0_R5_0,
		},
		{
			.start_resource = 16904,
			.num_resource = 64,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MCU_0_R5_2,
		},
		{
			.start_resource = 16968,
			.num_resource = 128,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_1_R5_0,
		},
		{
			.start_resource = 17096,
			.num_resource = 128,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_1_R5_2,
		},
		{
			.start_resource = 17224,
			.num_resource = 64,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_C7X_1,
		},
		{
			.start_resource = 17288,
			.num_resource = 64,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_C6X_0_1,
		},
		{
			.start_resource = 17352,
			.num_resource = 64,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_C6X_1_1,
		},
		{
			.start_resource = 17416,
			.num_resource = 128,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_0_R5_0,
		},
		{
			.start_resource = 17544,
			.num_resource = 128,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_MAIN_0_R5_2,
		},
		{
			.start_resource = 17672,
			.num_resource = 248,
			.type = RESASG_UTYPE (J721E_DEV_MCU_NAVSS0_INTAGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_ALL,
		},

	},
};
