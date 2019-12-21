/*
******************************************************************************************************
Name		:TM52M5268B_64B.h
Version		:V1.1
Author		:
Date		:2015.08.06
Modify      :2.PWM1RPD -> PWM1PRD
             1.TT0 -> IT0
******************************************************************************************************
*/
#ifndef __TM52F5268_H__
#define __TM52F5268_H__

sfr     P0      =0x80;
sbit    P0_3    = P0^3;
sbit    P0_2    = P0^2;			  
sbit    P0_1    = P0^1;
sbit    P0_0    = P0^0;


sfr     SP      =0x81;
sfr     DPL     =0x82;
sfr     DPH     =0x83;
sfr     PCON    =0x87;
	//--------------------------------------------------------------------------------------------
	#define 	SMOD	0x80		//波特率倍增位
	//--------------------------------------------------------------------------------------------
	//--------------------------------------------------------------------------------------------
	#define 	GF1		0x08		//用户可以随便使用
	#define 	GF0		0x04		//用户可以随便使用
	//--------------------------------------------------------------------------------------------
	#define 	PD		0x02		//此位置1,芯片进入PD模式
	//--------------------------------------------------------------------------------------------
	#define 	IDL		0x01		//此位置1,芯片进入IDL模式

//---------------------------
sfr     TCON    =0x88;
sbit    TF1     =TCON^7;
sbit    TR1     =TCON^6;
sbit    TF0     =TCON^5;
sbit    TR0     =TCON^4;
sbit    IE1     =TCON^3;
sbit    IT1     =TCON^2;
sbit    IE0     =TCON^1;
sbit    IT0     =TCON^0;

sfr     TMOD    =0x89;
	//--------------------------------------------------------------------------------------------
	#define 	T1Mask		0xf0		//T1工作模式选择Mask
	//--------------------------------------------------------------------------------------------
	#define 	GATE1		0x80		//定时器1操作开关控制位
					 	 	//当GATE1=1时,INT1引脚为高电平,同时TCON中的TR1控制位为1时,计时/计数器1才开始工作
					 	 	//当GATE1=0时,则只要将TR1控制位设为1，计时/计数器1就开始工作
	#define 	CT1		0x40		//定时/计数器1功能的选择位
					 	 	//CT1=1为计数器,通过外部引脚T1输入计数脉冲
					 	 	//CT1=0为定时器,由内部系统时钟提供计时工作脉冲
	//--------------------------------------------------------------------------------------------
	#define 	T1M0		0x00		//T1为13位计时/计数器
	#define 	T1M1		0x10		//T1为16位计时/计数器
	#define 	T1M2		0x20		//T1为8位自动加载计数/计时器 
	#define 	T1M3		0x30		//不存在
	//--------------------------------------------------------------------------------------------
	#define 	T0Mask		0x0f		//T0工作模式选择Mask
	//--------------------------------------------------------------------------------------------
	#define 	GATE0		0x08		//定时器0操作开关控制位
					 	 	//当GATE0=1时,INT0引脚为高电平,同时TCON中的TR0控制位为1时,计时/计数器0才开始工作
					 	 	//当GATE0=0时,则只要将TR0控制位设为1，计时/计数器0就开始工作
	#define 	CT0		0x04		//定时/计数器0功能的选择位
					 	 	//CT0=1为计数器,通过外部引脚T0输入计数脉冲
					 	 	//CT0=0为定时器,由内部系统时钟提供计时工作脉冲
	//--------------------------------------------------------------------------------------------
	#define 	T0M0		0x00		//T0为13位计时/计数器 
	#define 	T0M1		0x01		//T0为16位计时/计数器 
	#define 	T0M2		0x02		//T0为8位自动加载计数/计时器
	#define 	T0M3		0x03		//仅适用于T0,T0分为两个独立的8位定时器/计数器TH0及TL0,在此模式下T1停止工作
sfr     TL0     =0x8a;
sfr     TL1     =0x8b;
sfr     TH0     =0x8c;
sfr     TH1     =0x8d;
//---------------------------
sfr     P1      =0x90;
sbit    P1_7    = P1^7;
sbit    P1_6    = P1^6;
sbit    P1_5    = P1^5;
sbit    P1_4    = P1^4;
sbit    P1_3    = P1^3;
sbit    P1_2    = P1^2;			  
sbit    P1_1    = P1^1;
sbit    P1_0    = P1^0;
/*
******************************************************************************************************
*/
sfr		P0OE		= 0x91;				//P0 CMOS Push-Pull Output Enable (1=Enable)

