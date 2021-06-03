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
#include "demo.h"
#include <stdio.h>

int main(void)
{
	void* param;

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);

	GPIO_PinSelect(UART1_RX | UART1_TX, PIN_FUNC_1);
	UART_Init(UART_MODE_10B_ASYNC, 9600);

	printf("hello risc-v\r\n");

	while(1)
	{
		demo_entry();
		test_entry();
	}
	return 0;
}

