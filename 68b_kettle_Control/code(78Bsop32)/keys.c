#define __keys_c
#include "includeAll.h"
//=============================================================================
void GetKeys() {
	
  static uint8_t tempKeyValue = D_keyNull;

  if (P_key1 == 0||P_key2 == 0||P_key3 == 0||P_key4 == 0) {
    tempKeyValue = D_keyValue1;
    
  } else {
    keyValue = tempKeyValue;
    tempKeyValue = D_keyNull;
  }
	
	if(P_key4 == 0){
		key4 = 0;
	}
	if(P_key2 == 0){
		key3 = 0;
	}
	if(P_key1 == 0){
		i=i+10;
	}
}