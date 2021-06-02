#include "test_lptimer.h"
#include "lptimer.h"
#include "test_main.h"
#include "sysc.h"
#include "iom.h"
#include "stdio.h"

void LPT_IrqHandler(void)
{
    LPT_ClrIntFlag();
    SYSC->CLKENCFG |= SYSC_CLKENCFG_IOM_PCKEN;
    IOM->OE |= GPIO_PIN14;
    IOM->DATA = IOM->DATA & GPIO_PIN14 ? IOM->DATA & ~GPIO_PIN14 : IOM->DATA | GPIO_PIN14;
    SYSC->CLKENCFG &= ~SYSC_CLKENCFG_IOM_PCKEN;
}

void TestModelLPT(u8 *pu8Dat)
{
    switch (pu8Dat[FUNC])
    {
    case LPT_FUNC_CFG:
        switch (pu8Dat[ITEM])
        {
        case LPT_CFG_PARM:
           // u32 Del = ((u32)pu8Dat[PARM + 4] << 24) | ((u32)pu8Dat[PARM + 3] << 16) | ((u32)pu8Dat[PARM + 2] << 8) |
           //             pu8Dat[PARM+1];
           // LPT_Init(pu8Dat[PARM], Del, pu8Dat[PARM + 5]);
           break;
        case LPT_CFG_IE_CTL:
            if (pu8Dat[PARA])
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
