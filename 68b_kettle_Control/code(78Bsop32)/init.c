#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  F_clearWDT();
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
	//P3_4端口开漏
	P3_4 = 1;
	//P3_2端口开漏
	P3_2 = 1;
	//P1_7端口开漏
	P1_2 = 1;
	P1_7 = 1;
  STPPCK = 0;
  STPFCK = 0;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  SELFCK = 1;
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  _nop_();
  // IO 模式初始化
  P1MODL = 0xa8; 
	P1MODH = 0xa2;
  // IO 状态初始化

  // T2 初始化  7.3728Mhz/2 = 3686400Hz
  //  3686400Hz/3686.4 = 1000Hz = 1ms timer2 interrupt
  TH2 = (65536 - 922) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 922) % 256;
  RCP2L = TL2;
  TR2 = 1;
  ET2 = 1;
  EA = 1;
  BuzzCount(500);
}
//=============================================================================
void VarsInit() {}