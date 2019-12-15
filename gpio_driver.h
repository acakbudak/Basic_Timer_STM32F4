/*********************************************************************************
************GPIO port input/output için gerekli header dosyasi*******************
********************************************************************************/

#ifndef __GPIO_DRIVER_H
#define __GPIO_DRIVER_H

#include "stm32f446xx.h"




void gpio_init(GPIO_TypeDef *pGPIOLED, uint32_t pin_number, uint32_t pupd, uint32_t mode);
uint8_t gpio_read(GPIO_TypeDef *pGPIOLED, uint32_t pin_number);
void gpio_pin_toggle(GPIO_TypeDef *pGPIOLED, uint32_t pin_number);





#endif /*__GPIO_DRIVER_H */

