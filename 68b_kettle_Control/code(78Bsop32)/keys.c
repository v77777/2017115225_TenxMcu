#define __keys_c
#include "includeAll.h"
//=============================================================================
void GetKeys() {
	int delay = 0;
  static uint8_t tempKeyValue = D_keyNull;

  if (P_key1 == 0||P_key2 == 0||P_key3 == 0||P_key4 == 0) {
    tempKeyValue = D_keyValue1;
    
  } else {
    keyValue = tempKeyValue;
    tempKeyValue = D_keyNull;
  }
	
	if(P_key4 == 0){key4 = 0;}
	
	
}

void GetKey1(){
	if(P_key1 == 0){key3 = 0;}
}

void GetKey2(){
	if(P_key2 == 0&& key_flag == 1){
		if((i+10)<100){	i=i+10;}
		else{i=99;}
		key_flag = 0;
	}
}


void GetKey3(){
	if(P_key3 == 0 && key_flag == 1){
		if((i-10)>0){ i = i - 10;}
		else{ i = 0; }
		key_flag = 0;
	}
}