/*
 * 01LedToggle.c
 *
 *  Created on: 1st-Oct-2020
 *      Author: Amit
 */

#include "STM32F407xx.h"
#include "STM32F407xx_gpio_driver.h"
#include <stdio.h>
void delay()
{

	for (uint32_t i = 0; i < 50000; i++)
	{
		//do nothing
	}
}

int main(void)
{
	GPIO_Handle_t GPIOLed;
	GPIOLed.pGPIOx = GPIOD;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_Pin_No_12;
	GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_Mode_Out;
	GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OPType_PuPd;
	GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_Speed_High;
	GPIOLed.GPIO_PinConfig.GPIO_PinPupdControl = GPIO_Pin_NoPupd;
	GPIO_Peri_CLKControl(GPIOD, ENABLE);
	GPIO_init(&GPIOLed);

	GPIO_Handle_t GPIOUserSwitch;
	GPIOUserSwitch.pGPIOx = GPIOA;
	GPIOUserSwitch.GPIO_PinConfig.GPIO_PinNumber = GPIO_Pin_No_0;
	GPIOUserSwitch.GPIO_PinConfig.GPIO_PinMode = GPIO_Mode_Input;
	//GPIOUserSwitch.GPIO_PinConfig.GPIO_PinSpeed = GPIO_Speed_High;
	GPIOUserSwitch.GPIO_PinConfig.GPIO_PinPupdControl = GPIO_Pin_NoPupd;
	GPIO_Peri_CLKControl(GPIOA, ENABLE);
	GPIO_init(&GPIOUserSwitch);

	while (1)
	{
		if (GPIO_Read_fromInputPin(GPIOA, GPIO_Pin_No_0))
		{
			GPIO_Write_toOutputPin(GPIOD, GPIO_Pin_No_12, ENABLE);
			delay();
		}
		else
		{
			GPIO_Write_toOutputPin(GPIOD, GPIO_Pin_No_12, DISABLE);
			delay();
		}
	}
	return 0;
}

