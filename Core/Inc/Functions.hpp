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





extern 	void 		CheckRecData (struct _PacketParam* PacketParam);
extern 	void 		HipHop (void)	;
extern	void 		AssignData (int PacketType)	;
extern	void 		StopRobot (void)	;
extern	void 		Send2Chassis (void)	;
extern	void 		Shutdown (void)	;
extern	void 		CheckShutdown (void)	;
extern	void 		PowerOff (void)	;
extern	void 		PowerOn	(void)	;
extern	void		SendShutdownReq	(void)	;
extern	void 		CheckReset (void)	;
extern 	void 		CheckPacketValidation(void);
extern	void 		AdcConv (void)	;
extern 	void 		SendPacket			(struct _PacketParam* packetParam);


#endif



#endif /* INC_FUNCTIONS_HPP_ */
