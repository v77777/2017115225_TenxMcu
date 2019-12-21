#define __display_c
#include "includeAll.h"
code const uint8_t displayFonts[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F };

void DisplayLED12(){
	P1_0 = 0;
	P1_4 = 0;
	P1_2 = 1;

}

void DisplayLED14(){

	P1_0 = 0;
	P1_4 = 1;
	P1_2 = 0;

}

void DisplayTenNumber(uint8_t number){
	uint8_t temp1,temp2,temp3,temp4;
	uint8_t i = 0,l=1,delay=4;
	temp1 = P1MODH;
	temp2 = P3MODL;
	temp3 = P3MODH;
	temp4 = P1MODL;
	//1.7
	P1MODH = 0xAA;
	//3.2
	P3MODL = 0xAA;
	//3.4
	P3MODH = 0x2A;
	//1.2
	P1MODL = 0xAA;
	
	P1_6 = 0;
	P1_1 = 1;
	

	P1_3 = 0;
	for(i=0;i<delay;i++);
	P1_4 = 0;
	for(i=0;i<delay;i++);
	P3_4 = 0;
	for(i=0;i<delay;i++);
	P3_5 = 0;
	for(i=0;i<delay;i++);
	P1_7 = 0;
	for(i=0;i<delay;i++);
	P3_6 = 0;
	for(i=0;i<delay;i++);
	P1_2 = 0;
	for(i=0;i<delay;i++);
	P3_2 = 0;
	for(i=0;i<delay;i++);

	
	P1_4 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);
	P3_4 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);
	P3_5 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);
	P1_7 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);
	P3_6 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);
	P1_2 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);
	P3_2 = displayFonts[number]&l;
	for(i=0;i<delay;i++);
	P1MODH = temp1;
	P3MODL = temp2;
	P3MODH = temp3;
	P1MODL = temp4;

}

void DisplayBitNumber(uint8_t number){
	uint8_t temp1,temp2,temp3,temp4;
	uint8_t  i=0,l=1,delay = 4;
	temp1 = P1MODH;
	temp2 = P3MODL;
	temp3 = P3MODH;
	temp4 = P1MODL;
	//1.7
	P1MODH = 0xAA;
	//3.2
	P3MODL = 0xAA;
	//3.4
	P3MODH = 0x2A;
	//1.2
	P1MODL = 0xAA;
	
	P1_6 = 1;
	P1_1 = 0;
	
	P1_3 = 0;
	for(i=0;i<delay;i++);
	P1_4 = 0;
	for(i=0;i<delay;i++);
	P3_4 = 0;
	for(i=0;i<delay;i++);
	P3_5 = 0;
	for(i=0;i<delay;i++);
	P1_7 = 0;
	for(i=0;i<delay;i++);
	P3_6 = 0;
	for(i=0;i<delay;i++);
	P1_2 = 0;
	for(i=0;i<delay;i++);
	P3_2 = 0;
	for(i=0;i<delay;i++);

	
	P1_4 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);

	P3_4 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);

	P3_5 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);

	P1_7 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);

	P3_6 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);

	P1_2 = displayFonts[number]&l;
	l=l*2;
	for(i=0;i<delay;i++);

	P3_2 = displayFonts[number]&l;
	for(i=0;i<delay;i++);


	P1MODH = temp1;
	P3MODL = temp2;
	P3MODH = temp3;
	P1MODL = temp4;


}

void DisplayClear(){
	uint8_t temp1,temp2,temp3,temp4;
	uint8_t i = 0,l=1,delay = 2;
	temp1 = P1MODH;
	temp2 = P3MODL;
	temp3 = P3MODH;
	temp4 = P1MODL;
	//1.7
	P1MODH = 0xAA;
	//3.2
	P3MODL = 0xAA;
	//3.4
	P3MODH = 0x2A;
	//1.2
	P1MODL = 0xAA;
	
	P1_3 = 0;
	for(i=0;i<delay;i++);
	P1_4 = 0;
	for(i=0;i<delay;i++);
	P3_4 = 0;
	for(i=0;i<delay;i++);
	P3_5 = 0;
	for(i=0;i<delay;i++);
	P1_7 = 0;
	for(i=0;i<delay;i++);
	P3_6 = 0;
	for(i=0;i<delay;i++);
	P1_2 = 0;
	for(i=0;i<delay;i++);
	P3_2 = 0;
	for(i=0;i<delay;i++);
	
	P1MODH = temp1;
	P3MODL = temp2;
	P3MODH = temp3;
	P1MODL = temp4;
	for(i=0;i<10000;i++);
}

void DisplayNumber(uint8_t number)
{
	uint8_t i,j;
	if(number>100)
		return;

	j = number % 10;
	DisplayBitNumber(j);

	i = (number - j)/10;
	DisplayTenNumber(i);

}