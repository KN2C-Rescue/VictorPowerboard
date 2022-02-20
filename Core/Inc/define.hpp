/*
 * define.hpp
 *
 *  Created on: Jan 31, 2022
 *      Author: Joker
 */

#ifndef INC_DEFINE_HPP_
#define INC_DEFINE_HPP_


#include "main.h"




////placing ADC data into their variables
#define	RawChassisCurrrent			adcRaw[0]
#define	RawLogicCurrent					adcRaw[1]
#define RawTeknicCurrent				adcRaw[2]
#define RawBattery							adcRaw[3]
#define	RawArmCurrent						adcRaw[4]



//.......................................

#define TIMCallBack   					void HAL_TIM_PeriodElapsedCallback	(TIM_HandleTypeDef *htim		)
#define TxCallBack   						void HAL_UART_TxCpltCallback				(UART_HandleTypeDef *huart	)
#define RxCallBack    					void HAL_UART_RxCpltCallback				(UART_HandleTypeDef *huart	)


//LED
#define	LED_blue_Toggle	 				HAL_GPIO_TogglePin(LED1_GPIO_Port		,LED1_Pin			)
#define	LED_red_Toggle	 				HAL_GPIO_TogglePin(LED2_GPIO_Port		,LED2_Pin			)

#define	LED_blue_on	 						HAL_GPIO_WritePin(LED1_GPIO_Port		,LED1_Pin		,1)
#define	LED_red_on	 						HAL_GPIO_WritePin(LED2_GPIO_Port		,LED2_Pin		,1)

#define	LED_blue_off	 					HAL_GPIO_WritePin(LED1_GPIO_Port		,LED1_Pin		,0)
#define	LED_red_off	 						HAL_GPIO_WritePin(LED2_GPIO_Port		,LED2_Pin		,0)


//Power
#define En_Arm_on 							HAL_GPIO_WritePin(ArmPowerEn_GPIO_Port,ArmPowerEn_Pin,GPIO_PIN_SET)
#define En_Arm_off 							HAL_GPIO_WritePin(ArmPowerEn_GPIO_Port,ArmPowerEn_Pin,GPIO_PIN_RESET)

#define En_Chassis_on 					HAL_GPIO_WritePin(ChassisPowerEn_GPIO_Port,ChassisPowerEn_Pin,GPIO_PIN_SET)
#define En_Chassis_off 					HAL_GPIO_WritePin(ChassisPowerEn_GPIO_Port,ChassisPowerEn_Pin,GPIO_PIN_RESET)

#define isShutdownPressed				!HAL_GPIO_ReadPin(ShutDown_GPIO_Port,ShutDown_Pin)


//size
#define	Chassis_Transmit_len		10
#define	Chassis_Recive_len			7


//boolian States
#define valid										1
#define unvalid 								0

#define yes											1
#define no											0




//Packets...

//1.NUC	->	|	'M'	|	'C'	|	Power Byte	|	Right Motor PWM	|	Left Motor PWM |	Fron Flipper PWM	|	Back Flipper PWM	|	/r	|






#endif /* INC_DEFINE_HPP_ */
