#ifndef __display_h
#define __display_h
// Hal: exp: #define P_led P10 -----------------
#define P_led P1_1
// Const: exp: #define D_data 1 ----------------
#define D_ledOn 1  //高电位亮
#define D_ledOff 0 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c

#else

#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledOn() P_led = D_ledOn
#define F_ledOff() P_led = D_ledOff
#define F_ledNeg() P_led = ~P_led
// Function ------------------------------------

#endif