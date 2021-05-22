#include "lib_include.h"
#include "wdt_demo.h"
#include "demo.h"

void wdt_int_demo(void)
{
	WDT_Init(20000, WDT_OV_INT);
	WDT_Start();

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void wdt_rst_demo(void)
{
	WDT_Init(20000, WDT_OV_RST);
	WDT_Start();

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void wdt_demo(void)
{
#if 1
	wdt_int_demo();
#else
	wdt_rst_demo();
#endif
}

void NMI_Handler(void)
{
    static int tog = 0;

    if (tog)
    {
        LED_ON(LED_RED);
        tog = 0;
    } else
    {
        LED_OFF(LED_RED);
        tog = 1;
    }

    WDT_ClearIntFlag();
}
