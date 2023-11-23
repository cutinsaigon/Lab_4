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




char str[20];
void uart_communication_fsm()
{
    switch(status1)
    {
        case IDLE:
            //IDLE
            if(command_flag == 1)
            {
                ADC_value = HAL_ADC_GetValue(&hadc1)*5/4096;
                status1 = TRANSMIT;
                command_flag = 0;
            }
            break;
        //Transmitted message "ADC_value"
        case TRANSMIT:
            HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "ADC value = %d\r\n", ADC_value), 1000);
            setTimer1(3000);
            status1 = END;
            break;
        //End of transmission
        case END:
            //Time out for sending message 'OK'
            if(timer1_flag == 1)
            {
                status1 = TRANSMIT;
            }
            if(command_flag == 1)
            {
                status1 = IDLE;
                command_flag = 0;
            }
            break;

        default:
            break;
    }
}
