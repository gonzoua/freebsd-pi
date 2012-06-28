/*-
 * This file is provided under a dual BSD/GPLv2 license.  When using or
 * redistributing this file, you may do so under either license.
 *
 * GPL LICENSE SUMMARY
 *
 * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 * The full GNU General Public License is included in this distribution
 * in the file called LICENSE.GPL.
 *
 * BSD LICENSE
 *
 * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
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
 *
 * $FreeBSD: projects/armv6/sys/dev/isci/scil/scu_event_codes.h 231136 2012-02-07 17:43:58Z jimharris $
 */
#ifndef __SCU_EVENT_CODES_HEADER__
#define __SCU_EVENT_CODES_HEADER__

/**
 * @file
 *
 * @brief This file contains the constants and macros for the SCU event codes.
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define SCU_EVENT_TYPE_CODE_SHIFT      24
#define SCU_EVENT_TYPE_CODE_MASK       0x0F000000

#define SCU_EVENT_SPECIFIC_CODE_SHIFT  18
#define SCU_EVENT_SPECIFIC_CODE_MASK   0x00FC0000

#define SCU_EVENT_CODE_MASK \
   (SCU_EVENT_TYPE_CODE_MASK | SCU_EVENT_SPECIFIC_CODE_MASK)

/**
 * This macro constructs an SCU event type from the type value.
 */
#define SCU_EVENT_TYPE(type) \
   ((U32)(type) << SCU_EVENT_TYPE_CODE_SHIFT)

/**
 * This macro constructs an SCU event specifier from the code value.
 */
#define SCU_EVENT_SPECIFIC(code) \
   ((U32)(code) << SCU_EVENT_SPECIFIC_CODE_SHIFT)

/**
 * This macro constructs a combines an SCU event type and SCU event specifier
 * from the type and code values.
 */
#define SCU_EVENT_MESSAGE(type, code) \
   ((type) | SCU_EVENT_SPECIFIC(code))

/**
 * @name SCU_EVENT_TYPES
 */
/*@{*/
#define SCU_EVENT_TYPE_SMU_COMMAND_ERROR  SCU_EVENT_TYPE(0x08)
#define SCU_EVENT_TYPE_SMU_PCQ_ERROR      SCU_EVENT_TYPE(0x09)
#define SCU_EVENT_TYPE_SMU_ERROR          SCU_EVENT_TYPE(0x00)
#define SCU_EVENT_TYPE_TRANSPORT_ERROR    SCU_EVENT_TYPE(0x01)
#define SCU_EVENT_TYPE_BROADCAST_CHANGE   SCU_EVENT_TYPE(0x02)
#define SCU_EVENT_TYPE_OSSP_EVENT         SCU_EVENT_TYPE(0x03)
#define SCU_EVENT_TYPE_FATAL_MEMORY_ERROR SCU_EVENT_TYPE(0x0F)
#define SCU_EVENT_TYPE_RNC_SUSPEND_TX     SCU_EVENT_TYPE(0x04)
#define SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX  SCU_EVENT_TYPE(0x05)
#define SCU_EVENT_TYPE_RNC_OPS_MISC       SCU_EVENT_TYPE(0x06)
#define SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT SCU_EVENT_TYPE(0x07)
#define SCU_EVENT_TYPE_ERR_CNT_EVENT      SCU_EVENT_TYPE(0x0A)
/*@}*/

/**
 * @name SCU_EVENT_SPECIFIERS
 */
/*@{*/
#define SCU_EVENT_SPECIFIER_DRIVER_SUSPEND 0x20
#define SCU_EVENT_SPECIFIER_RNC_RELEASE    0x00
/*@}*/

/**
 * @name SMU_COMMAND_EVENTS
 */
/*@{*/
#define SCU_EVENT_INVALID_CONTEXT_COMMAND \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_COMMAND_ERROR, 0x00)
/*@}*/

/**
 * @name SMU_PCQ_EVENTS
 */
