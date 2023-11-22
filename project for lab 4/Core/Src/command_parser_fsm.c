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



// check if the message = RST or not
int check_RST(uint8_t buffer[]){
	if (buffer[0] == 'R' && buffer[1] == 'S' && buffer[2] == 'T'){
		return 1;
	}
	else return 0;
}
// check if the message = OK or not
int check_OK(uint8_t buffer[]){
	if (buffer[0] == 'O' && buffer[1] == 'K'){
		return 1;
	}
	else return 0;
}

void command_parser_fsm(){
	switch(status)
	{
		case INIT:
			if (temp == '!')
			{
				status = PROCESS;
			}
			break;
		case PROCESS:
			if (temp != '!' && temp != '#')
			{
				command[i] = temp;
				i++;
			}
			if (temp == '#')
			{
				i = 0;
				status = COMMAND;
			}
			break;
		case COMMAND:
			if (check_RST(command) == 1)
			{
				command_flag = TRANSMIT;
				setTimer1(10);
			}
			else if (check_OK(command) == 1)
			{
				command_flag = END;
			}
			status  = INIT;
			break;
	}
}


//void command_parser_fsm()
//{
//	switch(status)
//	{
//		case INIT:
//			if(buffer[index_buffer-1] == 'R')
//			{
//				status = input_R;
//			}
//			if(buffer[index_buffer-1] == 'O')
//			{
//				status = end_O;
//			}
//			if(buffer[index_buffer-1] != 'R' && buffer[index_buffer-1] != 'O')
//			{
//				status = INIT;
//			}
//			break;
//		case input_R:
//			if(buffer[index_buffer-1] == 'R')
//			{
//				status = input_R;
//			}
//			if(buffer[index_buffer-1] == 'S')
//			{
//				status = input_S;
//			}
//			if(buffer[index_buffer-1]!= 'R' && buffer[index_buffer-1]!= 'S')
//			{
//				status = INIT;
//			}
//			break;
//		case input_S:
//			if(buffer[index_buffer-1] == 'S')
//			{
//				status = INIT;
//			}
//			if(buffer[index_buffer-1] == 'T')
//			{
//				status = input_T;
//			}
//			if(buffer[index_buffer-1] != 'T')
//			{
//				status = INIT;
//			}
//			break;
//		case input_T:
//			command_flag = 1;
//			status = INIT;
//			break;
//
//		case end_O:
//			if(buffer[index_buffer-1] == 'O')
//			{
//				status = end_O;
//			}
//			if(buffer[index_buffer-1] == 'K')
//			{
//				status = end_K;
//			}
//			if(buffer[index_buffer-1]!= 'O' && buffer[index_buffer-1]!= 'K')
//			{
//				status = INIT;
//			}
//			break;
//		case end_K:
//			command_flag = 2;
//			status = INIT;
//			break;
//
//		default:
//			break;
//
//	}
//}


