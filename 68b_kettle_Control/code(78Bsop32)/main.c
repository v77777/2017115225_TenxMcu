/****************************************************************************
����ܽ�����ʾǰ��Ҫ������Ӱ ������������ܶ˿���0 
���������ᵼ�� 1_2�˿ڿ��Ƶ� LED�� ����Ϩ��״̬
��TimeProcess()�� if(b1ms)����� P1_2 = 0 ��ʱLED������ʾ
���Ƿ��ְ�������ʧ��


****************************************************************************/
#define __main_c
#include "includeAll.h"
int modeValue = 1;
int i = 20;
int j = 10;
int flag = 0;
//=============================================================================
void main() {
	
  SysInit();
  VarsInit();
  InitTriac();
  //ʹ�ܿ��Ź�
  F_turnOnWDT();
	led12 = 0;
	led14 = 0;
	P1_0 = 0;          // ��©���״̬ �� ����λΪ0 ʱ��
	P1_4 = 0;
	P1_2 = 0;
	P1MODH = 0xaa;     //�������״̬���Ʒ�����
  while (1) {
    //ι��
    F_clearWDT();
    TimeProcess();
    TaskSetting();
    DisplayNumber(i);

  }
}
//=============================================================================
void TimeProcess() {
  static uint8_t timer5ms = 0;
  static uint16_t second = 0;
	uint16_t temp1,temp2,temp3,temp4;
  if (b1ms) {
    // 1ms ִ��һ��
    b1ms = 0;
    timer5ms++;
    second++;
}
  if (timer5ms >= D_5ms) {
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
  if (second >= D_1000ms) {
      second = 0;

  }
}
//=============================================================================
void TaskProcess() {}
//=============================================================================
void TaskSetting() {
    if (modeValue == 1){//ģʽ��־Ϊ1ʱ����ģʽΪ�������
		//LED״̬ת��
		if(D_keyValue1 == keyValue){
			modeValue = ~modeValue;		//ģʽ��־Ϊȡ��
			led12 = ~led12;
			P1_0 = ~P1_0;
			i = i+30;
		}
		//P1MODL = P1MODL|0x20;		//��ģʽ��Ϊ���������ʹLED��ʾ
		
		}
	else {
	//���򣬸�ģʽΪ��������
			if(D_keyValue1 == keyValue){
				modeValue = ~modeValue;	
				P1_0 = ~P1_0;
				led12 = ~led12;
				P1_0 = ~P1_0;
			}
		}
}
//=============================================================================
void DisplayProcess() {
	DisplayLED12();
	DisplayLED14();
}