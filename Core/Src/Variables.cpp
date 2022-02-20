/*
 * Variables.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: Joker
 */




#include "Variables.hpp"

	int test=0;
	int  	DepackCounter=0;
	int  	LastTimeDataRecived=0;
	int  	PowerEn;
	int  	FanEn;
	int  	LEDEn;
	int 	data_is_recived=0;
	int  	indexx=0;
	int 	ChassisCurrrent;
	int 	LogicCurrent;
	int  	TeknicCurrent;
	int 	ArmCurrent;
	int		EmPoweroff=0;
	int 	RobotisShutdown=0;

	double  	BatteryVoltage;

	uint8_t 	rec;
	uint8_t 	Chassis_Recive[Chassis_Recive_len];
	uint8_t		PowerByte;
	uint8_t 	Chassis_Transmit[Chassis_Transmit_len];
	uint8_t 	Reset=0;
	uint8_t 	ChassisDisArm=0;
	uint8_t 	Shutdown=0;
	uint8_t 	ChassisEn=1;
	uint8_t 	ShutdownPressed=0;
	uint8_t 	ArmPower=1;

	uint16_t 	adcRaw[5]={0};

