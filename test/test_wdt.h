#ifndef _TEST_WDT_H_
#define _TEST_WDT_H_

#include "test.h"

void test_wdt();

//wdt
#define WDT_LOG_ADDR                (TEST_WDT_BASE)
#define WDT_LOG_EQUALS_ADDR         (WDT_LOG_ADDR              + 0x00 )
#define WDT_LOG_DIFFERS_ADDR        (WDT_LOG_ADDR              + 0x04 )
#define WDT_LOG_LESS_THAN_ADDR      (WDT_LOG_ADDR              + 0x08 )

#endif /*_TEST_WDT_H_*/

