/*
 * timer.c
 *
 *  Created on: Nov 17, 2022
 *      Author: Admin
 */

#include "main.h"
#include "timer.h"

void timer_set(int idx, int duration){
	if (idx >= NUMBER_OF_TIMER) return;
	timer_counter[idx] = duration/TIMER_CYCLE; //timer_cycle = 10 ;
	timer_flag[idx] = 0;
}

void timer_run(){
	for (int i = 0; i < NUMBER_OF_TIMER; i++){
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if (timer_counter[i] == 0) timer_flag[i] = 1;
		}
	}
}

 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		timer_run();
	}
}



