/* Configure optimized libm functions.  RV64 version.
   Copyright (C) 2024 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef RISCV64_MATH_PRIVATE_H
#define RISCV64_MATH_PRIVATE_H 1

#include <stdint.h>
#include <math.h>

#if __GNUC_PREREQ (14, 0) && defined __riscv_zfa

/* Use inline round and lround instructions.  */
#define TOINT_INTRINSICS 1

static inline double
roundtoint (double x)
{
	double y;

	__asm__ ("fround.d %0,%1,rne" : "=&f" (y): "f" (x));
	return y;
}

static inline int32_t
converttoint (double x)
{
	int32_t y;
	__asm__ ("fcvt.w.d %0,%1,rne" : "=&r" (y) : "f" (x));
	return y;
}

#endif

#include_next <math_private.h>

#endif
