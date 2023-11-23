/*
 * global.c
 *
 *  Created on: Nov 16, 2023
 *      Author: USER
 */
#include "global.h"
#include "command_parser_fsm.h"
#include "uart_communication_fsm.h"


uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t status = 1;
uint8_t status1 = 11;
uint8_t command_flag = 0;
uint8_t ADC_value = 0;
uint8_t command[5];
uint8_t i;





