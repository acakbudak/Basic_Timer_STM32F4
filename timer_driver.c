#include "timer_driver.h"

void timer_init(TIM_TypeDef *pTimer)
{
	  
		pTimer->CR1 |= (1 << 0);
		pTimer->CR1 &= ~(1 << 4);
	
}

void timer_deinit(TIM_TypeDef *pTimer)
{
  	pTimer->CR1 &= ~(0x00000000);
	pTimer->PSC = 0;
	pTimer->ARR = 0;
		
}

void timer_pre_arr(TIM_TypeDef *pTimer, uint32_t pre , uint32_t arr)
{
	pTimer->PSC = pre;
	pTimer->ARR = arr;
	
}

void timer_IT_begin(TIM_TypeDef *pTimer)
{
	
	pTimer->DIER |= (1 << 0);
	if(pTimer == TIM2)
	{
	*NVIC_ISER0 |= (1 << 28);
	}else if(pTimer == TIM3)
	{
	*NVIC_ISER0 |= (1 << 29);
	}else if(pTimer == TIM4)
	{
	*NVIC_ISER0 |= (1 << 30);
	}else	if(pTimer == TIM5)
	{
	*NVIC_ISER1 |= (1 << 18);
	}
	
}
