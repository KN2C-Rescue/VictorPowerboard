/*
 * Variables.hpp
 *
 *  Created on: Jan 31, 2022
 *      Author: Joker
 */

#ifndef INC_VARIABLES_HPP_
#define INC_VARIABLES_HPP_



#include "define.hpp"
#include <cstdlib>

extern	int test;
extern	int  	lastTimeDataRecived;
extern	int  	powerEn;
extern	int  	fanEn;
extern	int  	LEDEn;
extern	int 	data_is_recived;
extern	int  	indexx;
extern	int 	chassisCurrrent;
extern	int 	logicCurrent;
extern	int  	teknicCurrent;
extern	int 	armCurrent;
extern	int		emPoweroff;
extern	int 	robotisShutdown;

extern	double  	batteryVoltage;

extern	uint8_t		powerByte;
extern 	uint8_t 	reset;
extern 	uint8_t 	chassisDisArm;
extern 	uint8_t 	shutdown;
extern 	uint8_t 	chassisEn;
extern 	uint8_t 	shutdownPressed;
extern 	uint8_t 	armPower;

extern	uint16_t 	adcRaw[5];


struct _PacketParam
{
	char 		firstHeader;
	char 		secondHeader;
	int 		depackCounter ;
	int 		receiveLenght;
	int 		transmitLenght;
	uint8_t* 	receiveData;
	uint8_t* 	transmitData;
	uint8_t 	receiveHeader;
	bool 		syncBytesValid;
	UART_HandleTypeDef *huart;


	_PacketParam(UART_HandleTypeDef *_huart,char _firstHeader,char _secondHeader,int _receiveLenght, int _transmitLenght)
	{
		firstHeader = _firstHeader;
		secondHeader = _secondHeader;

		receiveLenght = _receiveLenght;
		transmitLenght = _transmitLenght;
		receiveData = (uint8_t*) malloc(receiveLenght * sizeof(uint8_t));
		transmitData = (uint8_t*) malloc(transmitLenght * sizeof(uint8_t));
		huart = _huart;

	}
};

extern struct _PacketParam PacketChassis;

#endif /* INC_VARIABLES_HPP_ */
