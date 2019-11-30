#define __init_c
#include "includeAll.h"
//=============================================================================
void SysInit() {
  F_clearWDT();
  //时钟初始化
  CLKCON = 0x03; // Clock div 1  7.3728Mhz
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
  P1MODL = 0xaa;
  P1_0 = 1;
  // IO 状态初始化

  // T2 初始化  7.3728Mhz/2 = 3686400Hz
  //  3686400Hz/3686.4 = 1000Hz = 1ms timer2 interrupt
  //每一次脉冲TH寄存器+1 到65535时 产生一次中断并进入 irc.c中的中断函数中执行，然后TH寄存器根据RCP2寄存器数据重置
  TH2 = (65536 - 3686) / 256;
  RCP2H = TH2;
  TL2 = (65536 - 3686) % 256;
  RCP2L = TL2;
  TR2 = 1;  //时钟2作为外部计数器运行
  ET2 = 1;  //允许中断
  EA = 1;   //开启中断允许
}
//=============================================================================
void VarsInit() {}