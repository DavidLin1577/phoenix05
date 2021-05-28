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

int main(void)
{
	void* param;

	demo_entry();
	test_entry();

	while(1)
	{

	}
	return 0;
}

