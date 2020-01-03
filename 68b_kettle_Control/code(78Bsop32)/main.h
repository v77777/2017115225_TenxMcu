#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led P10 -----------------

// Const: exp: #define D_data 1 ----------------
// base 1ms
#define D_5ms 5
#define D_1000ms 1000
#define D_200ms 200
// Globle Var -----------------------------------------
#ifdef __main_c
bit bLedFlash;
bit led12;
bit led14;
bit key4;
bit key3;
bit b4ms;
uint8_t tick;
uint8_t i;
#else
extern bit b4ms;
extern bit led12;
extern bit led14;
extern bit key4;
extern bit key3;
extern bit bLedFlash;
extern uint8_t tick;
extern uint8_t i;
#endif

// Action Macro: exp: #define F_getData() ------

// Function ------------------------------------
void TimeProcess();
void TaskSetting();
void TaskProcess();
void DisplayProcess();
#endif