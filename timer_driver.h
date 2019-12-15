/*********************************************************************************
	************Timer initialize icin gerekli header dosyasi*******************
********************************************************************************/

#ifndef __TIMER_DRIVER_H
#define __TIMER_DRIVER_H

#include "stm32f446xx.h"

#define NVIC_ISER0          ( (volatile uint32_t*)0xE000E100 )
#define NVIC_ISER1          ( (volatile uint32_t*)0xE000E104 )

void timer_init(TIM_TypeDef *pTimer);
void timer_deinit(TIM_TypeDef *pTimer);
void timer_pre_arr(TIM_TypeDef *pTimer, uint32_t pre , uint32_t arr);
void timer_IT_begin(TIM_TypeDef *pTimer);




#endif /* __TIMER_DRIVER_H */