/*
******************************************************************************************************
*/
sfr		P2MOD		= 0x93;				//P2  
	//--------------------------------------------------------------------------------------------
	//P2MOD1:P2MOD Bit[3:2],P2.1 Pin Mode Control
	#define		P21MOD_Mask		~0xc0
	#define		P21MOD_0		0x00
	#define		P21MOD_1		0x40
	#define		P21MOD_2		0x80
	#define		P21MOD_3		0xC0
	//--------------------------------------------------------------------------------------------
	//P2MOD0:P2MOD Bit[1:0],P2.0 Pin Mode Control
	#define		P20MOD_Mask		~0x03
	#define		P20MOD_0		0x00
	#define		P20MOD_1		0x01
	#define		P20MOD_2		0x02
	#define		P20MOD_3		0x03
/*
******************************************************************************************************
*/
sfr     OPTION  =0x94;
	//--------------------------------------------------------------------------------------------
	#define 	UART1W		0x80		//One wire UART, both TXD/RXD use P3.1 pin
	//--------------------------------------------------------------------------------------------
	#define 	MODE3 		0x40		//mode 3v
	//--------------------------------------------------------------------------------------------
	#define 	WDTPSC_0	0x30		//Watch Dog Timer Prescale 3=Fastest
	#define 	WDTPSC_1	0x20		//Watch Dog Timer Prescale
	#define 	WDTPSC_2	0x10		//Watch Dog Timer Prescale
	#define 	WDTPSC_3	0x00		//Watch Dog Timer Prescale
	//--------------------------------------------------------------------------------------------
	#define 	AdcClk_32	0x00		//ADC Clock Rate:SysClk/32
	#define 	AdcClk_16	0x04		//ADC Clock Rate:SysClk/16
	#define 	AdcClk_8	0x08		//ADC Clock Rate:SysClk/8
	#define 	AdcClk_4	0x0C		//ADC Clock Rate:SysClk/4
	//--------------------------------------------------------------------------------------------
	#define 	TM3Psc_32768	0x00		
	#define 	AdcClk_16384	0x01		
	#define 	AdcClk_8192	0x02		
	#define 	AdcClk_128	0x03
sfr     INTFLG  =0x95;
	//--------------------------------------------------------------------------------------------
	#define		LVD		0x80		//Low Voltage Detect Flag
	//--------------------------------------------------------------------------------------------
	#define		TKIF	0x20		//Touch Key 中断标志，HW clear while TKSOC set
	//--------------------------------------------------------------------------------------------
	#define		ADIF	0x10		//ADC 中断标志，HW clear while ADSOC set
	//--------------------------------------------------------------------------------------------
	#define		IE2		0x04		//INT2 中断标志，1=外部中断2中断
	//--------------------------------------------------------------------------------------------
	#define 	P1IF	0x02		//P1端口中断标志，1=P1端口中断
	//--------------------------------------------------------------------------------------------
	#define 	TF3		0x01		//TM3中断标志,1=TM3中断
sfr     P1WKUP  =0x96;
/*
******************************************************************************************************
*/
sfr		SWCMD		= 0x97;

//---------------------------
sfr     SCON    =0x98;
	//--------------------------------------------------------------------------------------------
	sbit 		SM0 		= SCON^7;	//串行口工作方式控制位
	sbit 		SM1 		= SCON^6;	//[SM0:SM1]=
					 	 	//00 方式0－波特率由振荡器频率所定:振荡器频率/12
					 	 	//01 方式1－波特率由定时器T1或T2的溢出率和SMOD所定:2SMOD*(T1溢出率)/32
					 	 	//10 方式2－波特率由振荡器频率和SMOD所定:2SMOD*振荡器频率/64
					 	 	//11 方式3－波特率由定时器T1或T2的溢出率和SMOD所定:2SMOD*(T1溢出率)/32
	//--------------------------------------------------------------------------------------------
	sbit 		SM2 		= SCON^5;	//多机通信控制位*/
							//多机通信是工作于方式2和方式3，SM2位主要用于方式2和方式3接收状态
					 	 	//当串行口工作于方式2或3:
					 	 	//当SM2=1时,只有当接收到第9位数据(RB8)为1时,才把接收到的前8位数据送入SBUF,且置位RI发出中断申请,否则会将接收到的数据放弃
					 	 	//当SM2=0时,就不管第9位数据是0还是1,都得数据送入SBUF,并发出中断申请,工作于方式0时，SM2必须为0
	//--------------------------------------------------------------------------------------------
	sbit 		REN 		= SCON^4;	//允许接收位:
					 	 	//REN用于控制数据接收的允许和禁止,REN=1时,允许接收,REN=0时,禁止接收
	//--------------------------------------------------------------------------------------------
	sbit 		TB8 		= SCON^3;	//发送数据第8位
	sbit 		RB8 		= SCON^2;	//接收数据第8位
	//--------------------------------------------------------------------------------------------
	sbit 		TI 		= SCON^1;	//发送中断标志位：
					 	 	//方式0时,发送完第8位数据后,由硬件置位
					 	 	//其它方式下,由硬件置位,TI=1表示帧发送结束,TI可由软件清零
	//--------------------------------------------------------------------------------------------
	sbit 		RI 		= SCON^0;	//接收中断标志位：
					 	 	//方式0时,接收完第8位数据后,由硬件置位
					 	 	//其它方式下,由硬件置位,RI=1表示帧接收完成
	
