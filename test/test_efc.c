#include "test_efc.h"

#include "lib_include.h"
#include "test_main.h"

static void efc_info(u8 value)
{
	u8 i;
	u8 msg[20]  = {'e', 'f', 'c', ' ', 'i', 'n', 'f', 'o', ':'};

    msg[10] = value + '0';
    msg[11] = '\r';
    for(i = 0; i < sizeof(msg);i++)
    {
        UART_Send(msg[i]);
    }
}

static void test_fail(void)
{
	u8 i;
	u8 msg[10]  = {'e','f','c',' ',' ', 'f','a','i','l','\r'};
    for(i = 0; i < sizeof(msg);i++)
    {
        UART_Send(msg[i]);
    }
}

void TestModelEFC(u8 func, u8 item, u8 para0, u8 para1, u8 para2, u8 para3, u8 para4)
{
    u8 value;
    u32 Addr;
    u8 type;
    u32 Dat;

    EFC_Init();

    switch (func)
    {
    case EFC_FUNC_CFG:
        switch (item)
        {
        case EFC_CFG_SIG_PRG:
            Addr = ((u32)(para3 << 24) | (u32)(para2 << 16) | (u32)(para1 << 8) |para0);
            type  = para4;
            switch(type)
            {
            case EFC_PRG_BYTE:
            	Dat = 0x55;
            	break;
            case EFC_PRG_HWORD:
            	Dat = 0x5a5a;
                break;
            case EFC_PRG_WORD:
            	Dat = 0xa5a5a5a5;
            	break;
            default:
            	break;
            }
            if( EFC_SingleProgram(Addr, type, Dat) != EFC_SUCCESS)
            {
            	test_fail();
            }
            break;
        case EFC_CFG_RD:
        	Addr = ((u32)(para3 << 24) | (u32)(para2 << 16) | (u32)(para1 << 8) |para0);
            //printf("%x", REG32(Addr));
        	//通过putty查看Address对应值
            break;
        case EFC_CFG_PG_ERS:
        	Addr = ((u32)(para3 << 24) | (u32)(para2 << 16) | (u32)(para1 << 8) |para0);
            if (EFC_PageErase(Addr) != EFC_SUCCESS)
            {
            	test_fail();
            }
            break;

        default:
            break;
        }
        break;
    case EFC_FUNC_CHP_ERS:
        if( EFC_ChipErase(0x00002000) != EFC_SUCCESS)
        {
        	test_fail();
        }
        break;
    case EFC_FUNC_RD_STS:
    	efc_info(EFC->STS);
        break;
    default:
        break;
    }
}
