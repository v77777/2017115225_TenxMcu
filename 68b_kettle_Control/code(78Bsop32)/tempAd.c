
#define __tempAd_c

#include    "includeAll.h"
//39k Pull up VCC, 12bits Ad sample
//0c--99c
#define D_tableSize 100
//10K

   code const uint16_t adTable[D_tableSize]={
   3974,3968,3962,3955,3949,3942,3935,3927,3919,3911,3901,3892,3882,
   3873,3863,3853,3842,3831,3820,3808,3795,3782,3768,3753,3738,3723,
   3707,3692,3677,3663,3650,3633,3616,3599,3580,3560,3539,3517,3495,
   3471,3448,3424,3400,3376,3353,3332,3306,3281,3255,3229,3202,3176,
   3149,3122,3094,3066,3037,3007,2977,2945,2912,2881,2849,2817,2784,
   2751,2718,2684,2650,2616,2582,2548,2514,2480,2447,2413,2381,2349,
   2317,2285,2253,2221,2189,2157,2124,2091,2058,2024,1990,1955,1919,
   1885,1853,1821,1790,1759,1728,1698,1668,1638,
   };
/*
//39K
code const uint16_t adTable[D_tableSize] = {
	3657, 3638, 3618, 3597, 3576, 3554, 3531, 3508, 3483, 3458, 3432, 3403, 3375,
	3347, 3319, 3290, 3260, 3230, 3198, 3165, 3131, 3095, 3059, 3022, 2984, 2947,
	2909, 2873, 2838, 2805, 2775, 2739, 2702, 2663, 2623, 2582, 2540, 2497, 2453,
	2409, 2365, 2321, 2279, 2238, 2199, 2163, 2122, 2081, 2041, 2002, 1963, 1924,
	1886, 1849, 1811, 1774, 1737, 1699, 1662, 1624, 1585, 1549, 1514, 1479, 1444,
	1410, 1376, 1343, 1310, 1278, 1247, 1216, 1186, 1157, 1129, 1102, 1076, 1051,
	1026, 1002, 978, 955, 932, 909, 887, 865, 843, 821, 799, 777, 755, 735, 716,
	698, 680, 663, 646, 630, 614, 598
};

 code const uint16_t adTable[D_tableSize]={
   122,128,134,141,147,154,161,169,177,185,194,203,213,222,232,242,253,//17 0~16
   264,275,287,300,313,327,342,357,372,388,403,418,432,445,462,479,496,515,//35  17~34
   535,556,578,600,624,647,671,695,719,742,763,789,814,840,866,893,919,946,973,//54 35~53
   1001,1029,1058,1088,1118,1150,1183,1214,1246,1278,1311,1344,1377,1411,1445,1479,//70 54~69
   1513,1547,1581,1615,1648,1682,1714,1746,1778,1810,1842,1874,1906,1938,1971,2004,//86 70~85
   2037,2071,2105,2140,2176,2210,2242,2274,2305,2336,2367,2397,2427,2457//,2481//101 86~100
   };
 */
//=============================================================================
void GetTemp(void)
{
//var
	static uint16_t adFilterResult = 2200;  //39K
	uint16_t adCurResult;
	uint8_t head, middle, end;

//code
	P3MODL |= 0xc0;  //ad0=P3.3
	CHSEL = CHSEL & 0x0F;   //AD0	p3.3
	OPTION = 0x04;   //ADC Clock Rate 10: SYSCLK/16
	CLRWDT = 1;
	ADSOC = 1;
	_nop_();
	_nop_();
	while (ADSOC) {
	}
	adCurResult = ADCDH;
	adCurResult <<= 4;
	head = ADTKDT;
	head >>= 4;
	adCurResult += head;
	if (adCurResult <= D_shortValue) {
		bAdShort = 1;
		bAdOff = 0;
		bKettleValid = 0;
		padInvalidTimer1 = D_padInvalidTime1;
		padInvalidTimer2 = D_padInvalidTime2;
		return;
	}else {
		bAdShort = 0;
		if (adCurResult >= D_offValue) {
			bAdOff = 1;
			bKettleValid = 0;
			padInvalidTimer2 = D_padInvalidTime2;
			padInvalidTimer1 = D_padInvalidTime1;
			curTemp = 56;
			return;
		}else {
			bAdOff = 0;
			if (bKettleValid == 0) {
				bTestWaterLevel = 1;
				testWaterLowCounter = 0;
				testWaterCounter = 0;
				padInvalidTimer2 = D_padInvalidTime2;
				padInvalidTimer1 = D_padInvalidTime1;
			}
			bKettleValid = 1;
			//？？？ AD转换原理未知
			adFilterResult = (adFilterResult * 7 + adCurResult) / 8;
			//adFilterResult = adCurResult;
			//二分查找 对应AD值的数组下标 即 温度
			head = 0;
			end = D_tableSize - 1;
			middle = (head + end) / 2;
			
			while (head != end) {
				if (adFilterResult < adTable[middle]) {
					head = middle + 1;
					middle = (head + end) / 2;
				}else {
					if (adFilterResult > adTable[middle]) {              //
						end = middle;
						middle = (head + end) / 2;
					}else {
						// ==
						break;
					} //end if
				}// end if
			}//end while
			curTemp = middle ;
			if (curTemp >= 100) {
				curTemp = 99;
			}
			
		//	curTemp = 78;
			// if (curTemp >= 45) {
			//  waterLowAdThreshold = D_waterLowAd - 300;
			//  if (curTemp >= 80) {
			//      waterLowAdThreshold = D_waterLowAd - 1600;
			//  }
			// }else {
			//  waterLowAdThreshold = D_waterLowAd;
			// }
			waterLowAdThreshold = D_waterLowAd;
		}
	}
}
//=============================================================================
void TestWaterLevel()
{
	uint16_t adWaterLevel;
	uint8_t tmp;

//code
	P3MODL |= 0xc0;  //ad0=P3.3
	CHSEL = D_swChannel;   //AD0
	OPTION = 0x04;   //ADC Clock Rate 10: SYSCLK/16
	CLRWDT = 1;
	ADSOC = 1;
	_nop_();
	_nop_();
	while (ADSOC) {
	}
	adWaterLevel = ADCDH;
	adWaterLevel <<= 4;
	tmp = ADTKDT;
	tmp >>= 4;
	adWaterLevel += tmp;
	testWaterCounter++;
	if (adWaterLevel >= waterLowAdThreshold) {
		testWaterLowCounter++;
	}
	if (testWaterCounter >= D_testWaterCount) {
		if (testWaterLowCounter >= D_testWaterLowCount) {
			bWaterLow = 1;
		}else {
			bWaterLow = 0;
		}
		bTestWaterLevel = 0;
		testWaterCounter = 0;
		testWaterLowCounter = 0;
	}
}
