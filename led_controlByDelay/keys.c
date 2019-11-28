#define __keys_c
#include "includeAll.h"
//=============================================================================
void DelayMs(uint16_t msCount) {
  uint16_t i, j;
  for (i = 0; i < msCount; i++) {
    for (j = 0; j < 1000; j++) {
      /* code */
      F_clearWDT();
    }
  }
}

void GetKeys() {
  static uint8_t tempKeyValue = D_keyNull;

  DelayMs(5);
  if (P_key1 == 0) {
    tempKeyValue = D_keyValue1;
  } else {
    keyValue = tempKeyValue;
    tempKeyValue = D_keyNull;
  }
}
