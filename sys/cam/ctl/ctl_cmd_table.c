/*-
 * Copyright (c) 2003, 2004, 2005, 2009 Silicon Graphics International Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 *
 * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_cmd_table.c#4 $
 * $FreeBSD: projects/armv6/sys/cam/ctl/ctl_cmd_table.c 234858 2012-05-01 04:01:22Z gonzo $
 */
/*
 * CAM Target Layer command table.
 *
 * Author: Ken Merry <ken@FreeBSD.org>, Kim Le
 */

#include <sys/cdefs.h>
#include <sys/param.h>
#include <sys/systm.h>
#include <sys/kernel.h>
#include <sys/types.h>
#include <sys/malloc.h>
#include <sys/condvar.h>
#include <sys/queue.h>
#include <sys/sysctl.h>

#include <cam/scsi/scsi_all.h>
#include <cam/scsi/scsi_da.h>
#include <cam/ctl/ctl_io.h>
#include <cam/ctl/ctl.h>
#include <cam/ctl/ctl_frontend.h>
#include <cam/ctl/ctl_backend.h>
#include <cam/ctl/ctl_frontend_internal.h>
#include <cam/ctl/ctl_ioctl.h>
#include <cam/ctl/ctl_ha.h>
#include <cam/ctl/ctl_private.h>

/*
 * Whenever support for a new command is added, it should be added to this
 * table.
 */
