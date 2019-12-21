#ifndef __buzz_h
    #define __buzz_h
//HAL--------------------
      #define P_buzz    P1_5
      #define F_buzz()  P_buzz = ~P_buzz
//Const--------------------
    #define D_buzzLastTime   25    //25*4ms(T0) = last 100ms per Buzz
    #define D_buzzIntervalTime   250 //250*4ms(T0) = Interval 1s between buzzs
//Var----------------------
    #ifdef __buzz_c
        bit b100Buzz;
        uint8_t buzzLastTimer;
        uint8_t buzzCounter;

    #else
        extern  bit b100Buzz;
        extern uint8_t buzzLastTimer;
        extern uint8_t buzzCounter;

    #endif

//Function----------------------
	void BuzzCount(uint8_t count);
    void Buzz();
#endif
