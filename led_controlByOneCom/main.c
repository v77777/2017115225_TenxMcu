#define __main_c
#include "includeAll.h"
int modeValue = 1;
//=============================================================================
void main() {

  SysInit();
  VarsInit();
  //使能看门狗
  F_turnOnWDT();

  while (1) {
    //喂狗
    F_clearWDT();
    //业务代码
    TimeProcess();
    TaskSetting();
  }
}
//=============================================================================
void TimeProcess() {

static uint8_t timer5ms = 0;


  if (b1ms) {
    // 1ms 执行一次
    b1ms = 0;
    timer5ms++;
  }
  if (timer5ms >= 5) {
		P1MODL = 0xa8;//将模式置为上拉输入,感知按键是否按下，只要处理时间够短，不影响LED显示
    	GetKeys();
  }
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
	 // delayMs(1000);
    if (modeValue == 1){//模式标志为1时，该模式为推挽输出
		//LED状态转换
		if(D_keyValue1 == keyValue){
			modeValue = ~modeValue;		//模式标志为取反
		}
		P1MODL = 0xaa;		//将模式置为推挽输出，使LED显示
		}
	else {
	//否则，该模式为上拉输入
			if(D_keyValue1 == keyValue){
				modeValue = ~modeValue;	
			}
		}
}
//=============================================================================
void DisplayProcess() {
}
