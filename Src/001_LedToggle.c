/*
 * 001_LedToggle.c
 *
 *  Created on: Sep 30, 2020
 *      Author: milind
 */
#include "STM32F407xx.h"
#include "STM32F407xx_gpio_driver.h"

void delay(void)
{
	for(uint32_t i = 0; i <= 50000; i += 1);
}

int main(void)
{
	GPIO_Handle_t gpioLed;
	gpioLed.pGPIOx = GPIOD;
	gpioLed.GPIO_PinConfig.PinNumber = GPIO_PIN_NO_12;
	gpioLed.GPIO_PinConfig.PinMode = GPIO_MODE_OUT;
	gpioLed.GPIO_PinConfig.PinOpType = GPIO_OP_TYPE_PP;
	gpioLed.GPIO_PinConfig.PinSpeed = GPIO_SPEED_HIGH;
	gpioLed.GPIO_PinConfig.PinPuPdCtrl = GPIO_NO_PUPD;

	GPIO_PeriphClkCtrl(GPIOD, ENABLE);	//gpioLed.pGPIOx = GPIOD
	GPIO_Init(&gpioLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		delay();
	}

	return 0;
}
