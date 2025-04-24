/*
 * DCR_SIGNAL.c
 *
 *  Created on: Apr 21, 2025
 *      Author: is750
 */
#include "main.h"
#include "rng.h"
#include "tim.h"
#define MIN_PERION 1000//Минимальный период = 100 мс
#define MAX_PERIOD 10//Максимальный период 	= 1 мс
#define MIN_N 5//Минимальный делитель
//Суть блока в том, чтобы брать значения с RNG, смещать их в диапазон до 100 кГц,т.е. числа до
//которого будет считать счетчик и генерировать PWM. Длительность импульса должна быть минимальна,
//т.к. она имитирует отклик от фотона всё таки, поэтому нет необходимости менять его длительность.
//Таким образом при каждом заходе в этот блок мы будем иметь новое значение ARR.
uint32_t RNG_GetValue (void)
{
	if (RNG->CR & RNG_CR_RNGEN)//Проверяем включено ли
	{
		RNG->CR |= RNG_CR_RNGEN;//Включаем генератор
	}
	return RNG->DR;
}

uint32_t period;
uint32_t RNG_Data;
void DCR_Geterate ()
{
	RNG_Data = RNG_GetValue ();
	period = (RNG_Data>>22);
	if (period >1)
	TIM3->ARR = period;
//	__HAL_TIM_SET_AUTORELOAD(&htim3, period);


}
