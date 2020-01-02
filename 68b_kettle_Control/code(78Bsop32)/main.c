/****************************************************************************
数码管交替显示前需要消除残影 即将所有数码管端口置0 
但是这样会导致 1_2端口控制的 LED灯 处于熄灭状态
在TimeProcess()的 if(b1ms)中添加 P1_2 = 0 此时LED正常显示
但是发现按键控制失常


****************************************************************************/
#define __main_c
#include "includeAll.h"
int modeValue = 1;
int j = 10;
int k = 0;
int flag = 0;

//=============================================================================
void main() {

	key4 = 1;
	key3 = 1;
	i = 25;
  SysInit();
  VarsInit();
  InitTriac();
  //使能看门狗
  F_turnOnWDT();
	led12 = 0;
	led14 = 0;
	P1_0 = 0;          // 开漏输出状态 且 数据位为0 时点
	P1_4 = 0;
	P1_2 = 0;
	P1MODH = 0xaa;     //推挽输出状态控制蜂鸣器
  while (1) {
  	while(key4){
  		F_clearWDT();
			TimeProcess();
  		DisplayOn(1);
		}
		
		while(key3){
  		F_clearWDT();
			TimeProcess();
  		DisplayNumber(i);		
			//for(k=0;k<5000;k++);
			//TaskSetting();
		}
		
    //喂狗
    F_clearWDT();
    TimeProcess();
    //TaskSetting();
  //  DisplayNumber(curTemp);
  }
}
//=============================================================================
void TimeProcess() {
  static uint8_t timer5ms = 0;
	static uint8_t timer100ms = 0;
  static uint16_t second = 0;
	uint16_t temp1,temp2,temp3,temp4;
	
	
  if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
		timer100ms++;
    second++;
}
  if (timer5ms >= D_5ms) {
		timer5ms = 0;
/*	temp1 = P1MODL;
	temp2 = P1MODH;
	temp3 = P3MODL;
	temp4 = P3MODH;
	
	//1.7
	P1MODH = 0x00;
	//3.2
	P3MODL = 0x00;
	//3.4
	P3MODH = 0x00;
	//1.2
	P1MODL = 0x00;
	//SysInit();
	//P3_4????
	P3_4 = 1;
	P3_2 = 1;
	//P1_7????*/
	P1_2 = 1;
	P1_7 = 1;
	P1MODL = P1MODL&0xCF;
  GetKeys();
	P1_2 = 0;
	P1_7 = 0;
	
	/*P3_4 = 0;
	P3_2 = 0;
	P1MODL = temp1;
	P1MODH = temp2;
	P3MODL = temp3;
	P3MODH = temp4;*/
  }
	
	if (timer100ms >= 100) {
		timer100ms = 0;
		GetTemp();
	}
	
  if (second >= D_1000ms) {
    second = 0;
  }
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
    if (modeValue == 1){
		if(D_keyValue1 == keyValue){
			modeValue = ~modeValue;		//模式标志为取反
			led12 = ~led12;
			P1_0 = ~P1_0;
			i = i+10;
			//DisplayProcess();
		}
		//P1MODL = P1MODL|0x20;		//将模式置为推挽输出，使LED显示
		
		}
	else {
	//否则，该模式为上拉输入
			if(D_keyValue1 == keyValue){
				modeValue = ~modeValue;	
				P1_0 = ~P1_0;
				led12 = ~led12;
				P1_0 = ~P1_0;
				DisplayProcess();
			}
		}
}
//=============================================================================
void DisplayProcess() {
	SysInit();
  VarsInit();
  InitTriac();
  //使能看门狗
  F_turnOnWDT();
	led12 = 0;
	led14 = 0;
	P1_0 = 0;          // 开漏输出状态 且 数据位为0 时点
	P1_4 = 0;
	P1_2 = 0;
	P1MODH = 0xaa;     //推挽输出状态控制蜂鸣器
	//DisplayClear();
}