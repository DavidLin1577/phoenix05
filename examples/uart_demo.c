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

static void uart_normal_demo(void)
{
	int i = 0;
	char bytes1[20] = {'r','i','s','c','v','\r'};
	char bytes2[20] = {'p','h','o','e','n','i','x','0','5','\r'};
	char bytes3[20] = {'u','a','r','t',' ','d','e','m','o','\r'};
	char bytes4[20] = {'h','e','l','l','o','w','o','r','l','d','\r'};

	char value = 0;
	int mode;

	mode = UART_MODE_10B_ASYNC;

	switch(mode)
	{
	case UART_MODE_8B_SYNC:
		UART_Init(UART_MODE_8B_SYNC, 9600);
		for(i = 0; i < sizeof(bytes1);i++)
		{
			UART_WriteData(bytes1[i]);
		}
		break;
	case UART_MODE_10B_ASYNC:
		UART_Init(UART_MODE_10B_ASYNC, 9600);
		for(i = 0; i < sizeof(bytes2);i++)
		{
			UART_WriteData(bytes2[i]);
		}
		break;
	case UART_MODE_11B_ASYNC:
		UART_Init(UART_MODE_11B_ASYNC, 9600);
		for(i = 0; i < sizeof(bytes3);i++)
		{
			UART_WriteData(bytes3[i]);
		}
		//puts(bytes4);
		value = UART_ReadData();
		{
			LED_ON(LED_RED);
			UART_WriteData(value);
		}
		break;
	}
}

static void uart_int_demo(void)
{
	int i = 0;
	char bytes_rx[20] = {0};
	char bytes_tx[20] = {0};
	int mode;

	mode = UART_MODE_11B_ASYNC;

	switch(mode)
	{
	case UART_MODE_8B_SYNC:
		UART_Init(UART_MODE_8B_SYNC, 9600);
		break;
	case UART_MODE_10B_ASYNC:
		UART_Init(UART_MODE_10B_ASYNC, 9600);
		break;
	case UART_MODE_11B_ASYNC:
		UART_Init(UART_MODE_11B_ASYNC, 9600);
		break;
	}
}

void uart_demo(void)
{
	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);

	int pin  = 0;
	int mode = 0;

	UART_DeInit();

	//chose which pin to set as uart
	switch(pin)
	{
	case 0:
		GPIO_PinSelect(UART1_RX | UART1_TX, PIN_FUNC_1);
		break;
	case 1:
		break;
	default:
		break;
	}

	//chose uart mode
	mode = 0;
    switch(mode)
    {
    case 0:
    	uart_normal_demo();
    	break;
    case 1:
    	uart_int_demo();
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
__attribute__((weak)) void uart_demo(void){};
#endif

