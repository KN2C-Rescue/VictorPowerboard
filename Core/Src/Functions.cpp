#include "Functions.hpp"

void 	send2Chassis(void)
{
	Chassis_Transmit[0]	=	'P'	;
	Chassis_Transmit[1]	=	'C'	;
	Chassis_Transmit[2]	=	'd'	;
	Chassis_Transmit[3]	=	PowerByte	;
	Chassis_Transmit[4]	=	(int)(BatteryVoltage*10.0)	;
	Chassis_Transmit[5]	=	LogicCurrent;
	Chassis_Transmit[6]	=	TeknicCurrent;
	Chassis_Transmit[7]	=	ArmCurrent;
	Chassis_Transmit[8]	=	ChassisCurrrent;

	Chassis_Transmit[Chassis_Transmit_len-1]	=	'\r'	;

	HAL_UART_Transmit(&huart1, Chassis_Transmit, Chassis_Transmit_len, 10);
}

void 	assignData(void)
{
	if(Chassis_Recive[Chassis_Recive_len-1]=='\r')
	{
		EmPoweroff			= (	Chassis_Recive[0] & 0x01	) >> 	0	; //0b00000001
		Shutdown				=	(	Chassis_Recive[0] & 0x02	) >> 	1	; //0b00000010
		ChassisDisArm		= (	Chassis_Recive[0] & 0x04	) >> 	2	;	//0b00000100
		Reset						=	(	Chassis_Recive[0] & 0x08	) >> 	3	;	//0b00001000
		ArmPower				= (	Chassis_Recive[0] & 0x10	) >> 	4	;	//0b00010000
		ChassisEn				= (	Chassis_Recive[0] & 0x20	) >> 	5	;	//0b00000100

		if(EmPoweroff)	{powerOff();}
		if(Shutdown)		{shutdown();}
		if(ArmPower)		{En_Arm_on;}
		else 	if(!ArmPower)		{En_Arm_off;}
		if(ChassisEn)		{En_Chassis_on;}
		else 	if(!ChassisEn)	{En_Chassis_off;}

		send2Chassis();

		for(int i=0; i<Chassis_Recive_len;	i++)	{Chassis_Recive[i]=0;}
	}

}

void 	depack(int first_header_byte,int second_header_byte,int* packet_counter,uint8_t* Rec,UART_HandleTypeDef *huart)
{

	switch(*packet_counter)
	{	case 0:
		if(data_is_recived) 								{data_is_recived=0; assignData();	}
		else if((*Rec)==first_header_byte) 	{	(*packet_counter)++;						}
		else                       					{	(*packet_counter)=0;						}
		HAL_UART_Receive_IT(huart, Rec, 1);
		break;

	case 1:
		if((*Rec)==second_header_byte) {	(*packet_counter)++;			}
		else 												{	(*packet_counter)=0;			}
		HAL_UART_Receive_IT(huart, Rec, 1);
		break;

	case 2:
		if(first_header_byte=='M')	{	HAL_UART_Receive_IT(&huart1, Chassis_Recive, Chassis_Recive_len);
		data_is_recived=yes;
		LastTimeDataRecived=0;
		}
		else 												{	HAL_UART_Receive_IT(huart, Rec , 1	);}
		(*packet_counter)=0;
		break;
	}
}
void 	hipHop(void)
{
	for(int i=0;i<8;i++)
	{
		LED_blue_Toggle	;

		LED_red_Toggle	;
		HAL_Delay(100)	;
	}
}

void 	stopRobot(void)
{
	En_Arm_off;
	En_Chassis_off;
}

void 	shutdown(void)
{
	hipHop();
	for(int i=0	;	i<3	;	i++)
	{sendShutdownReq();}
	HAL_Delay(10000);
	hipHop();
	powerOff();
	RobotisShutdown=yes;
}
void	sendShutdownReq(void)
{
	Chassis_Transmit[0] |=	0x02;
	send2Chassis();
}
void 	checkShutdown(void)
{
	if(	(isShutdownPressed	&&	!RobotisShutdown)	||	(Shutdown	&&	!RobotisShutdown)	)
	{ShutdownPressed++;
	if(ShutdownPressed>50)
	{shutdown();}
	}
	else if(!isShutdownPressed)
	{powerOn();RobotisShutdown=no;}
}

void 	powerOff(void)
{
	En_Arm_off;
	En_Chassis_off;
}
void 	powerOn(void)
{
	En_Arm_on;
	En_Chassis_on;
}
void 	checkReset(void)
{
	if(Reset)	{
		En_Arm_off;
		En_Chassis_off;
		HAL_Delay(3000);
		En_Arm_on;
		En_Chassis_on;
	}
}
void 	adcConv(void)
{
	BatteryVoltage	=	(RawBattery/161.0)	+	0.4	;
}
