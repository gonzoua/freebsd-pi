/* $NetBSD: negtf2.c,v 1.1 2011/01/17 10:08:35 matt Exp $ */

/*
 * Written by Matt Thomas, 2011.  This file is in the Public Domain.
 */

#include "softfloat-for-gcc.h"
#include "milieu.h"
#include "softfloat.h"

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: projects/armv6/lib/libc/softfloat/negtf2.c 232120 2012-02-24 18:39:55Z cognet $");

#ifdef FLOAT128

float128 __negtf2(float128);

float128
__negtf2(float128 a)
{

	/* libgcc1.c says -a */
	a.high ^= FLOAT64_MANGLE(0x8000000000000000ULL);
	return a;
}

#endif /* FLOAT128 */
