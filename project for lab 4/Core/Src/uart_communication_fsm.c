/*
 * uart_communication_fsm.c
 *
 *  Created on: Nov 16, 2023
 *      Author: USER
 */

#include "string.h"
#include "stdio.h"
#include "command_parser_fsm.h"
#include "global.h"
#include "main.h"
#include "timer.h"


void uart_communication_fsm(){
	char str[50];
	switch(command_flag)
	{
		//transmit value to console
		case TRANSMIT:
			if (timer1_flag == 1)
			{
				ADC_value = HAL_ADC_GetValue(&hadc1)*5/4096;
				HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "!ADC=%d#\r\n",ADC_value), 1000);
				setTimer1(3000);
			}
		    break;
		 // ending communication
		case END:
			ADC_value = -1;
			command_flag = INIT;
			break;
	}
}


//void uart_communication_fsm()
//{
//    switch(status1)
//    {
//        case RECEIVE:
//            //Receive and hold ADC value until receive message "OK"
//            if(command_flag == 1)
//            {
//
//                ADC_value = HAL_ADC_GetValue(&hadc1)*5/4096;
//                status1 = TRANSMIT;
//                command_flag = 0;
//            }
//
//            break;
//        //Transmitted message "ADC_value"
//        case TRANSMIT:
//            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "ADC value = %d\r\n", ADC_value), 1000);
//            setTimer1(3000);
//            status1 = END;
//            break;
//        //End of transmission
//        case END:
//            //Time out for receiving message "OK"
//            if(timer1_flag == 1)
//            {
//                status1 = TRANSMIT;
//            }
//            if(command_flag == 2)
//            {
//                command_flag = 0;
//                status1 = RECEIVE;
//
//            }
//            break;
//
//        default:
//            break;
//    }
//}
