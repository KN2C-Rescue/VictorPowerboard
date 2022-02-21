#include "Functions.hpp"

void 	Send2Chassis(void)
{
	//	Chassis_Transmit[0]	=	'P'	;
	//	Chassis_Transmit[1]	=	'C'	;
	//	Chassis_Transmit[2]	=	'd'	;
	//	Chassis_Transmit[3]	=	PowerByte	;
	//	Chassis_Transmit[4]	=	(int)(BatteryVoltage*10.0)	;
	//	Chassis_Transmit[5]	=	LogicCurrent;
	//	Chassis_Transmit[6]	=	TeknicCurrent;
	//	Chassis_Transmit[7]	=	ArmCurrent;
	//	Chassis_Transmit[8]	=	ChassisCurrrent;
	//
	//	Chassis_Transmit[Chassis_Transmit_len-1]	=	'\r'	;
	//
	//	HAL_UART_Transmit(&huart1, Chassis_Transmit, Chassis_Transmit_len, 10);
}

void 	AssignData(struct _PacketParam* packetParam)
{

	emPoweroff			= (	packetParam->receiveData[0] & 0x01	) >> 	0	; //0b00000001
	shutdown			= (	packetParam->receiveData[0] & 0x02	) >> 	1	; //0b00000010
	chassisDisArm		= (	packetParam->receiveData[0] & 0x04	) >> 	2	;	//0b00000100
	reset				= (	packetParam->receiveData[0] & 0x08	) >> 	3	;	//0b00001000
	armPower			= (	packetParam->receiveData[0] & 0x10	) >> 	4	;	//0b00010000
	chassisEn			= (	packetParam->receiveData[0] & 0x20	) >> 	5	;	//0b00000100
	LED_red_Toggle;

	if(emPoweroff)
	{
		PowerOff();
	}
	if(shutdown)
	{
		Shutdown();
	}
	if(armPower)
	{
		En_Arm_on;
	}
	else if(!armPower)
	{
		En_Arm_off;
	}
	if(chassisEn)
	{
		En_Chassis_on;
	}
	else 	if(!chassisEn)
	{
		En_Chassis_off;
	}

	Send2Chassis();


}
void CheckPacketValidation(void)
{
	if(PacketChassis.syncBytesValid == true)
	{

		AssignData(&PacketChassis);
		PacketChassis.syncBytesValid =false;
	}
}

void 	CheckRecData(struct _PacketParam* packetParam)
{


	switch(packetParam->depackCounter)
	{
	case 0:
		if(packetParam->receiveHeader==packetParam->firstHeader)
		{

			packetParam->depackCounter++;
		}
		else
		{
			packetParam->depackCounter =0;
		}

		HAL_UART_Receive_IT(packetParam->huart, &packetParam->receiveHeader, 1);

		break;

	case 1:
		if(packetParam->receiveHeader==packetParam->secondHeader)
		{

			packetParam->depackCounter++;
			HAL_UART_Receive_IT(packetParam->huart, packetParam->receiveData	, packetParam->receiveLenght);

		}
		else if(packetParam->receiveHeader==packetParam->firstHeader )
		{
			packetParam->depackCounter=1;
			HAL_UART_Receive_IT(packetParam->huart, &packetParam->receiveHeader, 1);
		}
		else
		{
			packetParam->depackCounter=0;
			HAL_UART_Receive_IT(packetParam->huart,&packetParam->receiveHeader, 1);
		}


		break;

	case 2:



		if( packetParam->receiveData[ packetParam->receiveLenght - 1 ] == '\r' )
		{

			packetParam->syncBytesValid = true;
		}
		else
		{
			packetParam->syncBytesValid = false;
		}
		packetParam->depackCounter=0;
		HAL_UART_Receive_IT(packetParam->huart, &packetParam->receiveHeader, 1);


		break;
	}
}
void 	HipHop(void)
{
	for(int i=0;i<6;i++)
	{
		LED_blue_Toggle	;

		LED_red_Toggle	;
		HAL_Delay(100)	;
	}
}

void 	StopRobot(void)
{
	En_Arm_off;
	En_Chassis_off;
}

void 	Shutdown(void)
{
	HipHop();
	for(int i=0	;	i<3	;	i++)
	{SendShutdownReq();}
	HAL_Delay(10000);
	HipHop();
	PowerOff();
	robotisShutdown=yes;
}
void	SendShutdownReq(void)
{
	//	Chassis_Transmit[0] |=	0x02;
	Send2Chassis();
}
void 	CheckShutdown(void)
{
	if(	(isShutdownPressed	&&	!robotisShutdown)	||	(shutdown	&&	!robotisShutdown)	)
	{shutdownPressed++;
	if(shutdownPressed>50)
	{Shutdown();}
	}
	else if(!isShutdownPressed)
	{PowerOn();robotisShutdown=no;}
}

void 	PowerOff(void)
{
	En_Arm_off;
	En_Chassis_off;
}
void 	PowerOn(void)
{
	En_Arm_on;
	En_Chassis_on;
}
void 	CheckReset(void)
{
	if(reset)	{
		En_Arm_off;
		En_Chassis_off;
		HAL_Delay(3000);
		En_Arm_on;
		En_Chassis_on;
	}
}
void 	AdcConv(void)
{
	batteryVoltage	=	(RawBattery/161.0)	+	0.4	;
}
