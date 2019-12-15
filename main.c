/*********************************************************************************
						************ main.c dosyasi*******************	
********************************************************************************/

#include "stm32f446xx.h"
#include "timer_driver.h"
#include "gpio_driver.h"

void delay(void)
{
	for(uint32_t i = 0 ; i < 125000 ; i ++); //yaklasik 100 ms lik delay fonksiyonu
}



int main(void)
{
	RCC->AHB1ENR |= (1 << 0);
	RCC->AHB1ENR |= (1 << 2);
	RCC->APB1ENR |= (1 << 0);
	RCC->APB1ENR |= (1 << 1);
	RCC->APB1ENR |= (1 << 2);
	RCC->APB1ENR |= (1 << 3);
	RCC->APB2ENR |= (1 << 1);

	
	
	gpio_init(GPIOA,5,0,1);
	gpio_init(GPIOC,13,1,0);
	
	while(1)
	{
		uint32_t sayac=0;
		
		while( ! gpio_read(GPIOC,13) )
		{
			delay();
			sayac++;
		}
		if(sayac>1 && sayac<10) //kisa basma modu
		{
			timer_deinit(TIM5);
			timer_deinit(TIM8);
			timer_deinit(TIM2);
			timer_init(TIM2);
			timer_pre_arr(TIM2 ,2700,6000);
			timer_IT_begin(TIM2);
			
			timer_deinit(TIM3);
			timer_init(TIM3);
			timer_pre_arr(TIM3 ,10800,6000);
			timer_IT_begin(TIM3);
    
			
		}
		if(sayac>10) // uzun basma modu
		{
			timer_deinit(TIM3);
			timer_deinit(TIM4);
			timer_deinit(TIM2);
			timer_init(TIM2);
			timer_pre_arr(TIM2 ,2700,6000);
			timer_IT_begin(TIM2);
			
			timer_deinit(TIM5);
			timer_init(TIM5);
			timer_pre_arr(TIM5 ,21600,6000);
			timer_IT_begin(TIM5);
		
		}
		
	}
	
	
	
}

void TIM2_IRQHandler(void)
{
	
	TIM2->SR &= ~(1 << 0);
	GPIOA->ODR ^= (1 << 5);
	
	
}

void TIM3_IRQHandler(void)
{
	TIM3->SR &= ~(1 << 0);
	timer_pre_arr(TIM2 ,5400,6000);
	timer_deinit(TIM3);
	timer_init(TIM4);
	timer_pre_arr(TIM4 ,21600,6000);
	timer_IT_begin(TIM4);
}


void TIM4_IRQHandler(void)
{
	TIM4->SR &= ~(1 << 0);
	timer_pre_arr(TIM2 ,2700,6000);
	timer_deinit(TIM4);
	timer_init(TIM3);
	timer_pre_arr(TIM3 ,10800,6000);
	timer_IT_begin(TIM3);
	
}


void TIM5_IRQHandler(void)
{
	TIM5->SR &= ~(1 << 0);
	timer_pre_arr(TIM2 ,5400,6000);
	timer_deinit(TIM5);
	timer_init(TIM8);
	timer_pre_arr(TIM8 ,43200,6000);
	timer_IT_begin(TIM8);
	
	
}

void TIM8_IRQHandler(void)
{
	TIM8->SR &= ~(1 << 0);
	timer_pre_arr(TIM2 ,2700,6000);
	timer_deinit(TIM8);
	timer_init(TIM5);
	timer_pre_arr(TIM5 ,21600,6000);
	timer_IT_begin(TIM5);
	
	
}

