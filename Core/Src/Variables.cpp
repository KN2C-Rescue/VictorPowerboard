/*
 * Variables.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: Joker
 */

#include "usart.h"
#include "Variables.hpp"

	int test=0;
	int  	lastTimeDataRecived=0;
	int  	powerEn;
	int  	fanEn;
	int  	LEDEn;
	int 	data_is_recived=0;
	int  	indexx=0;
	int 	chassisCurrrent;
	int 	logicCurrent;
	int  	teknicCurrent;
	int 	armCurrent;
	int		emPoweroff=0;
	int 	robotisShutdown=0;

	double  	batteryVoltage;


	uint8_t		powerByte;
	uint8_t 	reset=0;
	uint8_t 	chassisDisArm=0;
	uint8_t 	shutdown=0;
	uint8_t 	chassisEn=1;
	uint8_t 	shutdownPressed=0;
	uint8_t 	armPower=1;

	uint16_t 	adcRaw[5]={0};


struct _PacketParam PacketChassis (&huart1,'C','P',CP_len,	PC_len);
