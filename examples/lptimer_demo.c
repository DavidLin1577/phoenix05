#include "lib_include.h"
#include "lptimer_demo.h"
#include "demo.h"

void lptimer_sig_demo(void)
{
	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void lptimer_pit_demo(void)
{
	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void lptimer_demo(void)
{
#if 1
	lptimer_sig_demo();
#else
	lptimer_pit_demo();
#endif
}
