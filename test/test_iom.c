#include "test_iom.h"
#include "lib_include.h"
#include "test_main.h"

#if TEST_IOM_EN

static void iom_irq_info(u8 pin)
{
	u8 i;
	u8 msg[20]  = {'i', 'n', 't', ' ', 'p', 'i', 'n', ' '};

    msg[9] = pin + '0';
    msg[10] = '\r';
    for(i = 0; i < sizeof(msg);i++)
    {
        UART_Send(msg[i]);
    }
}

static void iom_info(u8 value)
{
	u8 i;
	u8 msg[20]  = {'i', 'o', 'm', ' ', 'i', 'n', 'f', 'o', ':'};

    msg[10] = value + '0';
    msg[11] = '\r';
    for(i = 0; i < sizeof(msg);i++)
    {
        UART_Send(msg[i]);
    }
}

void IOM_IrqHandler(void)
{
    for (int i = 0; i < 20; ++i)
    {
        if (IOM->INTF & (1 << i))
        {
            IOM->INTF = (1 << i);
            iom_irq_info(i);
        }
    }
}

void TestModelIOM(u8 func, u8 item, u8 para0, u8 para1, u8 para2)
{
    SYSC->CLKENCFG |= SYSC_CLKENCFG_IOM_PCKEN;
    u16 Dat   = 0;
    u16 tmp   = 0;
    u8  value = 0;

    switch (func)
    {
    case IOM_FUNC_CFG:
        switch (item)
        {
        case IOM_CFG_AF:
            Dat = ( (u16)((para1<< 8) | para0));
            GPIO_PinSelect(Dat, para2);
            break;
        case IOM_CFG_AIN_EN:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->AINCTRL |= tmp;
            break;
        case IOM_CFG_AIN_DIS:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->AINCTRL &= ~tmp;
            break;
        case IOM_CFG_OE_EN:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->OE |= tmp;
            break;
        case IOM_CFG_OE_DIS:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->OE &= ~tmp;
            break;
        case IOM_CFG_PU_EN:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->PU |= tmp;
            break;
        case IOM_CFG_PU_DIS:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->PU &= ~tmp;
            break;
        case IOM_CFG_PD_EN:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->PD |= tmp;
            break;
        case IOM_CFG_PD_DIS:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->PD &= ~tmp;
            break;
        case IOM_CFG_OTYPE_EN:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->OTYPE |= tmp;
            break;
        case IOM_CFG_OTYPE_DIS:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->OTYPE &= ~tmp;
            break;
        case IOM_CFG_DRS_STRONG:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->DRS |= tmp;
            break;
        case IOM_CFG_DRS_WEAK:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->DRS &= ~tmp;
            break;
        case IOM_CFG_INT_TYPE_LVL:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->INT_TYPE |= tmp;
            break;
        case IOM_CFG_INT_TYPE_EDGE:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->INT_TYPE &= ~tmp;
            break;
        case IOM_CFG_INT_POL_HIGH:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->INT_POLARITY |= tmp;
            break;
        case IOM_CFG_INT_POL_LOW:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->INT_POLARITY &= ~tmp;
            break;
        case IOM_CFG_INT_EN:
            tmp = ((u16)((para1<< 8) | para0));
            PLIC_SetPriority(IOM_IRQn, 1);
            PLIC_EnableIRQ(IOM_IRQn);
            PLIC_EnableIRQ(IOM_IRQn);
            GPIO_ClrIntFlag(GPIO_ALL);
            IOM->EXT_INTE |= tmp;
            break;
        case IOM_CFG_INT_DIS:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->EXT_INTE &= ~tmp;
            break;
        case IOM_CFG_OUT_DATA_HIGH:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->DATA |= tmp;
            break;
        case IOM_CFG_OUT_DATA_LOW:
            tmp = ((u16)((para1<< 8) | para0));
            IOM->DATA &= ~tmp;
            break;
        default:
            break;
        }
        break;
    case IOM_FUNC_GET_DATA:
    	//打印高8位
    	value = (IOM->DATA) >> 8;
    	iom_info(value);
    	//打印低8位
    	value = (IOM->DATA) & 0x0F;
    	iom_info(value);
        break;
    case IOM_FUNC_GET_STS:
    	//打印高8位
    	value = (IOM->INTF) >> 8;
    	iom_info(value);
    	//打印低8位
    	value = (IOM->INTF) & 0x0F;
    	iom_info(value);
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
}

#endif
