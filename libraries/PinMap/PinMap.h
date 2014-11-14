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

namespace Pin {
    //MOTORS
	int mtr_dir_FL = 27;
	int mtr_dir_FR = 26;
	int mtr_dir_BL = 25;
	int mtr_dir_BR = 24;
    int mtr_spd_FL = 12;
    int mtr_spd_FR = 11;
    int mtr_spd_BL = 10;
    int mtr_spd_BR = 9;
    //ULTRASONICS
    int u_trig_FL  = 33;
    int u_echo_FL  = 32;
	int u_trig_FR  = 31;
    int u_echo_FR  = 30;
	int u_trig_BL  = 37;
    int u_echo_BL  = 36;
	int u_trig_BR  = 35;
    int u_echo_BR  = 34;
	int u_trig_FF  = 29;
    int u_echo_FF  = 28;
    //INFRAREDS
	int infra_L    = 46;
	int infra_R    = 48;
    //SERIAL DISPLAY
    int disp_D4    = 0;
    int disp_D5    = 0;
	int disp_D6    = 0;
    int disp_D7    = 0;
    int disp_RS    = 0;
    int disp_EN    = 0;
    int disp_RW    = 0;
    int disp_BkR   = 0;
    int disp_BkG   = 0;
    int disp_BkB   = 0;
    //BUTTONS
    int goBtn      = 41;
    int mazeSizeA  = 43;
    int mazeSizeB  = 45;
    //INDICATORS
    int indLEDR    = 0;
    int indLEDG    = 0;
    int indLEDB    = 0;
};
#endif