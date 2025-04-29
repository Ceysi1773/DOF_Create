/*
 * math.c
 *
 *  Created on: Apr 25, 2025
 *      Author: is750
 */

#include "DCR.h"

void math (DCR_Setting *DCR)
{

	DCR->Frequency 	= 1000;//Желаемая частота
	DCR->ARR		= DARK_TRIGGERS_FREQUENCY/DCR->Frequency;
	DCR->k			= (float)(2*DCR->ARR)/__UINT32_MAX__;
}
