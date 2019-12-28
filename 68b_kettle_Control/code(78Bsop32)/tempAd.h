#ifndef  __tempAd_h
	#define __tempAd_h
//Hal-------------------------
//ad1
	#define D_wdChannel 0x0f
//ad0
	#define D_swChannel 0x0f
	#define P_waterLevel    P3_3
	#define F_clrWater()    P_waterLevel = 0
//Const
	#define D_shortValue 100
	#define D_offValue   4000  //39K
	#define D_waterLowAd   3750  //
	#define D_padInvalidTime2   4  //6sec to heat
	#define D_padInvalidTime1   2 //3sec to test Water
	#define D_padValidTime  3   //3min
	#define D_testWaterCount 10
	#define D_testWaterLowCount 6

//Var
	#ifdef __tempAd_c
bit bAdShort;
bit bAdOff;
bit bLastKettleValid;
bit bKettleValid;
bit bTestWaterLevel;
bit bWaterLow;
bit bSwitch;
uint8_t padInvalidTimer1, padInvalidTimer2, padValidTimer, xdPadInvalidTimer;
uint8_t curTemp, lastTemp;
uint8_t testWaterLowCounter;
uint8_t testWaterCounter;
uint16_t waterLowAdThreshold;
	#else
extern bit bAdShort;
extern bit bAdOff;
extern bit bLastKettleValid;
extern bit bKettleValid;
extern bit bTestWaterLevel;
extern bit bWaterLow;
extern bit bSwitch;
extern uint8_t padInvalidTimer1, padInvalidTimer2, padValidTimer, xdPadInvalidTimer;
extern uint8_t curTemp, lastTemp;
extern uint8_t testWaterLowCounter;
extern uint8_t testWaterCounter;
extern uint16_t waterLowAdThreshold;


	#endif

//Function
void    AdInit(void);
void    GetTemp(void);
void    TestWaterLevel(void);

#endif
