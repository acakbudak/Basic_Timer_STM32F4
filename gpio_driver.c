
#include "gpio_driver.h"


void gpio_init(GPIO_TypeDef *pGPIOLED,uint32_t pin_number,uint32_t pupd,uint32_t mode)
{
	if(mode==0)
	pGPIOLED->MODER &= ~(0x3 << pin_number);
	if(mode==1)
	pGPIOLED->MODER |= (1 << pin_number*2);
	
	pGPIOLED->OSPEEDR |= (2 << pin_number*2);
	
	if(pupd == 0)
	pGPIOLED->PUPDR &= ~(0x03 << pin_number*2);
	if(pupd == 1)
	GPIOC->PUPDR |= (0x01 << pin_number*2);
	
}

uint8_t gpio_read(GPIO_TypeDef *pGPIOLED, uint32_t pin_number)
{
	 uint8_t value;
	 value = (uint8_t )((pGPIOLED->IDR  >> pin_number) & 0x00000001 ) ;
	 return value;
}

void gpio_pin_toggle(GPIO_TypeDef *pGPIOLED, uint32_t pin_number)
{
	
	pGPIOLED->ODR ^= (1 << pin_number);
	
}

