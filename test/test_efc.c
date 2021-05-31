#include "test_efc.h"

#include "lib_include.h"
#include "test_main.h"

#if 0
void TestModelEFC(u8 *pu8Dat)
{
    EFC_Init();
    switch (pu8Dat[FUNC])
    {
    case EFC_FUNC_CFG:
        switch (pu8Dat[ITEM])
        {
        case EFC_CFG_SIG_PRG: {
            u32 Addr = ((u32)pu8Dat[PARM + 3] << 24) | ((u32)pu8Dat[PARM + 2] << 16) | ((u32)pu8Dat[PARM + 1] << 8) |
                         pu8Dat[PARM];
            u8   type  = pu8Dat[PARM + 4];
            u32 Dat  = ((u32)pu8Dat[PARM + 8] << 24) | ((u32)pu8Dat[PARM + 7] << 16) | ((u32)pu8Dat[PARM + 6] << 8) |
                        pu8Dat[PARM+5];
            ;
            if( EFC_SingleProgram(Addr, type, Dat) != EFC_SUCCESS)
            {
                printf("fail");
            }
        }
        break;
        case EFC_CFG_RD: {
            u32 Addr = ((u32)pu8Dat[PARM + 3] << 24) | ((u32)pu8Dat[PARM + 2] << 16) | ((u32)pu8Dat[PARM + 1] << 8) |
                         pu8Dat[PARM];
            ;
            printf("%x", REG32(Addr));
        }
        break;
        case EFC_CFG_PG_ERS: {
            u32 Addr = ((u32)pu8Dat[PARM + 3] << 24) | ((u32)pu8Dat[PARM + 2] << 16) | ((u32)pu8Dat[PARM + 1] << 8) |
                         pu8Dat[PARM];
            ;
            if (EFC_PageErase(Addr) != EFC_SUCCESS)
            {
                printf("fail");
            }
        }
        break;

        default:
            break;
        }
        break;
    case EFC_FUNC_CHP_ERS:
        if( EFC_ChipErase(0x10100000) != EFC_SUCCESS)
        {
            printf("fail");
        }
        break;
    case EFC_FUNC_RD_STS:
    	printf("%x", EFC->STS);
        break;

    default:
        break;
    }
}
#endif