/*@{*/
#define SCU_EVENT_UNCORRECTABLE_PCQ_ERROR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_PCQ_ERROR, 0x00)
/*@}*/

/**
 *  @name SMU_EVENTS
 */
/*@{*/
#define SCU_EVENT_UNCORRECTABLE_REGISTER_WRITE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x02)
#define SCU_EVENT_UNCORRECTABLE_REGISTER_READ \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x03)
#define SCU_EVENT_PCIE_INTERFACE_ERROR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x04)
#define SCU_EVENT_FUNCTION_LEVEL_RESET \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_SMU_ERROR, 0x05)
/*@}*/

/**
 * @name TRANSPORT_LEVEL_ERRORS
 */
/*@{*/
#define SCU_EVENT_ACK_NAK_TIMEOUT_ERROR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_TRANSPORT_ERROR, 0x00)
/*@}*/

/**
 * @name BROADCAST_CHANGE_EVENTS
 */
/*@{*/
#define SCU_EVENT_BROADCAST_CHANGE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x01)
#define SCU_EVENT_BROADCAST_RESERVED0 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x02)
#define SCU_EVENT_BROADCAST_RESERVED1 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x03)
#define SCU_EVENT_BROADCAST_SES \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x04)
#define SCU_EVENT_BROADCAST_EXPANDER \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x05)
#define SCU_EVENT_BROADCAST_AEN \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x06)
#define SCU_EVENT_BROADCAST_RESERVED3 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x07)
#define SCU_EVENT_BROADCAST_RESERVED4 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x08)
#define SCU_EVENT_PE_SUSPENDED \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_BROADCAST_CHANGE, 0x09)
/*@}*/

/**
 * @name OSSP_EVENTS
 */
/*@{*/
#define SCU_EVENT_PORT_SELECTOR_DETECTED \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x10)
#define SCU_EVENT_SENT_PORT_SELECTION \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x11)
#define SCU_EVENT_HARD_RESET_TRANSMITTED \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x12)
#define SCU_EVENT_HARD_RESET_RECEIVED \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x13)
#define SCU_EVENT_RECEIVED_IDENTIFY_TIMEOUT \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x15)
#define SCU_EVENT_LINK_FAILURE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x16)
#define SCU_EVENT_SATA_SPINUP_HOLD \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x17)
#define SCU_EVENT_SAS_15_SSC \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x18)
#define SCU_EVENT_SAS_15 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x19)
#define SCU_EVENT_SAS_30_SSC \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1A)
#define SCU_EVENT_SAS_30 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1B)
#define SCU_EVENT_SAS_60_SSC \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1C)
#define SCU_EVENT_SAS_60 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1D)
#define SCU_EVENT_SATA_15_SSC \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1E)
#define SCU_EVENT_SATA_15 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x1F)
#define SCU_EVENT_SATA_30_SSC \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x20)
#define SCU_EVENT_SATA_30 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x21)
#define SCU_EVENT_SATA_60_SSC \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x22)
#define SCU_EVENT_SATA_60 \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x23)
#define SCU_EVENT_SAS_PHY_DETECTED \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x24)
#define SCU_EVENT_SATA_PHY_DETECTED \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_OSSP_EVENT, 0x25)
/*@}*/

/**
 * @name FATAL_INTERNAL_MEMORY_ERROR_EVENTS
 */
/*@{*/
#define SCU_EVENT_TSC_RNSC_UNCORRECTABLE_ERROR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_FATAL_MEMORY_ERROR,  0x00)
#define SCU_EVENT_TC_RNC_UNCORRECTABLE_ERROR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_FATAL_MEMORY_ERROR,  0x01)
#define SCU_EVENT_ZPT_UNCORRECTABLE_ERROR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_FATAL_MEMORY_ERROR,  0x02)
/*@}*/

/**
 * @name REMOTE_NODE_SUSPEND_EVENTS
 */
