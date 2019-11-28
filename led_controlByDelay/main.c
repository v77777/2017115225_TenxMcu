#define __main_c
#include "includeAll.h"

//=============================================================================
void main() {
  SysInit();
  VarsInit();
  F_ledOn();
  //使能看门狗
  F_turnOnWDT();
  while (1) {
    //喂狗
    F_clearWDT();
    GetKeys();
    if (D_keyValue1 == keyValue) {
      F_ledNeg();
    }
    keyValue = D_keyNull;
  }
}
//=============================================================================

