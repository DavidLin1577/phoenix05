/*
 ============================================================================
 Name        : main.c
 Author      : David Lin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello RISC-V World in C
 ============================================================================
 */


#include <demo.h>
#include "lib_include.h"
#include "test.h"

int main(void)
{
	demo_entry();
	test_entry();

	while(1)
	{

	}
	return 0;
}

