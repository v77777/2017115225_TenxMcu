#ifndef __triac_h
#define __triac_h

//Hal------------------
#define P_zero   P3_7
#define	P_triac	 P1_6

#define F_triacOn()   P_triac = 0
#define F_triacOff()  P_triac = 1

//Const-----------------
#define D_triacHoldTime   4 //base 0.25ms
#define D_fireType_0_16	    0x0000
#define D_fireType_1_16	    0x0001
#define D_fireType_2_16	    0x0003
#define D_fireType_4_16	    0x000f
#define D_fireType_8_16 	0x00ff
#define D_fireType_16_16	0xffff




//Var-----------------
	#ifdef __triac_c
		bit bLastZero ;
		bit bZero ;
		bit bDelay ;
		bit bWattSetted ;
		bit	bAlarm ;
		uint16_t fireType ;
		uint8_t triacTimer ,delayTimer ;
		uint8_t zeroCounter ;
	#else
		extern bit bLastZero ;
		extern bit bZero ;
		extern bit bDelay ;
		extern bit bWattSetted ;
		extern bit	bAlarm ;
		extern uint32_t fireType ;
		extern uint8_t triacTimer ,delayTimer ;
		extern uint8_t zeroCounter ;
	#endif
//Function-------------------
void InitTriac() ;


#endif
