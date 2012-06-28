/*
 * Copyright (c) 1999 Lennart Augustsson <augustss@netbsd.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * This file contains fallback-compatibility code for the old FreeBSD
 * USB stack.
 */
#ifdef HID_COMPAT7

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: projects/armv6/lib/libusbhid/descr_compat.c 188945 2009-02-23 18:36:54Z thompsa $");

#include <sys/types.h>

#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/ioctl.h>

#include <dev/usb/usb.h>

#include "usbhid.h"
#include "usbvar.h"

int
hid_set_immed_compat7(int fd, int enable)
{
	return (ioctl(fd, USB_SET_IMMED, &enable));
}

int
hid_get_report_id_compat7(int fd)
{
	int temp = -1;

	if (ioctl(fd, USB_GET_REPORT_ID, &temp) < 0)
		return (-1);

	return (temp);
}

report_desc_t
hid_get_report_desc_compat7(int fd)
{
	struct usb_ctl_report_desc rep;

	rep.ucrd_size = 0;
	if (ioctl(fd, USB_GET_REPORT_DESC, &rep) < 0)
		return (NULL);

	return (hid_use_report_desc(rep.ucrd_data, (unsigned int)rep.ucrd_size));
}
#endif	/* HID_COMPAT7 */
