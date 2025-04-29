/*
 * DCR.h
 *
 *  Created on: Apr 25, 2025
 *      Author: is750
 */

#ifndef INC_DCR_H_
#define INC_DCR_H_
#include "main.h"
#define DARK_TRIGGERS_FREQUENCY  240000000//Частота таймера для 1 мс.

typedef struct
{
	uint32_t ARR;//Значение необходимо для темновых срабатываний
	uint32_t Frequency;//Частота таймера
	float k;//Коэффициент смещения в диапазон
	uint32_t period;//
	uint32_t RNG_Data;//Значение сформированного числа
}DCR_Setting;

void math (DCR_Setting *DCR);
void DCR_Geterate (DCR_Setting *DCR);
#endif /* INC_DCR_H_ */