sfr     SBUF    =0x99;
sfr     PWM0PRD =0x9a;
sfr     PWM0DH  =0x9b;
sfr     PWM1PRD =0x9c;
sfr     PWM1DH  =0x9d;

//---------------------------
sfr     P2      =0xa0;
sbit    P2_1    = P2^1;
sbit    P2_0    = P2^0;

sfr     PWMCON  =0xa1;
	//--------------------------------------------------------------------------------------------
	#define		PWM1CKS_16M	0xC0		//PWM1 clock =FRC Double frequence
	#define		PWM1CKS_Div1	0x80            //PWM1 clock =SysClk/1
	#define		PWM1CKS_Div2	0x40            //PWM1 clock =SysClk/2
	#define		PWM1CKS_Div4	0x00            //PWM1 clock =SysClk/4
	//--------------------------------------------------------------------------------------------
	// PWM1DL  (bit5~bit4) 
	//--------------------------------------------------------------------------------------------                                              //
	#define		PWM0CKS_16M		0x0C		//PWM0 clock =FRC Double frequence
	#define		PWM0CKS_Div1	0x08            //PWM0 clock =SysClk/1
	#define		PWM0CKS_Div2	0x04            //PWM0 clock =SysClk/2
	#define		PWM0CKS_Div4	0x00            //PWM0 clock =SysClk/4
sfr     P1MODL  =0xa2;
	//--------------------------------------------------------------------------------------------
	//P1MOD3:P1MODL Bit[7:6],P1.3 Pin Mode Control
	#define		P13MOD_Mask		~0xc0
	#define		P13MOD_0		0x00
	#define		P13MOD_1		0x40
	#define		P13MOD_2		0x80
	#define		P13MOD_3		0xC0
	//--------------------------------------------------------------------------------------------
	//P1MOD2:P1MODL Bit[5:4],P1.2 Pin Mode Control
	#define		P12MOD_Mask		~0x30
	#define		P12MOD_0		0x00
	#define		P12MOD_1		0x10
	#define		P12MOD_2		0x20
	#define		P12MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P1MOD1:P1MODL Bit[3:2],P1.1 Pin Mode Control
	#define		P11MOD_Mask		~0x0C
	#define		P11MOD_0		0x00
	#define		P11MOD_1		0x04
	#define		P11MOD_2		0x08
	#define		P11MOD_3		0x0C
	//--------------------------------------------------------------------------------------------
	//P1MOD0:P1MODL Bit[1:0],P1.0 Pin Mode Control
	#define		P10MOD_Mask		~0x03
	#define		P10MOD_0		0x00
	#define		P10MOD_1		0x01
	#define		P10MOD_2		0x02
	#define		P10MOD_3		0x03
sfr     P1MODH  =0xa3;
	//--------------------------------------------------------------------------------------------
	//P1MOD7:P1MODH Bit[7:6],P1.7 Pin Mode Control
	#define		P17MOD_Mask		~0xc0
	#define		P17MOD_0		0x00
	#define		P17MOD_1		0x40
	#define		P17MOD_2		0x80
	#define		P17MOD_3		0xc0
	//--------------------------------------------------------------------------------------------
	//P1MOD6:P1MODH Bit[5:4],P1.6 Pin Mode Control
	#define		P16MOD_Mask		~0x30
	#define		P16MOD_0		0x00
	#define		P16MOD_1		0x10
	#define		P16MOD_2		0x20
	#define		P16MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P1MOD5:P1MODH Bit[3:2],P1.5 Pin Mode Control
	#define		P15MOD_Mask		~0x0c
	#define		P15MOD_0		0x00
	#define		P15MOD_1		0x04
	#define		P15MOD_2		0x08
	#define		P15MOD_3		0x0c
	//--------------------------------------------------------------------------------------------
	//P1MOD4:P1MODH Bit[1:0],P1.4 Pin Mode Control
	#define		P14MOD_Mask		~0x03
	#define		P14MOD_0		0x00
	#define		P14MOD_1		0x01
	#define		P14MOD_2		0x02
	#define		P14MOD_3		0x03
