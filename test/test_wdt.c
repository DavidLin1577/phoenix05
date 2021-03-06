#include "test_wdt.h"
#include "wdt.h"
#include "demo.h"
#include "test_main.h"

#if TEST_WDT_EN

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
	UNITEST_EQUALS(WDT_RST_REG,  0x00,  WDT_LOG_EQUALS_ADDR, WDT_RST_REG_POWERON_POS);
	UNITEST_EQUALS(WDT_CR_REG,   0x70f, WDT_LOG_EQUALS_ADDR, WDT_CR_REG_POWERON_POS);
}

static void wdt_init(int mode)
{
	UNITEST_EQUALS(WDT_RST_REG,  0x00,  WDT_LOG_EQUALS_ADDR , WDT_RST_REG_INIT_POS);
	UNITEST_EQUALS(WDT_CR_REG,   0x70f, WDT_LOG_EQUALS_ADDR,  WDT_CR_REG_INIT_POS);
}

static void wdt_run(int mode)
{
	switch(mode)
	{
	case WDT_OV_INT:
		break;
	case WDT_OV_RST:
		break;
	default:
		break;
	}

	UNITEST_EQUALS(WDT_RST_REG,  0x00,  WDT_LOG_EQUALS_ADDR , WDT_RST_REG_RUN_POS);
	UNITEST_EQUALS(WDT_CR_REG,   0x70f, WDT_LOG_EQUALS_ADDR,  WDT_CR_REG_RUN_POS);

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

void NMI_Handler(void)
{
    static int tog = 0;

    if (tog)
    {
        LED_ON(LED_RED);
        tog = 0;
    }
    else
    {
        LED_OFF(LED_RED);
        tog = 1;
    }

    WDT_ClearIntFlag();
}
#ifdef _TIM1_WDT
void TIMER1_IrqHandler(void)
{
    TIM_ClrIntFlag(TIM1);
    TIM_DeInit(TIM1);
    TIM_TimerInit(TIM1, 1000);
    TIM_EnableControl(TIM1, ENABLE);
    WDT_ClrCount();
}
#endif

void TestModelWDT(u8 func, u8 item, u8 para0, u8 para1, u8 para2)
{
	u8 i;
    u8 msg[10]  = {0};

    switch (func)
    {
    case WDT_FUNC_CFG:
        switch (item)
        {
        case WDT_CFG_PARM:
            WDT_DeInit();
            WDT_Init(para0, para1, para2);
            break;
        default:
            break;
        }
        break;
    case WDT_FUNC_CTL_NO_RUN:
        WDT->RST = 0x96;
        WDT->RST = 0x69;
        break;
    case WDT_FUNC_CTL_RUN:
        WDT->RST = 0x69;
        WDT->RST = 0x96;
        break;
    case WDT_FUNC_GET_STS:
	    printf("wdt sts %x\r\n", WDT->CR);
        break;
    case WDT_FUNC_FEED:
        #if 0
        TIM_DeInit(TIM1);
        TIM_TimerInit(TIM1, 1000);
        PLIC_SetPriority(TIMER1_IRQn, 1);
        PLIC_EnableIRQ(TIMER1_IRQn);
        TIM_ClrIntFlag(TIM1);
        TIM_EnableIRQ(TIM1);
        TIM_EnableControl(TIM1, ENABLE);
        break;
        #endif
    case WDT_FUNC_INT:
    	WDT_Init(item, 20000, WDT_OV_INT);
    	WDT_Start();
    	GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
    	GPIO_SetPin(LED_RED);
    	LED_ON(LED_RED);
    	break;
    case WDT_FUNC_DEINIT:
    	WDT_DeInit();
    	break;
    default:
        break;
    }
}

#endif

