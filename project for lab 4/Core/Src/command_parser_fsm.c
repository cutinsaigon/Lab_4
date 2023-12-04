/*
 * command_parser_fsm.c
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






void command_parser_fsm(){
	uint8_t i = (index_buffer - 1 < 0)? MAX_BUFFER_SIZE - 1 : index_buffer - 1;
	switch(status){
		case INIT:
			if (temp == '!')
				status = PROCESS;
			break;
		case PROCESS:
			if (buffer[i] == '#')
			{
				command_flag = 1;
				status = INIT;
			}
			else if (buffer[i] == '!')
			{
				index_data = 0;
				memset(data, '\0', sizeof(data));
			}
			else data[index_data++] = buffer[i];
			break;
		default:
			break;
	}
}


// check if the message = RST or not
//int check_RST(uint8_t buffer[]){
//	if (buffer[0] == 'R' && buffer[1] == 'S' && buffer[2] == 'T'){
//		return 1;
//	}
//	else return 0;
//}
//// check if the message = OK or not
//int check_OK(uint8_t buffer[]){
//	if (buffer[0] == 'O' && buffer[1] == 'K'){
//		return 1;
//	}
//	else return 0;
//}

//void command_parser_fsm(){
//	switch(status)
//	{
//		case INIT:
//			//start communication by !
//			if (temp == '!')
//			{
//				status = PROCESS;
//			}
//
//		case PROCESS:
//			// !!!! is recognized as only 1 !
//			if	(temp == '#')
//			{
//
//			}
////			if (temp != '!' && temp != '#')
////			{
////				command[i] = temp;
////				i++;
////				// whether or not command = RST or OK fsm switch to the last stage
////				if (check_RST(command) == 1)
////				{
////					status = Start;
////				}
////				if (check_OK(command) == 1)
////				{
////					status = End;
////				}
////			}
//			break;
//		case Start:
//			if (temp == '#')
//			{
//				status = INIT;
//				command_flag = 1;
//				i = 0;
//			}
//			break;
//		case End:
//			if (temp == '#')
//			{
//				status = INIT;
//				command_flag = 0;
//				i = 0;
//
//			}
//			break;
//
//	}
//}



//void command_parser_fsm(){
//	switch(status)
//	{
//		case INIT:
//			if (temp == '!')
//			{
//				status = PROCESS;
//			}
//			else
//				status = INIT;
//			break;
//
//		case PROCESS:
//			if	(temp == '!')
//			{
//				status = PROCESS;
//			}
//			if (temp != '!' && temp != '#')
//			{
//				command[i] = temp;
//				i++;
//			}
//			if (temp == '#')
//			{
//				i = 0;
//				status = COMMAND;
//			}
//			break;
//		case COMMAND:
//			if (check_RST(command) == 1)
//			{
//				command_flag = 1;
//			}
//			else if (check_OK(command) == 1)
//			{
//				command_flag = 1;
//			}
//
//			status  = INIT;
//			break;
//	}
//}