sfr     P3MODL  =0xa4;
	//--------------------------------------------------------------------------------------------
	//P3MOD3:P3MODL Bit[7:6],P3.3 Pin Mode Control
	#define		P33MOD_Mask		~0xc0
	#define		P33MOD_0		0x00
	#define		P33MOD_1		0x40
	#define		P33MOD_2		0x80
	#define		P33MOD_3		0xc0
	//--------------------------------------------------------------------------------------------
	//P3MOD2:P3MODL Bit[5:4],P3.2 Pin Mode Control
	#define		P32MOD_Mask		~0x30
	#define		P32MOD_0		0x00
	#define		P32MOD_1		0x10
	#define		P32MOD_2		0x20
	#define		P32MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P3MOD1:P3MODL Bit[3:2],P3.1 Pin Mode Control
	#define		P31MOD_Mask		~0x0c
	#define		P31MOD_0		0x00
	#define		P31MOD_1		0x04
	#define		P31MOD_2		0x08
	#define		P31MOD_3		0x0c
	//--------------------------------------------------------------------------------------------
	//P3MOD0:P3MODL Bit[1:0],P3.0 Pin Mode Control
	#define		P30MOD_Mask		~0x03
	#define		P30MOD_0		0x00
	#define		P30MOD_1		0x01
	#define		P30MOD_2		0x02
	#define		P30MOD_3		0x03
sfr     P3MODH  =0xa5;	
	//--------------------------------------------------------------------------------------------
	//T0OE:P3MODH Bit[7],"Timer0 overflow divided by 64"signal output to P3.4 pin
	#define		T0OE    		0x80
	//--------------------------------------------------------------------------------------------
	//P3MOD6:P3MODH Bit[5:4],P3.6 Pin Mode Control
	#define		P36MOD_Mask		~0x30
	#define		P36MOD_0		0x00
	#define		P36MOD_1		0x10
	#define		P36MOD_2		0x20
	#define		P36MOD_3		0x30
	//--------------------------------------------------------------------------------------------
	//P3MOD5:P3MODH Bit[3:2],P3.5 Pin Mode Control
	#define		P35MOD_Mask		~0x0c
	#define		P35MOD_0		0x00
	#define		P35MOD_1		0x04
	#define		P35MOD_2		0x08
	#define		P35MOD_3		0x0c
	//--------------------------------------------------------------------------------------------
	//P3MOD4:P3MODH Bit[1:0],P3.4 Pin Mode Control
	#define		P34MOD_Mask		~0x03
	#define		P34MOD_0		0x00
	#define		P34MOD_1		0x01
	#define		P34MOD_2		0x02
	#define		P34MOD_3		0x03
sfr     PINMOD  =0xa6;
	#define		PWM1AOE		0x80//Set to enable PWM1A and signal output to P1.3 pin
	#define		PWM0AOE		0x20//Set to enable PWM0A and signal output to P1.2 pin
	#define		TCOE		  0x08//Set to output "Instruction Cycle Clock " signal to P1.4 pin
	#define		T2OE		  0x04//Set to output "Timer2 overflow divided by 2" signal to P1.0 pin
//---------------------------	
sfr     IE      =0xa8;
	//--------------------------------------------------------------------------------------------
	sbit 		EA 			= IE^7;		//EA=0时,所有中断禁止;EA=1时,各中断的产生由个别的允许位决定
	sbit 		ET2 		= IE^5;		//定时器2中断充许
	sbit 		ES 			= IE^4;		//串行口中断充许(ES=1充许,ES=0禁止)
	sbit 		ET1 		= IE^3;		//定时器1中断充许
	sbit 		EX1 		= IE^2;		//外中断INT1中断充许
	sbit 		ET0 		= IE^1;		//定时器0中断充许
	sbit 		EX0 		= IE^0;		//外部中断INT0的中断允许
	
