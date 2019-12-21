#ifndef __display_h
#define __display_h
// Hal: exp: #define P_led P10 -----------------
#define P_led P1_0
// Const: exp: #define D_data 1 ----------------
#define D_ledOn 0  //高电位亮
#define D_ledOff 1 //低点位灭
// Globle Var -----------------------------------------
#ifdef __display_c
bit bflag0;
bit bflag;
#else
extern bit bflag0;
extern bit bflag;
#endif

// Action Macro: exp: #define F_getData() ------
#define F_ledOn() P_led = D_ledOn
#define F_ledOff() P_led = D_ledOff
#define F_ledNeg() P_led = ~P_led
// Function ------------------------------------
void DisplayNumber(uint8_t number);
void DisplayTenNumber(uint8_t number);
void DisplayBitNumber(uint8_t number);
void DisplayLED12(void);
void DisplayLED14(void);
#endif