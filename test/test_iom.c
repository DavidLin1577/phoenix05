#include "test_iom.h"
#include "lib_include.h"
#include "test_main.h"


void IOM_IrqHandler(void)
{
    for (int i = 0; i < 20; ++i)
    {
        if (IOM->INTF & (1 << i))
        {
            IOM->INTF = (1 << i);
            //printf("int pin:%d", i);
        }
    }
}

void TestModelIOM(u8 func, u8 item, u8 para)
{
    SYSC->CLKENCFG |= SYSC_CLKENCFG_IOM_PCKEN;
#if 0
    switch (func)
    {
    case IOM_FUNC_CFG:
        switch (item)
        {
        case IOM_CFG_AF:
            u16 Dat = ( (u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            GPIO_PinSelect(Dat, pu8Dat[PARM + 2]);
            break;
        case IOM_CFG_AIN_EN:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->ADS |= tmp;
            break;
        case IOM_CFG_AIN_DIS:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->ADS &= ~tmp;
            break;
        case IOM_CFG_OE_EN:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->OE |= tmp;
            break;
        case IOM_CFG_OE_DIS:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->OE &= ~tmp;
            break;
        case IOM_CFG_PU_EN:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->PU |= tmp;
            break;
        case IOM_CFG_PU_DIS:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->PU &= ~tmp;
            break;
        case IOM_CFG_PD_EN:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->PD |= tmp;
            break;
        case IOM_CFG_PD_DIS:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->PD &= ~tmp;
            break;
        case IOM_CFG_OTYPE_EN:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->OTYPE |= tmp;
            break;
        case IOM_CFG_OTYPE_DIS:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->OTYPE &= ~tmp;
            break;
        case IOM_CFG_DRS_STRONG:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->DRS |= tmp;
            break;
        case IOM_CFG_DRS_WEAK:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->DRS &= ~tmp;
            break;
        case IOM_CFG_INT_TYPE_LVL:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->INT_TYPE |= tmp;
            break;
        case IOM_CFG_INT_TYPE_EDGE:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->INT_TYPE &= ~tmp;
            break;
        case IOM_CFG_INT_POL_HIGH:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->INT_POLARITY |= tmp;
            break;
        case IOM_CFG_INT_POL_LOW:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->INT_POLARITY &= ~tmp;
            break;
        case IOM_CFG_INT_EN:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            PLIC_SetPriority(IOM_IRQn, 1);
            PLIC_EnableIRQ(IOM_IRQn);
            PLIC_EnableIRQ(IOM_IRQn);
            GPIO_ClrIntFlag(GPIO_ALL);
            IOM->EXT_INTE |= tmp;
            break;
        case IOM_CFG_INT_DIS:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->EXT_INTE &= ~tmp;
            break;
        case IOM_CFG_OUT_DATA_HIGH:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->DATA |= tmp;
            break;
        case IOM_CFG_OUT_DATA_LOW:
            u16 tmp = ((u16)pu8Dat[PARM + 1] << 8) | pu8Dat[PARM];
            IOM->DATA &= ~tmp;
            break;
        default:
            break;
        }
        break;
    case IOM_FUNC_GET_DATA:
        printf("%x", IOM->DATA);
        break;
    case IOM_FUNC_GET_STS:
        printf("%x", IOM->INTF);
        break;
    case IOM_FUNC_CTL_DEBOUNCE_DIS:
        IOM->CTL &= ~IOM_CTL_DEBOUNCE;
        break;
    case IOM_FUNC_CTL_DEBOUNCE_EN:
        IOM->CTL |= IOM_CTL_DEBOUNCE;
        break;
    case IOM_FUNC_CTL_G_INT_DIS:
        IOM->CTL &= ~IOM_CTL_INTE;
        break;
    case IOM_FUNC_CTL_G_INT_EN:
        IOM->CTL |= IOM_CTL_INTE;
        break;
    case IOM_FUNC_CTL_IN_LS_SYNC_DIS:
        IOM->CTL &= ~IOM_CTL_LS_SYNC;
        break;
    case IOM_FUNC_CTL_IN_LS_SYNC_EN:
        IOM->CTL |= IOM_CTL_LS_SYNC;
        break;
    default:
        break;
    }
#endif
}
