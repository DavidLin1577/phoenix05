#include <demo.h>

#define DEMO_EN              (1)

void demo_entry(void)
{
#if DEMO_EN

    wdt_demo();
    lptimer_demo();
    timer_demo();

#endif
}

