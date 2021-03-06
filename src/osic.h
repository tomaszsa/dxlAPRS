/*
 * dxlAPRS toolchain
 *
 * Copyright (C) Hannes Schmelzer <oe5hpm@oevsv.at>
 * Copyright (C) Christian Rabler <oe5dxl@oevsv.at>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#ifndef __OSIC_H__
#define __OSIC_H__

#include <stdint.h>
#include "X2C.h"

void osic_flush(void);

void osic_WrLn(void);

void osic_WerrLn(void);

void osic_WrStr(char s[], unsigned long s_len);

void osic_WrStrLn(char s[], unsigned long s_len);

void osic_WerrStr(char s[], unsigned long s_len);

void osic_WerrStrLn(char s[], unsigned long s_len);

void osic_WrUINT32(uint32_t x, unsigned long witdh);

void osic_WrINT32(int32_t x, unsigned long witdh);

void osic_WrFixed(float x, long place, unsigned long witdh);

void osic_WrHex(unsigned long n, unsigned long f);

int osic_getptsname(int fd, char *name, int len);

int osic_grantpts(int fd);

int osic_unlockpts(int fd);

long osic_OpenAppendLong(char fn[], unsigned long fn_len);

long osic_OpenAppend(char fn[], unsigned long fn_len);

long osic_OpenWrite(char fn[], unsigned long fn_len);

long osic_OpenReadLong(char fn[], unsigned long fn_len);

long osic_OpenRead(char fn[], unsigned long fn_len);

long osic_OpenRW(char fn[], unsigned long fn_len);

long osic_OpenNONBLOCK(char fn[], unsigned long fn_len);

char osic_FdValid(long fd);

void osic_Close(long fd);

void osic_CloseSock(long fd);

long osic_RdBin(long fd,
		char buf[], unsigned long buf_len,
		unsigned long size);

void osic_WrBin(long fd, char buf[],
		unsigned long buf_len,
		unsigned long size);

void osic_Rename(char fname[], unsigned long fname_len,
		 char newname[], unsigned long newname_len);

int osic_Size(int fd);

void osic_Seek(long fd, unsigned long pos);

void osic_Seekcur(long fd, long rel);

void osic_Remove(char fname[], unsigned long fname_len, char *done);

char osic_Exists(char fname[], unsigned long fname_len);

int osic_symblink(char *existing, char *newname);

void osic_NextArg(char s[], unsigned long s_len);

void osic_Fill(char *buf, unsigned long len, char byte);

double osic_Random(void);

void X2C_BEGIN(int *argc, char *argv[],
	       int gc_auto, long gc_threshold, long heap_limit);

void X2C_PCOPY(void **ppcpy, size_t size);

long X2C_TRUNCI(double x, long min0, long max0);

unsigned long X2C_TRUNCC(double x, unsigned long min0, unsigned long max0);

float osic_cos(float x);

float osic_ln(float x);

float osic_sqrt(float x);

float osic_sin(float x);

float osic_arctan(float x);

float osic_tan(float x);

float osic_exp(float x);

float osic_power(float base, float exponent);

float osic_arccos(float x);

float osic_floor(float x);

void osic_alloc(X2C_ADDRESS *p, unsigned long size);

void osic_free(X2C_ADDRESS *a, unsigned long size);

unsigned long osic_time(void);

unsigned long X2C_LSH(unsigned long a, long length, long n);

char X2C_IN(unsigned long i, unsigned long bits, unsigned long set);

char X2C_INL(unsigned long i, unsigned long bits, unsigned long *set);

void X2C_INCL(unsigned long *set, unsigned long i, unsigned long bits);

void X2C_EXCL(unsigned long *set, unsigned long i, unsigned long bits);

unsigned long *X2C_COMPLEMENT(unsigned long *res, unsigned long *a, unsigned long length);

void X2C_DYNALLOCATE(char **a, size_t size, size_t lens[], size_t dims);

void X2C_DYNDEALLOCATE(char **a);

void *osic_chkptr(void *p);

#endif /* __OSIC_H__ */
