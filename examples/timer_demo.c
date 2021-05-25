#include "lib_include.h"
#include "timer_demo.h"
#include "timer.h"
#include "demo.h"

#define TIMER_DEMO_EN        (1)

#if TIMER_DEMO_EN

void timer_timing_demo(void)
{
	int timer = TIMER4;

	switch(timer)
	{
	case TIMER0:
		break;
	case TIMER1:
		Timer_Timing_Init(TIMER1, 10000);
        PLIC_EnableIRQ(TIMER1_IRQn);
        PLIC_SetPriority(TIMER1_IRQn, 1);
        Timer_EnableIRQ(TIMER1);
        Timer_EnableControl(TIMER1, ENABLE);
        Timer_ClrIntFlag(TIMER1);
        break;
	case TIMER2:
		Timer_Timing_Init(TIMER2, 200);
        PLIC_EnableIRQ(TIMER2_IRQn);
        PLIC_SetPriority(TIMER2_IRQn, 1);
        Timer_EnableIRQ(TIMER2);
        Timer_EnableControl(TIMER2, ENABLE);
        Timer_ClrIntFlag(TIMER2);
		break;
	case TIMER3:
		Timer_Timing_Init(TIMER3, 300);
        PLIC_EnableIRQ(TIMER3_IRQn);
        PLIC_SetPriority(TIMER3_IRQn, 1);
        Timer_EnableIRQ(TIMER3);
        Timer_EnableControl(TIMER3, ENABLE);
        Timer_ClrIntFlag(TIMER3);
		break;
	case TIMER4:
		Timer_Timing_Init(TIMER4, 400);
        PLIC_EnableIRQ(TIMER4_IRQn);
        PLIC_SetPriority(TIMER4_IRQn, 1);
        Timer_EnableIRQ(TIMER4);
        Timer_EnableControl(TIMER4, ENABLE);
        Timer_ClrIntFlag(TIMER4);
		break;
	default:
		break;
	}

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void timer_count_demo(void)
{

	int timer = TIMER4;

	switch(timer)
	{
	case TIMER0:
		break;
	case TIMER1:
		Timer_Count_Init(TIMER1, 100);
        PLIC_EnableIRQ(TIMER1_IRQn);
        PLIC_SetPriority(TIMER1_IRQn, 1);
        Timer_EnableIRQ(TIMER1);
        Timer_EnableControl(TIMER1, ENABLE);
        Timer_ClrIntFlag(TIMER1);
        break;
	case TIMER2:
		Timer_Count_Init(TIMER2, 200);
        PLIC_EnableIRQ(TIMER2_IRQn);
        PLIC_SetPriority(TIMER2_IRQn, 1);
        Timer_EnableIRQ(TIMER2);
        Timer_EnableControl(TIMER2, ENABLE);
        Timer_ClrIntFlag(TIMER2);
		break;
	case TIMER3:
		Timer_Count_Init(TIMER3, 300);
        PLIC_EnableIRQ(TIMER3_IRQn);
        PLIC_SetPriority(TIMER3_IRQn, 1);
        Timer_EnableIRQ(TIMER3);
        Timer_EnableControl(TIMER3, ENABLE);
        Timer_ClrIntFlag(TIMER3);
		break;
	case TIMER4:
		Timer_Count_Init(TIMER4, 400);
        PLIC_EnableIRQ(TIMER4_IRQn);
        PLIC_SetPriority(TIMER4_IRQn, 1);
        Timer_EnableIRQ(TIMER4);
        Timer_EnableControl(TIMER4, ENABLE);
        Timer_ClrIntFlag(TIMER4);
		break;
	default:
		break;
	}

	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
	GPIO_SetPin(LED_RED);
	LED_ON(LED_RED);
}

void timer_demo(void)
{
#if 1
	timer_timing_demo();
#else
	timer_count_demo();
#endif
}

void TIMER0_IrqHandler(void)
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

    Timer_ClrIntFlag(TIMER0);
}

void TIMER1_IrqHandler(void)
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

    Timer_ClrIntFlag(TIMER1);
}

void TIMER2_IrqHandler(void)
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

    Timer_ClrIntFlag(TIMER2);
}

void TIMER3_IrqHandler(void)
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

    Timer_ClrIntFlag(TIMER3);
}

void TIMER4_IrqHandler(void)
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

    Timer_ClrIntFlag(TIMER4);
}

#else
__attribute__((weak)) void timer_demo(void){};
#endif