sfr     INTE1   =0xa9;		
    //-------------------------------------------------------------------------------------------------------
	//IAP写使能-->INTE1=(INTE1&~IAPWE_Mask)|IAPWE_En;(仅仅写需要)
	//IAP写禁止-->INTE1=(INTE1&~IAPWE_Mask)|IAPWE_Dis;
	
	#define 	IAPWE_Mask	0xE0
	#define 	IAPWE_En	0xA0
	#define 	IAPWE_Dis	0x00
	//--------------------------------------------------------------------------------------------
	#define		SPIE		0x10		//SPI 中断允许
	//--------------------------------------------------------------------------------------------
	#define		ADTKIE  0x08		//ADC/Touch Key  中断允许
	//--------------------------------------------------------------------------------------------
	#define		EX2			0x04		//INT2 中断允许、Stop Mode 唤醒功能启用
	//--------------------------------------------------------------------------------------------
	#define	  P1IE		0x02		//P1端口中断允许
	//--------------------------------------------------------------------------------------------
	#define		TM3IE		0x01		//TM3中断允许		
sfr     ADTKDT  =0xaa;		
	//--------------------------------------------------------------------------------------------
	//ADCDL:ADTKDT Bit[7:4],ADC Data LSB 3~0
	#define		TKEOC		0x08		//Touch Key End of Conversion
	#define		TKOVF		0x04		//Touch Key Counter Overflow
	//--------------------------------------------------------------------------------------------
	//TKDH:ADTKDT Bit[1:0],Touch Key Data MSB 9~8
sfr     ADCDH   =0xab;
sfr     TKDL    =0xac;
sfr     TKCON   =0xad;
	//--------------------------------------------------------------------------------------------
	//TKPD:TKCON Bit[7],Touch Key Power Down
	#define		TKPD		0x80		//0: Touch Key Running ;1: Touch Key Power Down
	//--------------------------------------------------------------------------------------------
	//TKTMR:TKCON Bit[2:0],Touch Key Conversion Time
	#define		TKTMR_Mask		 ~0x07		//TKTMR_Mask
	#define		TKTMR_short    0x00		  //shortest
//...
	#define		TKTMR_long     0x07		  //longest
sfr     CHSEL   =0xae;
	//--------------------------------------------------------------------------------------------
	//ADCHS:CHSEL Bit[7:4],ADC Channel Select
                 //0000: AD0 (P3.3)
                 //0001: AD1 (P3.2)
                 //0010: AD2 (P3.1)
                 //0011: AD3 (P3.0)
                 //0100: AD4 (P1.0)
                 //0101: AD5 (P1.1)
                 //0110: AD6 (P1.2)
                 //0111: AD7 (P1.3)
                 //1000: AD8 (P1.4)
                 //1001: AD9 (P1.5)
                 //1010: VSS
                 //1011: VBG (Internal Reference Voltage)
                 //11xx: Reserved	
	//--------------------------------------------------------------------------------------------
	//TKCHS:TKCON Bit[3:0],Touch Key Channel Select
                 //0000: TK0 (P1.0)
                 //0001: TK1 (P1.1)
                 //0010: TK2 (P1.2)
                 //0011: TK3 (P1.3)
                 //0100: TK4 (P3.3)
                 //0101: TK5 (P3.2)
                 //0110: TK6 (P3.1)
                 //0111: TK7 (P3.0)
                 //1000: TK8 (P1.4)
                 //1001: TK9 (P1.6)
                 //1010: TK10 (P1.7)
                 //1011: TK11 (P3.6)
                 //1100: TK12 (P3.5)
                 //1101: TK13 (P3.4)
                 //11xx: Reserved
/*
******************************************************************************************************
*/
sfr		TKCON2		= 0xAF;
	//ATKDT:TKCON2 Bit[7:4],Auto Touch Key Scan Result
	//--------------------------------------------------------------------------------------------
	//TKAUTO:TKCON2 Bit[3],Touch Key Auto Scan Mode Enable
	#define		TKAUTO		0x08		//0: Touch Key Running ;1: Touch Key Power Down
	//--------------------------------------------------------------------------------------------
	//TKSCNRT:TKCON2 Bit[2],Touch Key Auto Scan Rate ,0=125mS,1=62mS
	#define		TKSCNRT		0x04		//0=125mS,1=62mS
	//--------------------------------------------------------------------------------------------
	//TKSCNUM:TKCON2 Bit[1:0],Touch Key Auto Scan Number
	#define		TKSCNUM1	0x00		//1 channel
	#define		TKSCNUM4	0x03		//4 channel