/*@{*/
#define SCU_EVENT_TL_RNC_SUSPEND_TX \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x00)
#define SCU_EVENT_TL_RNC_SUSPEND_TX_RX \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX, 0x00)
#define SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_DATA_LEN_ERR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x1A)
#define SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_OFFSET_ERR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x20)
#define SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_DMASETUP_DIERR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x27)
#define SCU_EVENT_TL_RNC_SUSPEND_TX_DONE_XFERCNT_ERR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x28)
#define SCU_EVENT_TL_RNC_SUSPEND_TX_RX_DONE_PLD_LEN_ERR \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX, 0x21)
#define SCU_EVENT_DRIVER_POST_RNC_SUSPEND_TX \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX, 0x20)
#define SCU_EVENT_DRIVER_POST_RNC_SUSPEND_TX_RX \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX, 0x20)
/*@}*/

/**
 * @name REMOTE_NODE_MISC_EVENTS
 */
/*@{*/
#define SCU_EVENT_POST_RCN_RELEASE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC,SCU_EVENT_SPECIFIER_RNC_RELEASE)
#define SCU_EVENT_POST_IT_NEXUS_LOSS_TIMER_ENABLE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x01)
#define SCU_EVENT_POST_IT_NEXUS_LOSS_TIMER_DISABLE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x02)
#define SCU_EVENT_POST_RNC_COMPLETE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x03)
#define SCU_EVENT_POST_RNC_INVALIDATE_COMPLETE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_RNC_OPS_MISC, 0x04)
/*@}*/

/**
 * @name ERROR_COUNT_EVENT
 */
/*@{*/
#define SCU_ERR_CNT_RX_CREDIT_BLOCKED_RECEIVED_INDEX  0x00
#define SCU_ERR_CNT_TX_DONE_CREDIT_TIMEOUT_INDEX      0x01
#define SCU_ERR_CNT_RX_DONE_CREDIT_TIMEOUT_INDEX      0x02
#define SCU_ERR_CNT_INACTIVITY_TIMER_EXPIRED_INDEX    0x03
#define SCU_ERR_CNT_TX_DONE_ACK_NAK_TIMEOUT_INDEX     0x04
#define SCU_ERR_CNT_RX_DONE_ACK_NAK_TIMEOUT_INDEX     0x05
#define SCU_ERR_CNT_MAX_INDEX                         0x06

#define SCU_EVENT_ERR_CNT(name) \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_ERR_CNT_EVENT, SCU_ERR_CNT_ ## name ## _INDEX)
/*@}*/

/**
 * This macro returns the SCU event type from the event code.
 */
#define scu_get_event_type(event_code) \
   ((event_code) & SCU_EVENT_TYPE_CODE_MASK)

/**
 * This macro returns the SCU event specifier from the event code.
 */
#define scu_get_event_specifier(event_code) \
   ((event_code) & SCU_EVENT_SPECIFIC_CODE_MASK)

/**
 * This macro returns the combined SCU event type and SCU event specifier from
 * the event code.
 */
#define scu_get_event_code(event_code) \
   ((event_code) & SCU_EVENT_CODE_MASK)


/**
 * @name PTS_SCHEDULE_EVENT
 */
/*@{*/
#define SCU_EVENT_SMP_RESPONSE_NO_PE \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT, 0x00)
#define SCU_EVENT_SPECIFIC_SMP_RESPONSE_NO_PE \
   scu_get_event_specifier(SCU_EVENT_SMP_RESPONSE_NO_PE)

#define SCU_EVENT_TASK_TIMEOUT \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT, 0x01)
#define SCU_EVENT_SPECIFIC_TASK_TIMEOUT \
   scu_get_event_specifier(SCU_EVENT_TASK_TIMEOUT)

#define SCU_EVENT_IT_NEXUS_TIMEOUT \
   SCU_EVENT_MESSAGE(SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT, 0x02)
#define SCU_EVENT_SPECIFIC_IT_NEXUS_TIMEOUT \
   scu_get_event_specifier(SCU_EVENT_IT_NEXUS_TIMEOUT)
/*@}*/

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __SCU_EVENT_CODES_HEADER__
