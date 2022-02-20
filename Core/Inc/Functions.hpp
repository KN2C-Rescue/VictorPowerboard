/*
 * Functions.hpp
 *
 *  Created on: Jan 31, 2022
 *      Author: Joker
 */

#ifndef INC_FUNCTIONS_HPP_
#define INC_FUNCTIONS_HPP_

#ifndef		_FUNC
#define		_FUNC

#include "math.h"
#include "Variables.hpp"
#include "tim.h"
#include "usart.h"
#include "gpio.h"





extern 	void 		depack(int first_header_byte,int second_header_byte,int* packet_counter,uint8_t* Rec,UART_HandleTypeDef *huart);
extern 	void 		hipHop							(void)	;
extern	void 		assignData					(void)	;
extern	void 		stopRobot						(void)	;
extern	void 		send2Chassis				(void)	;
extern	void 		shutdown						(void)	;
extern	void 		checkShutdown				(void)	;
extern	void 		powerOff						(void)	;
extern	void 		powerOn							(void)	;
extern	void		sendShutdownReq			(void)	;
extern	void 		checkReset					(void)	;
extern	void 		adcConv							(void)	;

#endif



#endif /* INC_FUNCTIONS_HPP_ */
