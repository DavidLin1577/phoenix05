#include "test_lptimer.h"
#include "lib_include.h"
#include "lptimer.h"
#include "test_main.h"
#include "sysc.h"
#include "iom.h"

#if TEST_LPT_EN

void LPT_IrqHandler(void)
{
    LPT_ClrIntFlag();
    SYSC->CLKENCFG |= SYSC_CLKENCFG_IOM_PCKEN;
    IOM->OE |= GPIO_PIN14;
    IOM->DATA = IOM->DATA & GPIO_PIN14 ? IOM->DATA & ~GPIO_PIN14 : IOM->DATA | GPIO_PIN14;
    SYSC->CLKENCFG &= ~SYSC_CLKENCFG_IOM_PCKEN;
}

void TestModelLPT(u8 func, u8 item, u8 para0, u8 para1, u8 para2)
{
	u16 Del;

    switch (func)
    {
    case LPT_FUNC_CFG:
        switch (item)
        {
        case LPT_CFG_PARM:
            Del = (u16)(para2 << 8 | para1);
            LPT_Init(Del, para0);
            break;
        case LPT_CFG_IE_CTL:
            if (para0)
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
    case LPT_FUNC_CTL_DIS:
        LPT_EnableControl(DISABLE);
        break;
    case LPT_FUNC_CTL_EN:
        LPT_EnableControl(ENABLE);
        break;
    case LPT_FUNC_GET_CNT:
        printf("cnt:%d\n", LPTIM->CNT);
        break;
    case LPT_FUNC_GET_STS:
        printf("sts:%d\n", LPTIM->INTSTS);
        break;
    default:
        break;
    }
}
#endif //TEST_LPT_EN
