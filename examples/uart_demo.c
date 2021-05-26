#include "lib_include.h"
#include "demo.h"

#define UART_DEMO_EN          (1)

#if UART_DEMO_EN


void uart_demo(void)
{
	int i = 0;
	char byte;

	UART_Init(UART_MODE_8B_SYNC, 9600);
	UART_EnableControl(UART_EN_TYPE_REN);

	GPIO_PinConfigure(UART1_RX, DISABLE, DISABLE, DISABLE, DISABLE, DISABLE);
	GPIO_PinConfigure(UART1_TX, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);

    IOM->AF0 |= 0x3;

	byte = 'u';
	for(i = 0; i < 100; i++)
	{
		UART_WriteData(byte);
	}
}

#else
__attribute__((weak)) void wdt_demo(void){};
#endif

