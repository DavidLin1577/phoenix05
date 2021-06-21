#include "test_efc.h"
#include "lib_include.h"
#include "test_main.h"

#if TEST_EFC_EN

void EFC_IrqHandler(void)
{
	if (EFC->STS & EFC_STS_ADDRE)
	{
		GPIO_SetPin(GPIO_PIN14);
		EFC->STS &= ~0x04;
	}
	if (EFC->STS & EFC_STS_FCE)
	{
		GPIO_SetPin(GPIO_PIN14);
	}                    
	if (EFC->STS & EFC_STS_CD)
	{
		GPIO_SetPin(GPIO_PIN14);
	}
}

void TestModelEFC(void)
{
	u8 func;
	u8 item;
	u8 type;
	u8 para[10] = {0};

    u8 value;
    u8 i;
    u32 Addr;

    u32 Dat;

	func     = UART_Receive();
    switch (func)
    {
    case EFC_FUNC_INIT:
    	EFC_Init();
		printf("EFC_Init\n");
		break;
    case EFC_FUNC_CFG:
    	//printf("EFC_CFG_SIG_PRG  (0)\n");
    	//printf("EFC_CFG_RD       (1)\n");
    	//printf("EFC_CFG_PG_ERS   (2)\n");
    	item     = UART_Receive();
        switch (item)
        {
        case EFC_CFG_SIG_PRG:
        	//Flash地址起始地址是0x2000,因为存储有代码，所以测试地址注意避开已经使用的区间，比如测试0x2000偏移10K的地址,0x4800
        	//printf("choose type: byte(0), halfword(1), word(2)\n");
        	type     = UART_Receive();
            switch(type)
            {
            case EFC_PRG_BYTE:
            	printf("byte: 0x00 - 0xff\r\n");
            	para[0]  = UART_Receive();
            	Dat = para[0];
            	Addr = 0x2000+0x2800;
            	break;
            case EFC_PRG_HWORD:
            	printf("half word: 0x0000 - 0xffff\n");
            	printf("high byte: 0x00 - 0xff\n");
            	para[0]  = UART_Receive();
            	printf("%x\r\n", para[0]);
            	printf("low  byte: 0x00 - 0xff\n");
            	para[1]  = UART_Receive();
            	printf("%x\r\n", para[1]);
            	Dat = ((u16)(para[0] << 8) | para[1]);
            	printf("Dat = %x\r\n", Dat);
            	Addr = 0x2000+0x2800;
                break;
            case EFC_PRG_WORD:
            	Dat = 0xa5a5a5a5;
            	Addr = 0x2000+0x2800;
            	break;
            default:
            	Dat = 0x00000000;
            	Addr = 0x2000+0x2800;
            	break;
            }

            if( EFC_SingleProgram(Addr, type, Dat) != EFC_SUCCESS)
            {
            	printf("write flash error\n");
            }
            else
            {
            	printf("REG32(%x) %x\n", Addr, REG32(Addr));
            }

            break;
        case EFC_CFG_RD:
        	printf("address: 0x2000 - 0x5fff\n");
        	printf("high addr: 0x00 - 0xff\n");
        	para[0]  = UART_Receive();
        	printf("low  addr: 0x00 - 0xff\n");
        	para[1]  = UART_Receive();
        	Addr = ((u16)(para[0] << 8) | para[1]);
            printf("%x", REG32(Addr));
            break;
        case EFC_CFG_PG_ERS:
        	printf("address: 0x2000 - 0x5fff\n");
        	printf("high addr: 0x00 - 0xff\n");
        	para[0]  = UART_Receive();
        	printf("low  addr: 0x00 - 0xff\n");
        	para[1]  = UART_Receive();
        	Addr = ((u16)(para[0] << 8) | para[1]);
            if (EFC_PageErase(Addr) != EFC_SUCCESS)
            {
            	printf("erase flash error\n");
            }
            break;

        default:
            break;
        }
        break;
    case EFC_FUNC_CHP_ERS:
        if( EFC_ChipErase(0x00002000) != EFC_SUCCESS)
        {
        	printf("erase chip error\n");
        }
        break;
    case EFC_FUNC_RD_STS:
    	printf("EFC->STS %x\n", EFC->STS);
        break;
	case EFC_FUNC_INT:
		PLIC_EnableIRQ(EFC_IRQn);
		PLIC_SetPriority(EFC_IRQn, 1);
	    EFC_EnableIRQ();
		item = UART_Receive();
		printf("item   %x\n", item);
		switch (item)
		{
		case EFC_CFG_ADDREINTEN:
			EFC_SingleProgram(0xAFFF, EFC_PRG_WORD, 0x5a5aa5a5);
			break;
		case EFC_CFG_FCINTEN:
			if (EFC_SingleProgram(0x4800, EFC_PRG_WORD, 0x5a5aa5a5) != EFC_SUCCESS)
			{
				printf("write flash error\n");
			}
			break;
		default:
			break;
		}
		break;
	default:
        break;
    }
}

#endif
