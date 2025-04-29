/*
 * RISING_PHOTON.c
 *
 *  Created on: Apr 15, 2025
 *      Author: is750
 */
#include "main.h"
#include "gpio.h"

/*Настроить таймер в режиме one pulse. На вход триггера подавать импульс. Использовать также
триггер mode для запуска другого таймера по захвату входного сигнала (COMPARE PULSE (MMS))
Таймер мертвого времени настроить на прерывания только по переполнению URS=1;
*/

void HAL_TIM_TriggerCallback(TIM_HandleTypeDef *htim)
{
//  HAL_TIM_OnePulse_Start(&htim1, TIM_CHANNEL_1);
//	TIM1->EGR |= TIM_EGR_UG;
	TIM1->BDTR 	&= ~TIM_BDTR_MOE;//Отключаем первый канал
	TIM1->CCER	&= ~TIM_CCER_CC1E;
	TIM4->CR1	= TIM_CR1_CEN;//Включаем таймер мертвого времени
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	TIM4->CR1	&= ~TIM_CR1_CEN;
	TIM1->CCER	= TIM_CCER_CC1E;
	TIM1->BDTR	= TIM_BDTR_MOE;
	TIM4->CNT	= 0;
}
