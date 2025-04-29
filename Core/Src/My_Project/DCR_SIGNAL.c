/*
 * DCR_SIGNAL.c
 *
 *  Created on: Apr 21, 2025
 *      Author: is750
 */
#include "main.h"
#include "rng.h"
#include "tim.h"
#include "DCR.h"
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

void DCR_Geterate (DCR_Setting *DCR)
{
	DCR->RNG_Data	= RNG_GetValue ();
	DCR->period 	= (float)(DCR->RNG_Data*DCR->k+1);
	TIM5->ARR		= DCR->period;
}
