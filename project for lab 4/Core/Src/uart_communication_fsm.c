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
#include "uart_communication_fsm.h"
#include "stdlib.h"

// comparison function:  compare character in 2 string
int isStringEqual(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

char str[20];
void uart_communication_fsm(){
	switch(status1){
		case TRANSMIT:
			if (command_flag == 1)
			{
				command_flag = 0;
				if (isStringEqual(data, "RST"))
				{
					HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
					status1 = END;

					HAL_ADC_Start(&hadc1);
					HAL_ADC_PollForConversion(&hadc1, 1000);
					ADC_value = HAL_ADC_GetValue(&hadc1)*5/4096;
					HAL_ADC_Stop(&hadc1);
					HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!ADC=%dV#\r\n",ADC_value), 1000);
					setTimer1(100);
				}
				memset(data, '\0', sizeof(data));
				index_data = 0;
			}
			break;
		case END:
			if (timer1_flag == 1)
			{
				setTimer1(3000);
				HAL_UART_Transmit(&huart2, (void*)str, sprintf(str,"!ADC=%dV#\r\n",ADC_value), 1000);
			}
			if (command_flag == 1)
			{
				command_flag = 0;
				if (isStringEqual(data, "OK"))
				{
					status1 = TRANSMIT;
					HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				}
				memset(data, '\0', sizeof(data));
				index_data = 0;
			}
			break;
		default:
			break;
	}
}
//void uart_communication_fsm()
//{
//    switch(status1)
//    {
//        case IDLE:
//            //IDLE
//            if(command_flag == 1)
//            {
//                ADC_value = HAL_ADC_GetValue(&hadc1)*5/4096;
//                status1 = TRANSMIT;
////                command_flag = 0;
//            }
//            break;
//        //Transmitted message "ADC_value"
//        case TRANSMIT:
//            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "ADC value = %dV\r\n", ADC_value), 1000);
//            setTimer1(3000);
//            status1 = END;
//            break;
//        //End of transmission
//        case END:
//            //Time out for sending message 'OK'
//            if(timer1_flag == 1)
//            {
//                status1 = TRANSMIT;
//            }
//
//            if(command_flag == 0)
//            {
////            	command_flag = 0;
//                status1 = IDLE;
//            }
//            break;
//
//        default:
//            break;
//    }
//}
//void uart_communication_fsm()
//{
//    switch(status1)
//    {
//        case IDLE:
//            //IDLE
//            if(command_flag == 1)
//            {
//                ADC_value = HAL_ADC_GetValue(&hadc1)*5/4096;
//                status1 = TRANSMIT;
//                command_flag = 0;
//            }
//            break;
//        //Transmitted message "ADC_value"
//        case TRANSMIT:
//            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "ADC value = %d\r\n", ADC_value), 1000);
//            setTimer1(3000);
//            status1 = END;
//            break;
//        //End of transmission
//        case END:
//            //Time out for sending message 'OK'
//            if(timer1_flag == 1)
//            {
//                status1 = TRANSMIT;
//            }
//
//            if(command_flag == 1)
//            {
//            	command_flag = 0;
//                status1 = IDLE;
//            }
//            break;
//
//        default:
//            break;
//    }
//}
