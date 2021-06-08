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

	printf("hello risc-v\r\n");

	while(1)
	{
		demo_entry();
		test_entry();
	}
	return 0;
}

