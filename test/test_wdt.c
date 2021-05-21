#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "test_wdt.h"
#include "wdt.h"

//wdt
#define WDT_LOG_ADDR                (TEST_WDT_BASE)
#define WDT_LOG_EQUALS_ADDR         (WDT_LOG_ADDR              + 0x00 )  //地址可以根据实际需要配置
#define WDT_LOG_DIFFERS_ADDR        (WDT_LOG_ADDR              + 0x04 )
#define WDT_LOG_LESS_THAN_ADDR      (WDT_LOG_ADDR              + 0x08 )

typedef enum wdt_log_offset
{
	WDT_RST_REG_POWERON_POS       = 0,
	WDT_CR_REG_POWERON_POS        = 1,
	WDT_RST_REG_INIT_POS          = 2,
	WDT_CR_REG_INIT_POS           = 3,
	WDT_RST_REG_RUN_POS           = 4,
	WDT_CR_REG_RUN_POS            = 5,
	WDT_RST_REG_DEEPSLEEP_POS     = 6,
	WDT_CR_REG_DEEPSLEEP_POS      = 7,
	WDT_RST_REG_POWERDOWN_POS     = 8,
	WDT_CR_REG_POWERDOWN_POS      = 9,
	WDT_RST_REG_DEINIT_POS        = 10,
	WDT_CR_REG_DEINIT_POS         = 11,
	WDT_REG_MAX_POS               = 16    //因为phoenix05最大地址为15位，所以不能超过15
}wdt_log_offset_t;

static void wdt_poweron(void)
{
	UNITEST_EQUALS(WDT_RST_REG,  0x00,  WDT_LOG_ADDR, WDT_RST_REG_POWERON_POS);
	UNITEST_EQUALS(WDT_CR_REG,   0x70f, WDT_LOG_ADDR, 2);
}

static void wdt_init(int mode)
{

}

static void wdt_run(int mode)
{

}

static void wdt_deepsleep(void)
{

}

static void wdt_powerdown(void)
{


}

static void wdt_deinit(void)
{

}

void test_wdt()
{
	int mode = WDT_OV_INT; //另外一种模式WDT_OV_RST

    wdt_poweron();

    //手动修改运行模式
    wdt_init(mode);

    //手动修改运行模式
    wdt_run(mode);

    //休眠模式后续再测试
    wdt_deepsleep();

    wdt_powerdown();

    wdt_deinit();
}

