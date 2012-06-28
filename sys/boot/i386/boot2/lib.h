/*
 * Copyright (c) 1998 Robert Nordier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are freely
 * permitted provided that the above copyright notice and this
 * paragraph and the following disclaimer are duplicated in all
 * such forms.
 *
 * This software is provided "AS IS" and without any express or
 * implied warranties, including, without limitation, the implied
 * warranties of merchantability and fitness for a particular
 * purpose.
 */

/*
 * $FreeBSD: projects/armv6/sys/boot/i386/boot2/lib.h 220337 2011-04-04 18:23:55Z rdivacky $
 */

void sio_init(int) __attribute__((regparm (3)));
void sio_flush(void);
void sio_putc(int) __attribute__((regparm (3)));
int sio_getc(void);
int sio_ischar(void);
