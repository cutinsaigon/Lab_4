/*
 * timer.h
 *
 *  Created on: Nov 18, 2023
 *      Author: USER
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "main.h"

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);

void timer_run();

#endif /* INC_TIMER_H_ */
