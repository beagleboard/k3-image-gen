/*
 * K3 System Firmware Resource Management Configuration Data
 * Auto generated from K3 Resource Partitioning tool
 *
 * Copyright (C) 2019-2021 Texas Instruments Incorporated - https://www.ti.com/
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

const struct boardcfg_rm_local am65x_boardcfg_rm_data = {
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
			.host_cfg_entries = {
				{
					.host_id = HOST_ID_R5_0,
					.allowed_atype = 0b101010,
					.allowed_qos = 0xAAAA,
					.allowed_orderid = 0xAAAAAAAA,
					.allowed_priority = 0xAAAA,
					.allowed_sched_priority = 0xAA,
				},
				{
					.host_id = HOST_ID_R5_2,
					.allowed_atype = 0b101010,
					.allowed_qos = 0xAAAA,
					.allowed_orderid = 0xAAAAAAAA,
					.allowed_priority = 0xAAAA,
					.allowed_sched_priority = 0xAA,
				},
				{
					.host_id = HOST_ID_A53_2,
					.allowed_atype = 0b101010,
					.allowed_qos = 0xAAAA,
					.allowed_orderid = 0xAAAAAAAA,
					.allowed_priority = 0xAAAA,
					.allowed_sched_priority = 0xAA,
				},
				{
					.host_id = HOST_ID_A53_3,
					.allowed_atype = 0b101010,
					.allowed_qos = 0xAAAA,
					.allowed_orderid = 0xAAAAAAAA,
					.allowed_priority = 0xAAAA,
					.allowed_sched_priority = 0xAA,
				},
			}
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
		/* Compare event Interrupt router */
		{
			.start_resource = 0,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_CMPEVENT_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 12,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_CMPEVENT_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 16,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_CMPEVENT_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 24,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_CMPEVENT_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		/* Main 2 MCU Level Interrupt Router */
		{
			.start_resource = 0,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_MAIN2MCU_LVL_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 32,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_MAIN2MCU_LVL_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		/* Main 2 MCU Pulse Interrupt Router */
		{
			.start_resource = 0,
			.num_resource = 24,
			.type = RESASG_UTYPE (AM6_DEV_MAIN2MCU_PLS_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 24,
			.num_resource = 24,
			.type = RESASG_UTYPE (AM6_DEV_MAIN2MCU_PLS_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		/* Main GPIO Interrupt Router */
		{
			.start_resource = 0,
			.num_resource = 20,
			.type = RESASG_UTYPE (AM6_DEV_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 20,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 24,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 28,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		/* Timesync Interrupt router */
		{
			.start_resource = 0,
			.num_resource = 16,
			.type = RESASG_UTYPE (AM6_DEV_TIMESYNC_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 16,
			.num_resource = 16,
			.type = RESASG_UTYPE (AM6_DEV_TIMESYNC_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 32,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_TIMESYNC_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_ALL,
		},
		/* Wakeup GPIO Interrupt router */
		{
			.start_resource = 0,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_WKUP_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 4,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_WKUP_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 8,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_WKUP_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 12,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_WKUP_GPIOMUX_INTRTR0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		/* Main NAVSS UDMA Interrupt aggregator Virtual interrupts */
		{
			.start_resource = 16,
			.num_resource = 80,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 96,
			.num_resource = 30,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 126,
			.num_resource = 50,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 176,
			.num_resource = 50,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 226,
			.num_resource = 30,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA Interrupt aggregator Global events */
		{
			.start_resource = 16,
			.num_resource = 1024,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 1040,
			.num_resource = 512,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 1552,
			.num_resource = 512,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 2064,
			.num_resource = 512,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 2576,
			.num_resource = 2032,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMASS_INTA0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_ALL,
		},
		/* MODSS Interrupt aggregator0 Virtual interrupts */
		{
			.start_resource = 0,
			.num_resource = 64,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_MODSS_INTA0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_ALL,
		},
		/* MODSS Interrupt aggregator0 Global events */
		{
			.start_resource = 20480,
			.num_resource = 1024,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_MODSS_INTA0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_ALL,
		},
		/* MODSS Interrupt aggregator1 Virtual interrupts */
		{
			.start_resource = 0,
			.num_resource = 64,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_MODSS_INTA1,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_ALL,
		},
		/* MODSS Interrupt aggregator1 Global events */
		{
			.start_resource = 22528,
			.num_resource = 1024,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_MODSS_INTA1,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS Interrupt Router */
		{
			.start_resource = 16,
			.num_resource = 64,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_INTR_ROUTER_0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 80,
			.num_resource = 40,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_INTR_ROUTER_0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 120,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_INTR_ROUTER_0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 124,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_INTR_ROUTER_0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 128,
			.num_resource = 24,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_INTR_ROUTER_0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS Non secure proxies */
		{
			.start_resource = 1,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 13,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 17,
			.num_resource = 16,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 33,
			.num_resource = 16,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 49,
			.num_resource = 15,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS Ring accelerator Error event config */
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_ERROR_OES),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS Ring accelerator Free rings */
		{
			.start_resource = 304,
			.num_resource = 100,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 404,
			.num_resource = 50,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 454,
			.num_resource = 256,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 710,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 742,
			.num_resource = 26,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS Rings for Normal capacity Rx channels */
		{
			.start_resource = 160,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 172,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 172,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 176,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 178,
			.num_resource = 52,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 230,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 238,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 270,
			.num_resource = 14,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 284,
			.num_resource = 18,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS Rings for Normal capacity Tx channels */
		{
			.start_resource = 8,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 20,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 20,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 24,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 26,
			.num_resource = 38,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 64,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 72,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 104,
			.num_resource = 14,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 118,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS Rings for extended Tx channels */
		{
			.start_resource = 120,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 124,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 128,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 140,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_EXT),
			.host_id = HOST_ID_R5_2,
		},
		/* Main NAVSS Rings for High capacity Rx channels */
		{
			.start_resource = 154,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 154,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 154,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 154,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 156,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 158,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_R5_2,
		},
		/* Main NAVSS Rings for High capacity Tx channels */
		{
			.start_resource = 1,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 1,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 1,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 1,
			.num_resource = 3,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 4,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 6,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_R5_2,
		},
		/* Main NAVSS Ring accelerator virt_id range */
		{
			.start_resource = 2,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_VIRTID),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 3,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_VIRTID),
			.host_id = HOST_ID_A53_3,
		},
		/* Main NAVSS Ring monitors */
		{
			.start_resource = 0,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 8,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 12,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 20,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 28,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA Rx Free flows */
		{
			.start_resource = 150,
			.num_resource = 64,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 214,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 222,
			.num_resource = 64,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 286,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 294,
			.num_resource = 6,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA invalid flow event config */
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_INVALID_FLOW_OES),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA global event trigger */
		{
			.start_resource = 49152,
			.num_resource = 1024,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA global config */
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_GLOBAL_CONFIG),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA Normal capacity Rx channels */
		{
			.start_resource = 8,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 20,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 20,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 24,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 26,
			.num_resource = 52,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 78,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 86,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 118,
			.num_resource = 14,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 132,
			.num_resource = 18,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA High capacity Rx channels */
		{
			.start_resource = 2,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 2,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 2,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 2,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 4,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 6,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_R5_2,
		},
		/* Main NAVSS UDMA Normal capacity Tx channels */
		{
			.start_resource = 8,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 20,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 20,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 24,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 26,
			.num_resource = 38,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 64,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 72,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 104,
			.num_resource = 14,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 118,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_ALL,
		},
		/* Main NAVSS UDMA extended Tx channels */
		{
			.start_resource = 120,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 124,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 128,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 140,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_ECHAN),
			.host_id = HOST_ID_R5_2,
		},
		/* Main NAVSS UDMA High capacity Tx channels */
		{
			.start_resource = 1,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 1,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 1,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 1,
			.num_resource = 3,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 4,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 6,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS Interrupt aggregator Virtual interrupts */
		{
			.start_resource = 8,
			.num_resource = 80,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 88,
			.num_resource = 30,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 118,
			.num_resource = 50,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 168,
			.num_resource = 50,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 218,
			.num_resource = 38,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_IA_VINT),
			.host_id = HOST_ID_ALL,
		},
		/* MCU NAVSS Interrupt aggregator Global events */
		{
			.start_resource = 16392,
			.num_resource = 512,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 16904,
			.num_resource = 128,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 17032,
			.num_resource = 256,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 17288,
			.num_resource = 256,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 17544,
			.num_resource = 376,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_AGGR_0,
					RESASG_SUBTYPE_GLOBAL_EVENT_SEVT),
			.host_id = HOST_ID_ALL,
		},
		/* MCU NAVSS Interrupt router */
		{
			.start_resource = 4,
			.num_resource = 28,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_ROUTER_0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 36,
			.num_resource = 28,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_INTR_ROUTER_0,
					RESASG_SUBTYPE_IR_OUTPUT),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS Non secure proxies */
		{
			.start_resource = 0,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 12,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 16,
			.num_resource = 24,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 40,
			.num_resource = 24,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_PROXY0,
					RESASG_SUBTYPE_PROXY_PROXIES),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS UDMA Rx free flows */
		{
			.start_resource = 48,
			.num_resource = 16,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 64,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 68,
			.num_resource = 16,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 84,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 92,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON),
			.host_id = HOST_ID_ALL,
		},
		/* MCU NAVSS invalid flow event config */
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_INVALID_FLOW_OES),
			.host_id = HOST_ID_ALL,
		},
		/* MCU NAVSS UDMA global event trigger */
		{
			.start_resource = 56320,
			.num_resource = 256,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER),
			.host_id = HOST_ID_ALL,
		},
		/* MCU NAVSS UDMA global config */
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_GLOBAL_CONFIG),
			.host_id = HOST_ID_ALL,
		},
		/* MCU NAVSS UDMA Normal capacity Rx channels */
		{
			.start_resource = 2,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 4,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 4,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 8,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 10,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 22,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 26,
			.num_resource = 10,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 36,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS UDMA High capacity Rx channels */
		{
			.start_resource = 0,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_RX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		/* MCU NAVSS UDMA Normal capacity Tx channels */
		{
			.start_resource = 2,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 4,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 4,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 8,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 10,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 22,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 26,
			.num_resource = 10,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 36,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_CHAN),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS UDMA High capacity Tx channels */
		{
			.start_resource = 0,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_UDMAP0,
					RESASG_SUBTYPE_UDMAP_TX_HCHAN),
			.host_id = HOST_ID_R5_0,
		},
		/* MCU NAVSS Ring accelerator error event config */
		{
			.start_resource = 0,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_ERROR_OES),
			.host_id = HOST_ID_ALL,
		},
		/* MCU NAVSS Ring accelerator Free rings */
		{
			.start_resource = 96,
			.num_resource = 32,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 128,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 136,
			.num_resource = 60,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 196,
			.num_resource = 60,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_GP),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS Rings for Normal capacity Rx channels */
		{
			.start_resource = 50,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 52,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 52,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 56,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 58,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 70,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 74,
			.num_resource = 10,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 84,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS Rings for Normal capacity Tx channels */
		{
			.start_resource = 2,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 4,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 4,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 8,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 10,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 22,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 26,
			.num_resource = 10,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 36,
			.num_resource = 12,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX),
			.host_id = HOST_ID_R5_2,
		},
		/* MCU NAVSS Rings for High capacity Rx channels */
		{
			.start_resource = 48,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 48,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_RX_H),
			.host_id = HOST_ID_R5_0,
		},
		/* MCU NAVSS Rings for High capacity Tx channels */
		{
			.start_resource = 0,
			.num_resource = 0,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 0,
			.num_resource = 2,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_UDMAP_TX_H),
			.host_id = HOST_ID_R5_0,
		},
		/* MCU NAVSS Ring accelerator virt_id range */
		{
			.start_resource = 2,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_VIRTID),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 3,
			.num_resource = 1,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_VIRTID),
			.host_id = HOST_ID_A53_3,
		},
		/* MCU NAVSS Ring monitors */
		{
			.start_resource = 0,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_A53_2,
		},
		{
			.start_resource = 8,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_A53_3,
		},
		{
			.start_resource = 12,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_R5_0,
		},
		{
			.start_resource = 20,
			.num_resource = 8,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_R5_2,
		},
		{
			.start_resource = 28,
			.num_resource = 4,
			.type = RESASG_UTYPE (AM6_DEV_MCU_NAVSS0_RINGACC0,
					RESASG_SUBTYPE_RA_MONITORS),
			.host_id = HOST_ID_ALL,
		},
	},
};
