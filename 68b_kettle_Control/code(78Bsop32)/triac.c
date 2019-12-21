#define __triac_c

#include    "includeAll.h"

void InitTriac()
{
	bWattSetted = 0 ;
	bLastZero = 0 ;
	bZero = 0 ;
	bDelay = 0 ;
	delayTimer = 0 ;
	triacTimer = 0 ;
	fireType = 0 ;
	
}
