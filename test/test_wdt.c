#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "test.h"
#include "wdt.h"

static void wdt_poweron_status(void)
{

	UNITEST_EQUALS(WDT_RST_REG,  0x00,  WDT_LOG_ADDR, 1);
	UNITEST_EQUALS(WDT_CR_REG,   0x70f, WDT_LOG_ADDR, 2);
	//REG32(WDT_LOG_ADDR) = 0xff;
	//REG32(WDT_LOG_ADDR) = 0xff;

}

void test_wdt()
{
    wdt_poweron_status();
}

