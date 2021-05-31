#include "demo.h"

#define DEMO_EN              (0)

void demo_entry(void)
{
#if DEMO_EN

    wdt_demo();
    lptimer_demo();
    timer_demo();
    uart_demo();
    EFC_Init();

#endif
}

