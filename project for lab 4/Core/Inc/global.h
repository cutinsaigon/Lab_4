/*
 * global.h
 *
 *  Created on: Nov 16, 2023
 *      Author: USER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"


#define MAX_BUFFER_SIZE 30
#define INIT	1
#define input_R 2
#define input_S	3
#define input_T	4
#define end_O 5
#define end_K 6
#define RECEIVE 11
#define TRANSMIT 12
#define END 13

extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t status;
extern uint8_t status1;
extern uint8_t command_flag;
extern uint8_t ADC_value;
extern uint8_t str[12];


#endif /* INC_GLOBAL_H_ */
