
#ifndef __typeAlias_h
#define __typeAlias_h

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long int uint32_t;
typedef char int8_t;
typedef short int16_t;
typedef long int32_t;

#define F_turnOnWDT() CFGWL = (CFGWL & 0x3f) | 0xC0
#define F_clearWDT() CLRWDT = 1

#endif