//---------------------------
sfr     P3      =0xb0;
sbit    P3_7    = P3^7;
sbit    P3_6    = P3^6;
sbit    P3_5    = P3^5;
sbit    P3_4    = P3^4;
sbit    P3_3    = P3^3;
sbit    P3_2    = P3^2;			  
sbit    P3_1    = P3^1;
sbit    P3_0    = P3^0;

//---------------------------
sfr     IP      =0xb8;
	//--------------------------------------------------------------------------------------------
	sbit		PT2			  = IP^5;		//定时2中断优先级低位
	sbit 		PS			  = IP^4;		//串行口中断优先级低位
	sbit 		PT1	    	= IP^3;		//定时1中断优先级低位
	sbit 		PX1	    	= IP^2;		//外中断INT1中断优先级低位
	sbit 		PT0	    	= IP^1;		//定时0中断优先级低位
	sbit 		PX0	    	= IP^0;		//外中断INT0中断优先级低位

sfr     IPH     =0xb9;
	//--------------------------------------------------------------------------------------------	
	#define	  	PT2H		0x20 		//Timer2中断优先级高位控制
	#define	  	PSH		  0x10 		//串口中断优先级高位控制
	#define	  	PT1H		0x08 		//Timer1中断优先级高位控制
	#define	  	PX1H		0x04 		//XINT1中断优先级高位控制 
	#define	  	PT0H		0x02 		//Timer0中断优先级高位控制
	#define		  PX0H		0x01 		//XINT0中断优先级高位控制
sfr     IP1     =0xba;
	//--------------------------------------------------------------------------------------------
	#define		  PSPI		0x10		//SPI中断优先级低位
	#define	  	PADTKI  0x08		//ADC/Touch Key中断优先低位控制
	#define	  	PX2		  0x04		//XINT2中断优先低位控制
	#define	  	PP1		  0x02		//Port1中断优先低位控制
	#define		  PT3		  0x01		//Timer3中断优先低位控制
sfr     IP1H    =0xbb;
	//--------------------------------------------------------------------------------------------
	#define		  PSPIH 	0x10		//SPI中断优先级高位
	#define 	  PADTKIH	0x08;		//ADC/Touch Key 中断优先级高位
	#define		  PX2H		0x04		//XIN T2中断优先级高位
	#define 	  PP1H		0x02;		//P1中断优先级高位
	#define 	  PT3H    0x01;		//定时3中断优先级高位

/*
******************************************************************************************************
*/
sfr   SPCON     = 0xBC;
	#define		SPCON_Mask	~0xFF		//
	#define		SPEN    0x80		//SPI Enable.0: SPI Enable;1: SPI Disable
	#define		MSTR    0x40 	  //Master Mode Enable.0: Slave Mode;1: Master Mode
	#define		CPOL    0x20	  //SPI Clock Polarity.0: SCK is low in idle state;1: SCK is high in idle state
	#define		CPHA    0x10		//SPI Clock Phase.0: Data sampled on first edge of SCK period;1: Data sampled on second edge of SCK period
	#define		SSDIS   0x08		//Pin Disable.0: Enable   pin;1: Disable   pin
	#define		LSBF    0x04 	  //LSB First.0: MSB first;1: LSB first
	//--------------------------------------------------------------------------------------------
	//SPCR:SPCON Bit[1:0], SPI Clock Rate.
	#define		SPCR_2  0x00	  //FSYSCLK/2
	#define		SPCR_4  0x01	  //FSYSCLK/4
	#define		SPCR_8  0x02	  //FSYSCLK/8
	#define		SPCR_16 0x03	  //FSYSCLK/16
