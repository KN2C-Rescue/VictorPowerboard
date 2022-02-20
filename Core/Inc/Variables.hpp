/*
 * Variables.hpp
 *
 *  Created on: Jan 31, 2022
 *      Author: Joker
 */

#ifndef INC_VARIABLES_HPP_
#define INC_VARIABLES_HPP_



#include "define.hpp"

extern	int test;
extern	int  	DepackCounter;
extern	int  	LastTimeDataRecived;
extern	int  	PowerEn;
extern	int  	FanEn;
extern	int  	LEDEn;
extern	int 	data_is_recived;
extern	int  	indexx;
extern	int 	ChassisCurrrent;
extern	int 	LogicCurrent;
extern	int  	TeknicCurrent;
extern	int 	ArmCurrent;
extern	int		EmPoweroff;
extern	int 	RobotisShutdown;

extern	double  	BatteryVoltage;


extern 	uint8_t 	rec;
extern 	uint8_t 	Chassis_Recive[Chassis_Recive_len];
extern 	uint8_t 	Chassis_Transmit[Chassis_Transmit_len];
extern	uint8_t		PowerByte;
extern 	uint8_t 	Reset;
extern 	uint8_t 	ChassisDisArm;
extern 	uint8_t 	Shutdown;
extern 	uint8_t 	ChassisEn;
extern 	uint8_t 	ShutdownPressed;
extern 	uint8_t 	ArmPower;

extern	uint16_t 	adcRaw[5];



#endif /* INC_VARIABLES_HPP_ */
