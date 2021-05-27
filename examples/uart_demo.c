#include "lib_include.h"
#include "demo.h"

#define UART_DEMO_EN          (1)

#if UART_DEMO_EN

static void delay(int cnt)
{
	int i = 0;

	for(i = 0; i < cnt;i++)
	{
		__asm("NOP");
	}
}

static void uart_tx_demo(void)
{
	int i = 0;
	char bytes1[20] = {'r','i','s','c','v','\r'};
	char bytes2[20] = {'p','h','o','e','n','i','x','0','5','\r'};
	char bytes3[20] = {'u','a','r','t',' ','d','e','m','o','\r'};
	int mode;

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	LED_ON(LED_RED);

	UART_DeInit();
	GPIO_PinSelect(UART1_RX | UART1_TX, PIN_FUNC_1);

	mode = UART_MODE_11B_ASYNC;

	switch(mode)
	{
	case UART_MODE_8B_SYNC:
		UART_Init(UART_MODE_8B_SYNC, 9600);
		for(i = 0; i < sizeof(bytes1);i++)
		{
			UART_WriteData(bytes1[i]);
			delay(10000);
		}
		break;
	case UART_MODE_10B_ASYNC:
		UART_Init(UART_MODE_10B_ASYNC, 9600);
		for(i = 0; i < sizeof(bytes2);i++)
		{
			UART_WriteData(bytes2[i]);
			delay(10000);
		}
		break;
	case UART_MODE_11B_ASYNC:
		UART_Init(UART_MODE_11B_ASYNC, 9600);
		for(i = 0; i < sizeof(bytes3);i++)
		{
			UART_WriteData(bytes3[i]);
			delay(10000);
		}
		break;
	}
}

void uart_demo(void)
{
	int mode = 0;

    switch(mode)
    {
    case 0:
    	uart_tx_demo();
    	break;
    case 1:
    	break;
    case 2:
    	break;
    case 3:
    	break;
    }
}

void UART1_IrqHandler(void)
{

}

void MEXP_Handler(void)
{
	//LED_ON(LED_RED);
}

#else
__attribute__((weak)) void wdt_demo(void){};
#endif

