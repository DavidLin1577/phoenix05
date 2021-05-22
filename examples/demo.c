#include <demo.h>

#define DEMO_EN              (1)
#define WDT_DEMO_EN          (0)
#define LPTIMER_DEMO_EN      (1)

void demo_entry(void)
{
#if DEMO_EN

    #if WDT_DEMO_EN
    wdt_demo();
    #endif

    #if LPTIMER_DEMO_EN
    lptimer_demo();
    #endif

#endif
}