/*
******************************************************************************************************
*/
sfr   SPSTA     = 0xBD;
	#define		SPSTA_Mask	~0xFC		//
	#define		SPIF    0x80		//SPI Interrupt Flag,This bit is set by H/W at the end of a data transfer,Cleared by H/W when interrupt is vectored into
	#define		WCOL    0x40 	  //Write Collision Interrupt Flag,This bit is set by H/W if write data to SPDAT when SPBSY is set.Write 0 to this bit or rewrite data to SPDAT when SPBYS is cleared will clear this flag.
	#define		MODF    0x20	  //Mode Fault Interrupt Flag,This bit is set by H/W when SSDIS is cleared and NSS pin is pulled low in Master mode.Write 0 to this bit will clear this flag.When this bit is set, the SPEN and MSTR in SPCON will be cleared by hardware
	#define		RCVOVF  0x10		//Receive Buffer Overrun Flag,This bit is set by H/W at the end of a data transfer and RCVBF is set.Write 0 to this bit or read SPDAT register will clear this flag.
	#define		RCVBF   0x08		//Receive Buffer Full Flag,This bit is set by H/W at the end of a data transfer.Write 0 to this bit or read SPDAT register will clear this flag.
	#define		SPBSY   0x04 	  //SPI Busy Flag (Read Only),This bit is set by H/W when a SPI transfer is progress.
/*
******************************************************************************************************
*/
sfr   SPDAT     = 0xBE;         //SPI Transmit and Receive Data
/*
******************************************************************************************************
*/
sfr   ATKCMP10H = 0xC2;         //
	//--------------------------------------------------------------------------------------------
	//ATKCMP1:ATKCMP10H Bit[6:4], Auto Touch Key Scan Channel 1 Compare Data bit 10~8.
	//--------------------------------------------------------------------------------------------
	//ATKCMP0:ATKCMP10H Bit[2:0], Auto Touch Key Scan Channel 0 Compare Data bit 10~8.
/*
******************************************************************************************************
*/
sfr   ATKCMP32H = 0xC3;         //
	//--------------------------------------------------------------------------------------------
	//ATKCMP3:ATKCMP32H Bit[6:4], Auto Touch Key Scan Channel 3 Compare Data bit 10~8.
	//--------------------------------------------------------------------------------------------
	//ATKCMP2:ATKCMP32H Bit[2:0], Auto Touch Key Scan Channel 2 Compare Data bit 10~8.
/*
******************************************************************************************************
*/
sfr   ATKCMP0   = 0xC4;         //Auto Touch Key Scan Channel 0 Compare Data bit 7~0.
/*
******************************************************************************************************
*/
sfr   ATKCMP1   = 0xC5;         //Auto Touch Key Scan Channel 1 Compare Data bit 7~0.
/*
******************************************************************************************************
*/
sfr   ATKCMP2   = 0xC6;         //Auto Touch Key Scan Channel 2 Compare Data bit 7~0.
/*
******************************************************************************************************
*/
sfr   ATKCMP3   = 0xC7;         //Auto Touch Key Scan Channel 3 Compare Data bit 7~0.
//---------------------------
sfr     T2CON   =0xc8;
	//--------------------------------------------------------------------------------------------
	sbit 		TF2  	  =	T2CON^7 ;	//TM2溢出中断标志。TF2必须由用户程序清“0”。当TM2作为串口波特率发生器时，TF2不会被置“1”。
	sbit 		EXF2    =	T2CON^6	;	//定时器TM2外部中断标志。EXEN2为1时，当T2EX（P1.1）发生负跳变时置1中断标志EXF2，EXF2必须由用户程序清“0”。
	sbit  	RCLK    =	T2CON^5	;	//串行接口的发送时钟选择标志。TCLK=1时，T2工作于波特率发生器方式。
	sbit  	TCLK 	  =	T2CON^4	;	//串行接口的接收时钟选择标志位。RCLK＝1时，T2工作于波特率发生器方式。
	sbit  	EXEN2   =	T2CON^3	;	//TM2的外部中断充许标志。
	sbit 		TR2     =	T2CON^2	;	//TM2计数/定时控制位。TR2为1时充许计数，为0时禁止计数
	sbit 		CT2     =	T2CON^1	;	//外部计数器/定时器选择位。C/T2=1时，T2为外部事件计数器，计数脉冲来自T2（P1.0）；C/T2=0时，T2为定时器，振荡脉冲的十二分频信号作为计数信号。
	sbit    CPRL2   =	T2CON^0	;	//捕捉和常数自动再装入方式选择位。为1时工作于捕捉方式，为0时TM2工作于常数自动再装入方式。当TCLK或RCLK为1时，CP/RL2被忽略，T2总是工作于常数自动再装入方式。

sfr     RCP2L   =0xca;
sfr     RCP2H   =0xcb;
sfr     TL2     =0xcc;
sfr     TH2     =0xcd;

