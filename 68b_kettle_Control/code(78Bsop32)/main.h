#ifndef __main_h
#define __main_h
// Hal: exp: #define P_led P10 -----------------

// Const: exp: #define D_data 1 ----------------
// base 1ms
#define D_5ms 5
#define D_1000ms 3000
// Globle Var -----------------------------------------
#ifdef __main_c
bit bLedFlash;
bit led12;
bit led14;
bit b4ms;
uint8_t tick;
#else
extern bit b4ms;
extern bit led12;
extern bit led14;
extern bit bLedFlash;
extern uint8_t tick;
#endif

// Action Macro: exp: #define F_getData() ------

// Function ------------------------------------
void TimeProcess();
void TaskSetting();
void TaskProcess();
void DisplayProcess();
#endif