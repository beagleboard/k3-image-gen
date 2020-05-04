/*
 * K3 System Firmware Resource Management Configuration Data
 *
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
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

const struct boardcfg_rm_local am65_boardcfg_rm_data = {
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
				.size = sizeof(struct boardcfg_rm_host_cfg),
			},
			.host_cfg_entries = {{ 0 } },
		},

		/* boardcfg_rm_resasg */
		.resasg = {
			.subhdr = {
				.magic = BOARDCFG_RM_RESASG_MAGIC_NUM,
				.size = sizeof(struct boardcfg_rm_resasg),
			},
			.resasg_entries_size = BOARDCFG_RM_RESASG_ENTRIES *
					sizeof(struct boardcfg_rm_resasg_entry),
			.reserved = 0,
			/* .resasg_entries is set via boardcfg_rm_local */
		},
	},

	/* This is actually part of .resasg */
	.resasg_entries = {
		{
			.start_resource = 16,
			.num_resource = 240,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMASS_INTA0,
				       RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 16,
			.num_resource = 4592,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMASS_INTA0,
				       RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 0,
			.num_resource = 64,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_MODSS_INTA0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 20480,
			.num_resource = 1024,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_MODSS_INTA0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 0,
			.num_resource = 64,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_MODSS_INTA1,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 22528,
			.num_resource = 1024,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_MODSS_INTA1,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 8,
			.num_resource = 248,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 16392,
			.num_resource = 992,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 17384,
			.num_resource = 536,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 49152,
			.num_resource = 1024,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
					 RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 1,
			.num_resource = 7,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 8,
			.num_resource = 112,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
					 RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 120,
			.num_resource = 32,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 2,
			.num_resource = 6,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 8,
			.num_resource = 142,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
					 RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 150,
			.num_resource = 150,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
				  RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_UDMAP0,
				RESASG_SUBTYPE_UDMAP_INVALID_FLOW_OES),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 56320,
			.num_resource = 256,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
					  RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
					 RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 2,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
					  RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
					 RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 2,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
					  RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 48,
			.num_resource = 48,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
				   RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 2,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
					  RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_1,
		},
		{
			.start_resource = 2,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
					  RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_1,
		},
		{
			.start_resource = 48,
			.num_resource = 48,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
				   RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_R5_1,
		},
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_UDMAP0,
				 RESASG_SUBTYPE_UDMAP_INVALID_FLOW_OES),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 1,
			.num_resource = 7,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_RINGACC0,
				      RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 8,
			.num_resource = 112,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_RINGACC0,
				      RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 153,
			.num_resource = 7,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_RINGACC0,
				      RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 160,
			.num_resource = 142,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_RINGACC0,
				      RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 304,
			.num_resource = 464,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_RINGACC0,
					    RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_RINGACC0,
					  RESASG_SUBTYPE_RA_ERROR_OES),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
				       RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 2,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
				       RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 48,
			.num_resource = 2,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
				       RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 50,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
				       RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 96,
			.num_resource = 160,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
					     RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 2,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
				       RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_1,
		},
		{
			.start_resource = 50,
			.num_resource = 46,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
				       RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_1,
		},
		{
			.start_resource = 96,
			.num_resource = 160,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
					     RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_R5_1,
		},
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_RINGACC0,
					   RESASG_SUBTYPE_RA_ERROR_OES),
			.host_id = HOST_ID_A53_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_CMPEVENT_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 0,
			.num_resource = 32,
			.host_id = HOST_ID_A53_2,
		},
		/* Main 2 MCU level IRQ IR */
		{
			.type = RESASG_UTYPE(AM6_DEV_MAIN2MCU_LVL_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 0,
			.num_resource = 32,
			.host_id = HOST_ID_R5_0,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_MAIN2MCU_LVL_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 32,
			.num_resource = 32,
			.host_id = HOST_ID_R5_2,
		},
		/* Main 2 MCU Pulse IRQ IR */
		{
			.type = RESASG_UTYPE(AM6_DEV_MAIN2MCU_PLS_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 0,
			.num_resource = 24,
			.host_id = HOST_ID_R5_0,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_MAIN2MCU_PLS_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 24,
			.num_resource = 24,
			.host_id = HOST_ID_R5_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_GPIOMUX_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 0,
			.num_resource = 32,
			.host_id = HOST_ID_A53_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_TIMESYNC_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 0,
			.num_resource = 40,
			.host_id = HOST_ID_A53_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_WKUP_GPIOMUX_INTRTR0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 0,
			.num_resource = 16,
			.host_id = HOST_ID_A53_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_INTR_ROUTER_0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 16,
			.num_resource = 104,
			.host_id = HOST_ID_A53_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_INTR_ROUTER_0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 120,
			.num_resource = 4,
			.host_id = HOST_ID_R5_0,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_INTR_ROUTER_0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 124,
			.num_resource = 4,
			.host_id = HOST_ID_R5_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_INTR_ROUTER_0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 128,
			.num_resource = 8,
			.host_id = HOST_ID_ICSSG_0,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_INTR_ROUTER_0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 136,
			.num_resource = 8,
			.host_id = HOST_ID_ICSSG_1,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_NAVSS0_INTR_ROUTER_0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 144,
			.num_resource = 8,
			.host_id = HOST_ID_ICSSG_2,
		},
		{
			.type = RESASG_UTYPE(AM6_DEV_MCU_NAVSS0_INTR_ROUTER_0, RESASG_SUBTYPE_IR_OUTPUT),
			.start_resource = 4,
			.num_resource = 28,
			.host_id = HOST_ID_R5_0,
		},
	},
};