sfr     PSW     =0xd0;
	//--------------------------------------------------------------------------------------------
	sbit 		CY 		= PSW^7;	//进位标志,有进或借位,CY＝1;无进或借位,CY＝0
	sbit 		AC 		= PSW^6;	//半进位标志
	sbit 		F0 		= PSW^5;	//用户可以随便使用
	sbit 		RS1 	= PSW^4;	//工作寄存器区选择[RS1:RS0]
	sbit 		RS0 	= PSW^3;	//00--0区,01--1区,10--2区,11--3区
	sbit 		OV 		= PSW^2;	//运算结果按补码运算,有溢出,OV=1;无溢出,OV＝0
  sbit    F1    = PSW^1;
	sbit 		P 		= PSW^0;	//用来表示ALU运算结果中二进制数位1的个数的奇偶性,

//---------------------------
sfr     CLKCON  =0xd8;
	//--------------------------------------------------------------------------------------------
	sbit		SCKTYPE		=CLKCON^7;		//Slow Clock Type. 0=SRC, 1=SXT
	sbit		FCKTYPE		=CLKCON^6;		//Fast Clock Type. 0=FRC, 1=FXT
	sbit		STPPCK		=CLKCON^4;		//Stop UART/Timer0/Timer1/Timer2/ADC Clock in Idle mode
	sbit		STPFCK		=CLKCON^3;		//Stop Fast Clock
	sbit		SELFCK      =CLKCON^2;		//Select Fast Clock	
	//--------------------------------------------------------------------------------------------
	#define		CLKPSC_div16 0x00
	#define		CLKPSC_div4	 0x01
	#define		CLKPSC_div2	 0x02
	#define		CLKPSC_div1	 0x03

sfr     ACC     =0xe0;
sfr     B       =0xf0;
sfr     CFGWL   =0xf7;
	//--------------------------------------------------------------------------------------------
	#define 	WDTEMask	0xC0		//
	#define 	WDTE11		0xC0		//WDT总是使能
	#define 	WDTE10		0x80		//WDT使能,但在IDLE/PDOWN模式下禁止
	#define 	WDTE0X		0x00		//WDT总是禁止
	
	
 	#define 	IRCMask		0x0F		//

//---------------------------
sfr     AUX1    =0xf8;
	//--------------------------------------------------------------------------------------------
    sbit 		CLRWDT		= AUX1^7;
    sbit 		CLRTM3		= AUX1^6;//清零TM3也是启动TM3
    sbit 		TKSOC		  = AUX1^5;//触摸键开始，结束时自动清零
    sbit 		ADSOC		  = AUX1^4;//ADC开始，结束时硬件自动清零
    sbit 		CLRPWM0		= AUX1^3;
    sbit 		DPSEL		  = AUX1^0;//0表选择DPTR;1表选择DPTR1
/*
******************************************************************************************************
*/	
sfr 	ICECON 		= 0xF9;
	#define 	HWBRK		          0x80		//H/W Break
	#define 	RETROREQ          0x40		//Retro-OPCode Request,HW set at SWBRK,clear at NMI return
	#define 	TXRDY		          0x20		//Transmitt Ready
	#define 	CMDRDY	          0x10		//Ready for Command
	#define 	XFIRCK	          0x08		//Swich to FIRC 4MHZ
	#define 	WRFAIL	          0x01		//EEPROM Write Fail
/*
******************************************************************************************************
*/	
sfr 	RETROCODE	= 0xFA;//ICE Mode Retro-OPCode
/*
******************************************************************************************************
*/	
sfr 	ICERCD 		= 0xFB;//ICE Mode Receive Data
/*
******************************************************************************************************
*/	
sfr 	ICECMDL		= 0xFC;//ICE Mode Command Low Byte
/*
******************************************************************************************************
*/	
sfr 	ICECMDH		= 0xFD;//ICE Mode Command High Byte
/*
******************************************************************************************************
*/	
sfr 	ICETXD 		= 0xFE;//ICE Mode Transmit Data
/*
******************************************************************************************************
*/	
sfr 	INDSFR 		= 0xFF;//SFR direct Adr replaced by ICECMDL in NMI"mov dir,a"&"mov a,dir"
/*
******************************************************************************************************
*/
#define	 All_Interrupt_Enable()		do{EA = 1;}while(0)		//全局中断使能
#define	 All_Interrupt_Disable()	do{EA = 0;}while(0)		//全局中断关闭
/*
******************************************************************************************************
*/
#define	 PowerDown()			do{PCON = PCON | PD;}while(0)	//进入掉电模式
#define	 PowerIdel()			do{PCON = PCON | IDL;}while(0)	//进入IDEL模式
#endif
