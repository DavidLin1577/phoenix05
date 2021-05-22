#include "lib_include.h"
#include "lptimer_demo.h"
#include "lptimer.h"
#include "demo.h"

void lptimer_pit_demo(void)
{
    LPT_Init(500, LPT_PIT_CNT);
    PLIC_EnableIRQ(LPTIMER_IRQn);
    PLIC_SetPriority(LPTIMER_IRQn, 1);
    LPT_EnableIRQ();
    LPT_EnableControl(ENABLE);
    LPT_ClrIntFlag();

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void lptimer_sig_demo(void)
{
    LPT_Init(500, LPT_SIG_TIME_CNT);
    PLIC_EnableIRQ(LPTIMER_IRQn);
    PLIC_SetPriority(LPTIMER_IRQn, 1);
    LPT_EnableIRQ();
    LPT_EnableControl(ENABLE);
    LPT_ClrIntFlag();

    EnableGlobleIRQ();

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void lptimer_demo(void)
{
#if 0
	lptimer_pit_demo();
#else
	lptimer_sig_demo();
#endif
}

void LPTIMER_IrqHandler(void)
{
    static int tog = 0;

    if(tog)
    {
        tog = 0;
        LED_OFF(LED_RED);
    }
    else
    {
        tog = 1;
        LED_ON(LED_RED);
    }

    LPT_ClrIntFlag();
}