struct ctl_cmd_entry ctl_cmd_table[] =
{
/* 00 TEST UNIT READY */
{ctl_tur, CTL_SERIDX_TUR, CTL_CMD_FLAG_OK_ON_BOTH |
			  CTL_FLAG_DATA_NONE |
			  CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_TUR},

/* 01 REWIND */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 02 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 03 REQUEST SENSE */
{ctl_request_sense, CTL_SERIDX_RQ_SNS, CTL_FLAG_DATA_IN |
				       CTL_CMD_FLAG_OK_ON_ALL_LUNS |
				       CTL_CMD_FLAG_ALLOW_ON_RESV |
				       CTL_CMD_FLAG_NO_SENSE |
				       CTL_CMD_FLAG_OK_ON_STOPPED |
				       CTL_CMD_FLAG_OK_ON_INOPERABLE |
				       CTL_CMD_FLAG_OK_ON_OFFLINE |
				       CTL_CMD_FLAG_OK_ON_SECONDARY |
				       CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_NONE},

/* 04 FORMAT UNIT */
{ctl_format, CTL_SERIDX_FORMAT, CTL_CMD_FLAG_OK_ON_SLUN |
				CTL_CMD_FLAG_OK_ON_INOPERABLE |
				CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* 05 READ BLOCK LIMITS */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 06 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 07 REASSIGN BLOCKS */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 08 READ(6) */
{ctl_read_write, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_SLUN |
				  CTL_FLAG_DATA_IN |
				  CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_READ | CTL_LUN_PAT_RANGE},

/* 09 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 0A WRITE(6) */
{ctl_read_write, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_SLUN |
				   CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_WRITE | CTL_LUN_PAT_RANGE},

/* 0B SEEK(6) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 0C */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 0D */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 0E */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 0F READ REVERSE(6) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 10 WRITE FILEMARKS(6) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 11 SPACE(6) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 12 INQUIRY */
{ctl_inquiry, CTL_SERIDX_INQ, CTL_CMD_FLAG_OK_ON_ALL_LUNS |
			      CTL_CMD_FLAG_ALLOW_ON_RESV |
			      CTL_CMD_FLAG_NO_SENSE |
			      CTL_CMD_FLAG_OK_ON_STOPPED |
			      CTL_CMD_FLAG_OK_ON_INOPERABLE |
			      CTL_CMD_FLAG_OK_ON_OFFLINE |
			      CTL_CMD_FLAG_OK_ON_SECONDARY |
			      CTL_FLAG_DATA_IN |
			      CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_NONE},

/* 13 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 14 RECOVER BUFFERED DATA */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 15 MODE SELECT(6) */
{ctl_mode_select, CTL_SERIDX_MD_SEL, CTL_CMD_FLAG_OK_ON_BOTH |
				     CTL_CMD_FLAG_OK_ON_STOPPED |
				     CTL_CMD_FLAG_OK_ON_INOPERABLE |
				     CTL_CMD_FLAG_OK_ON_SECONDARY |
				     CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* 16 RESERVE(6) */
{ctl_scsi_reserve, CTL_SERIDX_RESV, CTL_CMD_FLAG_ALLOW_ON_RESV |
				    CTL_CMD_FLAG_OK_ON_BOTH |
				    CTL_CMD_FLAG_OK_ON_STOPPED |
				    CTL_CMD_FLAG_OK_ON_INOPERABLE |
				    CTL_CMD_FLAG_OK_ON_SECONDARY |
				    CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* 17 RELEASE(6) */
{ctl_scsi_release, CTL_SERIDX_REL, CTL_CMD_FLAG_ALLOW_ON_RESV |
				   CTL_CMD_FLAG_OK_ON_BOTH |
				   CTL_CMD_FLAG_OK_ON_STOPPED |
				   CTL_CMD_FLAG_OK_ON_INOPERABLE |
				   CTL_CMD_FLAG_OK_ON_SECONDARY |
				   CTL_FLAG_DATA_NONE,
 CTL_LUN_PAT_NONE},

/* 18 COPY */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 19 ERASE(6) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 1A MODE SENSE(6) */
{ctl_mode_sense, CTL_SERIDX_MD_SNS, CTL_CMD_FLAG_OK_ON_BOTH |
				    CTL_CMD_FLAG_OK_ON_STOPPED |
				    CTL_CMD_FLAG_OK_ON_INOPERABLE |
				    CTL_CMD_FLAG_OK_ON_SECONDARY |
				    CTL_FLAG_DATA_IN,
 CTL_LUN_PAT_NONE},

/* 1B START STOP UNIT */
{ctl_start_stop, CTL_SERIDX_START, CTL_CMD_FLAG_OK_ON_SLUN |
				   CTL_CMD_FLAG_OK_ON_STOPPED |
				   CTL_CMD_FLAG_OK_ON_INOPERABLE |
				   CTL_CMD_FLAG_OK_ON_OFFLINE |
				   CTL_FLAG_DATA_NONE |
				   CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_NONE},

/* 1C RECEIVE DIAGNOSTIC RESULTS */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 1D SEND DIAGNOSTIC */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 1E PREVENT ALLOW MEDIUM REMOVAL */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 1F */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 20 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 21 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 22 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 23 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 24 SET WINDOW */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 25 READ CAPACITY(10) */
{ctl_read_capacity, CTL_SERIDX_RD_CAP, CTL_CMD_FLAG_OK_ON_SLUN|
				       CTL_CMD_FLAG_OK_ON_STOPPED |
				       CTL_CMD_FLAG_OK_ON_INOPERABLE |
				       CTL_CMD_FLAG_OK_ON_SECONDARY |
				       CTL_FLAG_DATA_IN |
				       CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_READCAP},

/* 26 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 27 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 28 READ(10) */
{ctl_read_write, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_SLUN |
				  CTL_FLAG_DATA_IN |
				  CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_READ | CTL_LUN_PAT_RANGE},

/* 29 READ GENERATION */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 2A WRITE(10) */
{ctl_read_write, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_SLUN| CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_WRITE | CTL_LUN_PAT_RANGE},

/* 2B SEEK(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 2C ERASE(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 2D READ UPDATED BLOCK */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 2E WRITE AND VERIFY(10) */
{ctl_read_write, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_SLUN| CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_WRITE | CTL_LUN_PAT_RANGE},

/* 2F VERIFY(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 30 SEARCH DATA HIGH(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 31 SEARCH DATA EQUAL(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 32 SEARCH DATA LOW(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 33 SET LIMITS(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 34 PRE-FETCH(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 35 SYNCHRONIZE CACHE(10) */
{ctl_sync_cache, CTL_SERIDX_START, CTL_CMD_FLAG_OK_ON_SLUN |
				   CTL_FLAG_DATA_NONE,
 CTL_LUN_PAT_NONE},

/* 36 LOCK UNLOCK CACHE(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 37 READ DEFECT DATA(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 38 MEDIUM SCAN */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 39 COMPARE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 3A COPY AND VERIFY */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 3B WRITE BUFFER */
{ctl_write_buffer, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_PROC |
				     CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* 3C READ BUFFER */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 3D UPDATE BLOCK */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 3E READ LONG */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 3F WRITE LONG */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 40 CHANGE DEFINITION */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 41 WRITE SAME(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 42 READ SUB-CHANNEL */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 43 READ TOC/PMA/ATIP */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 44 REPORT DENSITY SUPPORT */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 45 PLAY AUDIO(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 46 GET CONFIGURATION */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 47 PLAY AUDIO MSF */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 48 PLAY AUDIO TRACK INDEX */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 49 PLAY TRACK RELATIVE(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 4A GET EVENT STATUS NOTIFICATION */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 4B PAUSE/RESUME */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 4C LOG SELECT */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 4D LOG SENSE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 4E STOP PLAY/SCAN */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 4F */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 50 XDWRITE(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 51 XPWRITE(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 52 XDREAD(10) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 53 RESERVE TRACK */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 54 SEND OPC INFORMATION */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 55 MODE SELECT(10) */
{ctl_mode_select, CTL_SERIDX_MD_SEL, CTL_CMD_FLAG_OK_ON_BOTH |
				     CTL_CMD_FLAG_OK_ON_STOPPED |
				     CTL_CMD_FLAG_OK_ON_INOPERABLE |
				     CTL_CMD_FLAG_OK_ON_SECONDARY |
				     CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* 56 RESERVE(10) */
{ctl_scsi_reserve, CTL_SERIDX_RESV, CTL_CMD_FLAG_ALLOW_ON_RESV |
				    CTL_CMD_FLAG_OK_ON_BOTH |
				    CTL_CMD_FLAG_OK_ON_STOPPED |
				    CTL_CMD_FLAG_OK_ON_INOPERABLE |
				    CTL_CMD_FLAG_OK_ON_SECONDARY |
				    CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* 57 RELEASE(10) */
{ctl_scsi_release, CTL_SERIDX_REL, CTL_CMD_FLAG_ALLOW_ON_RESV |
				   CTL_CMD_FLAG_OK_ON_BOTH |
				   CTL_CMD_FLAG_OK_ON_STOPPED |
				   CTL_CMD_FLAG_OK_ON_INOPERABLE |
				   CTL_CMD_FLAG_OK_ON_SECONDARY |
				   CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* 58 REPAIR TRACK */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 59 READ MASTER CUE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 5A MODE SENSE(10) */
{ctl_mode_sense, CTL_SERIDX_MD_SNS, CTL_CMD_FLAG_OK_ON_BOTH |
				    CTL_CMD_FLAG_OK_ON_STOPPED |
				    CTL_CMD_FLAG_OK_ON_INOPERABLE |
				    CTL_CMD_FLAG_OK_ON_SECONDARY |
				    CTL_FLAG_DATA_IN,
 CTL_LUN_PAT_NONE},

/* 5B CLOSE TRACK/SESSION */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 5C READ BUFFER CAPACITY */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 5D SEND CUE SHEET */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 5E PERSISTENT RESERVE IN */
{ctl_persistent_reserve_in, CTL_SERIDX_PRES_IN, CTL_CMD_FLAG_ALLOW_ON_RESV |
						CTL_CMD_FLAG_OK_ON_BOTH |
						CTL_CMD_FLAG_OK_ON_STOPPED |
						CTL_CMD_FLAG_OK_ON_INOPERABLE |
						CTL_CMD_FLAG_OK_ON_SECONDARY |
						CTL_FLAG_DATA_IN |
						CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_NONE},

//{ctl_persistent_reserve_in, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE},

/* 5F PERSISTENT RESERVE OUT */
{ctl_persistent_reserve_out, CTL_SERIDX_PRES_OUT, CTL_CMD_FLAG_ALLOW_ON_RESV |
						  CTL_CMD_FLAG_OK_ON_BOTH |
						  CTL_CMD_FLAG_OK_ON_STOPPED |
						  CTL_CMD_FLAG_OK_ON_INOPERABLE|
						  CTL_CMD_FLAG_OK_ON_SECONDARY |
						  CTL_FLAG_DATA_OUT |
						  CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_NONE},

//{ctl_persistent_reserve_out, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE},

/* 60 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 61 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 62 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 63 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 64 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 65 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 66 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 67 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 68 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 69 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 6A */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 6B */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 6C */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 6D */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 6E */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 6F */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 70 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 71 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 72 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 73 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 74 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 75 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 76 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 77 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 78 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 79 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 7A */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 7B */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 7C */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 7D */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 7E */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 7F */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 80 XDWRITE EXTENDED(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 81 REBUILD(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 82 REGENERATE(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 83 EXTENDED COPY */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 84 RECEIVE COPY RESULTS */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 85 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 86 ACCESS CONTROL IN */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 87 ACCESS CONTROL OUT */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 88 READ(16) */
{ctl_read_write, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_SLUN | CTL_FLAG_DATA_IN |
                                  CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_READ | CTL_LUN_PAT_RANGE},

/* 89 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 8A WRITE(16) */
{ctl_read_write, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_SLUN| CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_WRITE | CTL_LUN_PAT_RANGE},

/* 8B */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 8C READ ATTRIBUTE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 8D WRITE ATTRIBUTE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 8E WRITE AND VERIFY(16) */
{ctl_read_write, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_SLUN| CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_WRITE | CTL_LUN_PAT_RANGE},

/* 8F VERIFY(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 90 PRE-FETCH(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 91 SYNCHRONIZE CACHE(16) */
{ctl_sync_cache, CTL_SERIDX_START, CTL_CMD_FLAG_OK_ON_SLUN |
				   CTL_FLAG_DATA_NONE,
 CTL_LUN_PAT_NONE},

/* 92 LOCK UNLOCK CACHE(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 93 WRITE SAME(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 94 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 95 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 96 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 97 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 98 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 99 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 9A */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 9B */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 9C */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 9D */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* 9E SERVICE ACTION IN(16) */
/* XXX KDM not all service actions will be read capacity!! */
{ctl_service_action_in, CTL_SERIDX_RD_CAP, CTL_CMD_FLAG_OK_ON_SLUN |
					   CTL_CMD_FLAG_OK_ON_STOPPED |
					   CTL_CMD_FLAG_OK_ON_INOPERABLE |
					   CTL_CMD_FLAG_OK_ON_SECONDARY |
					   CTL_FLAG_DATA_IN |
					   CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_READCAP},

/* 9F SERVICE ACTION OUT(16) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* A0 REPORT LUNS */
{ctl_report_luns, CTL_SERIDX_INQ, CTL_CMD_FLAG_OK_ON_ALL_LUNS |
				  CTL_CMD_FLAG_ALLOW_ON_RESV |
				  CTL_CMD_FLAG_NO_SENSE |
				  CTL_CMD_FLAG_OK_ON_STOPPED |
				  CTL_CMD_FLAG_OK_ON_INOPERABLE |
				  CTL_CMD_FLAG_OK_ON_OFFLINE |
				  CTL_CMD_FLAG_OK_ON_SECONDARY |
				  CTL_FLAG_DATA_IN |
				  CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_NONE},

/* A1 BLANK */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* A2 SEND EVENT */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* A3 MAINTENANCE (IN) Service Action - (0A) REPORT TARGET PORT GROUP */
{ctl_maintenance_in, CTL_SERIDX_MAIN_IN, CTL_CMD_FLAG_OK_ON_BOTH |
				         CTL_CMD_FLAG_OK_ON_STOPPED |
				         CTL_CMD_FLAG_OK_ON_INOPERABLE |
				         CTL_CMD_FLAG_OK_ON_SECONDARY |
				         CTL_FLAG_DATA_IN,
 CTL_LUN_PAT_NONE},

/* A4 MAINTENANCE (OUT) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* A5 MOVE MEDIUM */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* A6 EXCHANGE MEDIUM */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* A7 MOVE MEDIUM ATTACHED */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* A8 READ(12) */
{ctl_read_write, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_SLUN | CTL_FLAG_DATA_IN |
                                  CTL_CMD_FLAG_ALLOW_ON_PR_RESV,
 CTL_LUN_PAT_READ | CTL_LUN_PAT_RANGE},

/* A9 PLAY TRACK RELATIVE(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* AA WRITE(12) */
{ctl_read_write, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_SLUN| CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_WRITE | CTL_LUN_PAT_RANGE},

/* AB SERVICE ACTION IN(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* AC ERASE(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* AD READ DVD STRUCTURE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* AE WRITE AND VERIFY(12) */
{ctl_read_write, CTL_SERIDX_WRITE, CTL_CMD_FLAG_OK_ON_SLUN| CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_WRITE | CTL_LUN_PAT_RANGE},

/* AF VERIFY(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B0 SEARCH DATA HIGH(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B1 SEARCH DATA EQUAL(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B2 SEARCH DATA LOW(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B3 SET LIMITS(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B4 READ ELEMENT STATUS ATTACHED */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B5 REQUEST VOLUME ELEMENT ADDRESS */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B6 SEND VOLUME TAG */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B7 READ DEFECT DATA(12) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B8 READ ELEMENT STATUS */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* B9 READ CD MSF */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* BA REDUNDANCY GROUP (IN) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* BB REDUNDANCY GROUP (OUT) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* BC SPARE (IN) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* BD SPARE (OUT) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* BE VOLUME SET (IN) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* BF VOLUME SET (OUT) */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* C0 - ISC_SEND_MSG_SHORT */
//{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE},
{ctl_isc, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_PROC | CTL_FLAG_DATA_NONE,
 CTL_LUN_PAT_NONE},

/* C1 - ISC_SEND_MSG */
//{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE},
{ctl_isc, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_PROC | CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* C2 - ISC_WRITE */
//{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE},
{ctl_isc, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_PROC | CTL_FLAG_DATA_OUT,
 CTL_LUN_PAT_NONE},

/* C3 - ISC_READ */
//{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE},
{ctl_isc, CTL_SERIDX_READ, CTL_CMD_FLAG_OK_ON_PROC | CTL_FLAG_DATA_IN,
 CTL_LUN_PAT_NONE},

/* C4 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* C5 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* C6 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* C7 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* C8 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* C9 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* CA */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* CB */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* CC */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* CD */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* CE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* CF */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D0 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D1 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D2 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D3 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D4 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D5 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D6 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D7 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D8 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* D9 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* DA */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* DB */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* DC */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* DD */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* DE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* DF */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E0 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E1 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E2 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E3 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E4 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E5 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E6 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E7 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E8 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* E9 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* EA */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* EB */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* EC */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* ED */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* EE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* EF */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F0 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F1 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F2 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F3 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F4 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F5 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F6 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F7 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F8 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* F9 */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* FA */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* FB */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* FC */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* FD */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* FE */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE},

/* FF */
{NULL, CTL_SERIDX_INVLD, CTL_CMD_FLAG_NONE, CTL_LUN_PAT_NONE}

};
