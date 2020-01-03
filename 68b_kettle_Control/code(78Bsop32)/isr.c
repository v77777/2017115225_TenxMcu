//=============================================================================
//Name		:isr.c
//Purpose	:Interrupt Service Routine
//=============================================================================
#define     _ISR_C

#include    "includeAll.h"

//=============================================================================
// Function:	void INT0_int(void)
// Purpose:	INT0 pin interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void INT0_int(void) interrupt 0
{
	IE0 = 0;            //clear interrupt flag
}
//=============================================================================
// Function:	void TIMER0_int(void)
// Purpose:	TIMER0 interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void TIMER0_int(void) interrupt 1
{
	/*TF0 = 0;            //clear interrupt flag
	TR0 = 0;
	TH0 += 246;     //238= 8cycle  246=13cycle  stepMotor
	TL0 += 2;
	TR0 = 1;
	#ifndef POWERSAVE
	gBTimer0RollOver++;
	AntiNoiseTimer++;
	if (AntiNoiseTimer > 50) AntiNoiseTimer = 50;
	#endif
	//------------*/
}
//=============================================================================
// Function:	void INT1_int(void)
// Purpose:	INT1 pin interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void INT1_int(void) interrupt 2
{
	IE1 = 0;            //clear interrupt flag
}
//=============================================================================
// Function:	void TIMER1_int(void)
// Purpose:	TIMER1 interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void TIMER1_int(void) interrupt 3
{
	/*TF1 = 0;            //clear interrupt flag
	TR1 = 0;
	TH1 = (65536 - 28860) / 256;        //20ms timer1 interrupt
	TL1 = (65536 - 28860) % 256;
	#ifndef POWERSAVE
	if (RawDataInvalidFlag) {
		AntiNoiseDebounceTimer++;
		if (AntiNoiseDebounceTimer > 10) {
			AntiNoiseTimer = 0;
			RawDataInvalidFlag = 0;
		}
	}
	#endif
	TR1 = 1;*/
}
//=============================================================================
// Function:	void UART_int(void)
// Purpose:	UART interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void UART_int(void) interrupt 4
{
	TI = 0;             //clear interrupt flag
	RI = 0;             //clear interrupt flag
}
//=============================================================================
// Function:	void TIMER2_int(void)
// Purpose:	TIMER2 interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void TIMER2_int(void) interrupt 5
{//88khz
	TF2 = 0; // clear interrupt flag
  	b1ms = 1;
  	if(buzzCounter>0){
  		F_buzz();
			buzzCounter--;
		}
	if(led12){
		BuzzCount(100);
		led12 = 0;
	}
}
//=============================================================================
// Function:	void TIMER3_int(void)
// Purpose:	TIMER3 interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void TIMER3_int(void) interrupt 7
{
	/*INTFLG &= ~TF3;
	#ifdef POWERSAVE
	gBTimer0RollOver++;
	AntiNoiseTimer++;
	if (AntiNoiseTimer > 50) AntiNoiseTimer = 50;
	if (RawDataInvalidFlag) {
		AntiNoiseDebounceTimer++;
		if (AntiNoiseDebounceTimer > 10) {
			AntiNoiseTimer = 0;
			RawDataInvalidFlag = 0;
		}
	}
	#endif*/
}
//=============================================================================
// Function:	void P1_int(void)
// Purpose:	P1 pin interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void P1_int(void) interrupt 8
{
	INTFLG &= ~P1IF;
}
//=============================================================================
// Function:	void INT2_int(void)
// Purpose:	INT2 pin interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void INT2_int(void) interrupt 9
{
	INTFLG &= ~IE2;
}
//=============================================================================
// Function:	void ADC_TK_int(void)
// Purpose:	ADC&TOUCHKEY interrupt vector
// Input:	none
// OutPut:	none
// Author:
//=============================================================================
void ADC_TK_int(void) interrupt 10
{
	INTFLG &= ~ADIF;
	INTFLG &= ~TKIF;
	TKCON2 &= ~TKAUTO;  //disable touch key auto scan
}
