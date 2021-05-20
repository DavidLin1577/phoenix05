/*
 ============================================================================
 Name        : main.c
 Author      : David Lin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello RISC-V World in C
 ============================================================================
 */


#include "lib_include.h"
#include "test.h"


#define LED_RED    GPIO_PIN14
#define LED_GREEN  GPIO_PIN2

#define LED_OFF(pin) GPIO_SetPin(pin)
#define LED_ON(pin)  GPIO_ClrPin(pin)


int main(void)
{
	GPIO_PinConfigure(LED_GREEN | LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_GREEN | LED_RED);

	test_entry();

	while(1)
	{
		LED_OFF(LED_RED);
	}
	return 0;
}

