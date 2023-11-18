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



void command_parser_fsm()
{
	switch(status)
	{
		case INIT:
			if(buffer[index_buffer-1] == 'R')
			{
				status = input_R;
			}
			if(buffer[index_buffer-1] == 'O')
			{
				status = end_O;
			}
			if(buffer[index_buffer-1] != 'R' && buffer[index_buffer-1] != 'O')
			{
				status = INIT;
			}
			break;
		case input_R:
			if(buffer[index_buffer-1] == 'R')
			{
				status = input_R;
			}
			if(buffer[index_buffer-1] == 'S')
			{
				status = input_S;
			}
			if(buffer[index_buffer-1]!= 'R' && buffer[index_buffer-1]!= 'S')
			{
				status = INIT;
			}
			break;
		case input_S:
			if(buffer[index_buffer-1] == 'S')
			{
				status = INIT;
			}
			if(buffer[index_buffer-1] == 'T')
			{
				status = input_T;
			}
			if(buffer[index_buffer-1] != 'T')
			{
				status = INIT;
			}
			break;
		case input_T:
			command_flag = 1;
			status = INIT;
			break;

		case end_O:
			if(buffer[index_buffer-1] == 'O')
			{
				status = end_O;
			}
			if(buffer[index_buffer-1] == 'K')
			{
				status = end_K;
			}
			if(buffer[index_buffer-1]!= 'O' && buffer[index_buffer-1]!= 'K')
			{
				status = INIT;
			}
			break;
		case end_K:
			command_flag = 2;
			status = INIT;
			break;

		default:
			break;

	}
}
