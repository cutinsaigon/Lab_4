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
			else
				status = INIT;
			break;

		case PROCESS:
			if	(temp == '!')
			{
				status = PROCESS;
			}
			if (temp != '!' && temp != '#')
			{
				command[i] = temp;
				i++;
				if (check_RST(command) == 1)
				{
					status = End;

				}
				else if (check_OK(command) == 1)
				{
					status = End;

				}

			}
			break;

		case End:
			if (temp == '#')
			{
				command_flag = 1;
				i = 0;
				status = INIT;
			}
			break;

	}
}

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





