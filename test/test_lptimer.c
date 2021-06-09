#include "test_lptimer.h"
#include "lib_include.h"
#include "lptimer.h"
#include "test_main.h"
#include "sysc.h"
#include "iom.h"

#if TEST_LPT_EN

void LPTIMER_IrqHandler(void)
{
    static int tog;

    if (tog)
    {
    	tog = 0;
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
    	tog = 1;
        GPIO_SetPin(GPIO_PIN14);
    }
    LPT_ClrIntFlag();
}

void test_mode_lptimer(void)
{
	u16 iDel;
	u16 iPS;
	u16 func;
	u16 item;
	u8 para[10] = {0};

    printf("choose func: 1 - 10\r\n");
	printf("LPT_FUNC_CFG          (0)\r");
	printf("LPT_FUNC_CTL_EN       (1)\r");
	printf("LPT_FUNC_CTL_DIS      (2)\r");
	printf("LPT_FUNC_GET_CNT      (3)\r");
	printf("LPT_FUNC_GET_STS      (4)\r");
	printf("LPT_FUNC_PIT_CNT      (5)\r");
	func     = UART_Receive();

    switch (func)
    {
    case LPT_FUNC_CFG:
    	printf("choose item:\r\n");
    	printf("LPT_CFG_PARM     (0)\r");
    	printf("LPT_CFG_IE_CTL   (1)\r");
        item     = UART_Receive();
        switch (item)
        {
        case LPT_CFG_PARM:
        	printf("iDel: 0x0000 - 0xffff\r");
        	printf("high byte: 0x00 - 0xff\r");
        	para[0]  = UART_Receive();
        	printf("low  byte: 0x00 - 0xff\r");
        	para[1]  = UART_Receive();
        	iDel = ((u16)(para[0] << 8) | para[1]);
        	printf("iDel = %x\r\n", iDel);
        	printf("mode: 0 - LPT_SIG_TIME_CNT;  1 - LPT_PIT_CNT\r");
        	para[2]  = UART_Receive();
        	printf("iPS: 0x0000 - 0xffff\r");
        	printf("high byte: 0x00 - 0xff\r");
        	para[3]  = UART_Receive();
        	printf("low  byte: 0x00 - 0xff\r");
        	para[4]  = UART_Receive();
        	iPS = ((u16)(para[3] << 8) | para[4]);
        	printf("iPS = %x\r", iPS);

            LPT_Init(iDel, para[2], iPS);
            break;
        case LPT_CFG_IE_CTL:
        	printf("LPT_CFG_IE_CTL: 1-enable; 0-disable\r");
        	para[0]  = UART_Receive();
            if (para[0])
            {
                PLIC_SetPriority(LPTIMER_IRQn, 1);
                PLIC_EnableIRQ(LPTIMER_IRQn);
                LPT_ClrIntFlag();
                LPT_EnableIRQ();
            }
            else
            {
                LPT_DisableIRQ();
            }
            break;
        default:
            break;
        }
        break;
    case LPT_FUNC_CTL_EN:
        LPT_EnableControl(ENABLE);
        break;

    case LPT_FUNC_CTL_DIS:
        LPT_EnableControl(DISABLE);
        break;
    case LPT_FUNC_GET_CNT:
        printf("cnt:%x\n", LPTIM->CNT);
        break;
    case LPT_FUNC_GET_STS:
        printf("sts:%x\n", LPTIM->INTSTS);
        break;
    case LPT_FUNC_PIT_CNT:
    	LPT_DeInit();
    	LPT_Init(10, LPT_PIT_CNT, 2);
        PLIC_EnableIRQ(LPTIMER_IRQn);
        PLIC_SetPriority(LPTIMER_IRQn, 1);
        LPT_EnableIRQ();
        LPT_EnableControl(ENABLE);
        LPT_ClrIntFlag();
        printf("LPTIM->CR %x\n", LPTIM->CR);
    	break;
    default:
        break;
    }
}
#endif //TEST_LPT_EN
