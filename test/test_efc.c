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

static void test_pass(void)
{
	u8 i;
	u8 msg[10]  = {'t','e','s','t',' ', 'o','k','\r'};
    for(i = 0; i < sizeof(msg);i++)
    {
        UART_Send(msg[i]);
    }
}

void TestModelEFC(u8 func, u8 item, u8 para0, u8 para1, u8 para2, u8 para3)
{
    u8 value;
    u32 Addr;
    u8 type;
    u32 Dat;

    switch (func)
    {
    case EFC_FUNC_INIT:
    	EFC_Init();
    	break;
    case EFC_FUNC_CFG:
        switch (item)
        {
        case EFC_CFG_SIG_PRG:
        	//Flash地址起始地址是0x2000,因为存储有代码，所以测试地址注意避开已经使用的区间，比如测试0x2000偏移10K的地址,0x4800
            Addr = ((u32)(para0 << 8) | para1);
            REG32(TEST_EFC_BASE) = Addr;
            type  = para2;
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
            	Dat = 0xffffffff;
            	break;
            }
            if( EFC_SingleProgram(Addr, type, Dat) != EFC_SUCCESS)
            {
            	test_fail();
            }
            else
            {
            	test_pass();
            }
            break;
        case EFC_CFG_RD:
        	Addr = ((u32)(para0 << 8) | para1);
            //printf("%x", REG32(Addr));
        	//通过putty查看Address对应值
            break;
        case EFC_CFG_PG_ERS:
        	Addr = ((u32)(para0 << 8) | para1);
            if (EFC_PageErase(Addr) != EFC_SUCCESS)
            {
            	test_fail();
            }
            else
            {
            	test_pass();
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
