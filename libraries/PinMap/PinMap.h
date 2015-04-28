/*
*************************************************************************************
PinMap.h - Library for keeping all of our pin locations nice.
*************************************************************************************
Change Log:
12/22/14 - Initial Version
*************************************************************************************
*/
#ifndef Pin_h
#define Pin_h

#define IR_SENS 8
const int IRminOn[8] = {884, 724, 520, 568, 568, 568, 732, 1008};
const int IRmaxOn[8] = {2500, 2500, 2500, 2500, 2500, 2500, 2500, 2500};
const int IRminOff[8] = {255, 8632, 8600, 8568, 1744, 4, 1, 20001};
const int IRmaxOff[8] = {255, 8632, 8600, 8568, 1744, 4, 1, 20001};

namespace Pin {
    //MOTORS
	//int mtr_dir_FL = 22;
	//int mtr_dir_FR = 23;
	int mtr_dir_FL = 37; //motor 4
	int mtr_dir_FR = 36; //motor 3
	//int mtr_dir_BL =;
	//int mtr_dir_BR =;
    int mtr_spd_FL = 6;
    int mtr_spd_FR = 7;
    //int mtr_spd_BL = ;
    //int mtr_spd_BR = ;
    
	//ULTRASONICS--- TX = Echo = Odd pins Arduino / RX = Trigger = Even pins Arduino
    int u_trig_FL  = 44;
    int u_echo_FL  = 45;
	int u_trig_FR  = 40;
    int u_echo_FR  = 41;
	//int u_trig_BL  = 46;
    //int u_echo_BL  = 47;
	//int u_trig_BR  = 36;
    //int u_echo_BR  = 37;
	int u_trig_FF  = 42;
    int u_echo_FF  = 43;
    
	//INFRAREDS
	int i1  = 53;
	int i2  = 52;
	int i3  = 51;
	int i4  = 50;
	int i5  = 25;
	int i6  = 24;
	int i7  = 23;
	int i8  = 22;
    int iLed = 5;
	int infraL = 47;
	int infraR = 46;
	//int infra_LL    = 53;
    //int infra_RR    = 25;
    
	//SERIAL DISPLAY
    int disp_D4    = 33;
    int disp_D5    = 32;
	int disp_D6    = 31;
    int disp_D7    = 30;
    int disp_RS    = 35;
    int disp_EN    = 34;
    int disp_RW    = 0;//????
    int disp_BLR   = 29;
    int disp_BLG   = 28;
    int disp_BLB   = 27;
    
	//BUTTONS
    int goBtn      = 39;
	//int goBtn      = 50;
    int mazeSizeA  = 48;
    int mazeSizeB  = 49;
    
	//INDICATORS
    int indLEDR    = 3;
    int indLEDG    = 9;
};
#endif