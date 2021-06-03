#include "test_uart.h"
#include "test_main.h"
#include "uart.h"
#include <stdio.h>

#if TEST_UART_EN

void TestModelUART(u8 func, u8 item, u8 para0, u8 para1, u8 para2)
{
    u16 Dat;
    u16 Baud;

    switch (func)
    {
    case UART_FUNC_CFG:
        switch (item)
        {
        case UART_CFG_PARA:
            Baud = (u16)(para2 << 8 | para1);
            UART_DeInit();
            UART_Init(para0, Baud);
            UART_EnableControl(UART_EN_TYPE_REN);
            break;
        case UART_CFG_RCV_VRF:
            UART_RcvVerifyCfg(para1);
            break;
        case UART_CFG_CTL:
            UART_EnableControl(para1);
            break;
        case UART_CFG_IE_CTL:
            if (para1)
            {
                PLIC_SetPriority(UART1_IRQn, 1);
                PLIC_EnableIRQ(UART1_IRQn);
                UART_ClrIntFlag(0xff);
                UART_EnableIRQ(para2);
            }
            else
            {
                UART_DisableIRQ(para2);
            }
            break;
        case UART_CFG_SEND_DAT:
            Dat = (u16)(para2 << 8 | para1) ;
            UART_WriteData(Dat);
            break;
        case UART_CFG_ADDR_MSK:
            UART_SetAddrAndMask(para1, para2);
            break;
        default:
            break;
        }
        break;
    case UART_FUNC_RD1_DAT:
        printf("%x", UART_ReadData());
        break;
    case UART_FUNC_RD1_STS:
        printf("%x", UART_GetIntFlag());
        break;
    case UART_FUNC_CLR1_STS:
        UART_ClrIntFlag(0xff);
        break;
    default:
        break;
    }
}
#endif //TEST_UART_EN

