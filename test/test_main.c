#include "test_main.h"
#include "lib_include.h"
#include "demo.h"
#include "test_wdt.h"
#include "test_iom.h"
#include "test_efc.h"
#include "test_lptimer.h"
#include "test_uart.h"

#define TEST_DEBUG_EN        (1)

int test_entry(void)
{
#if TEST_DEBUG_EN

	 u8 recv_header;
	 u8 model;
	 u8 func;
	 u8 item;
	 u8 para[10] = {0};

	 while(1)
	 {
		 recv_header =  UART_Receive();

		 if(recv_header == 0xcc)
		 {
			 LED_OFF(LED_RED);
			 model = UART_Receive();

			 switch(model)
			 {
			 case MODEL_CTL:
                 #if TEST_CTL_EN
				 func     = UART_Receive();
				 switch(func)
				 {
				 case CTRL_FUNC_CORE_RST:
					 LED_ON(LED_RED);
					 break;
				 case CTRL_FUNC_CHIP_RST:
					 LED_OFF(LED_RED);
					 break;
				 case CTRL_FUNC_DIG_RST:
					 LED_ON(LED_RED);
					 break;
				 case CTRL_FUNC_CFG:
					 LED_OFF(LED_RED);
					 break;
				 default:
					 break;
				 }
                 #endif
				 break;
			 case MODEL_IOM:
                 #if TEST_IOM_EN
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 TestModelIOM(func, item, para[0], para[1], para[2]);
                 #endif
				 break;
			 case MODEL_WDT:
                 #if TEST_WDT_EN
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 TestModelWDT(func, item, para[0], para[1], para[2]);
                 #endif
				 break;
			 case MODEL_LPTIMER:
                 #if TEST_LPT_EN
                 func     = UART_Receive();
                 item     = UART_Receive();
                 para[0]  = UART_Receive();
                 para[1]  = UART_Receive();
                 para[2]  = UART_Receive();
                 TestModelLPT(func, item, para[0], para[1], para[2]);
                 #endif
				 break;
			 case MODEL_TIMER:
                 #if TEST_TIM_EN
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 para[3]  = UART_Receive();
				 para[4]  = UART_Receive();
				 TestModelTimer(func, item, para[0], para[1], para[2], para[3], para[4]);
                 #endif
				 break;
			 case MODEL_UART:
                 #if TEST_UART_EN
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 TestModelUART(func, item, para[0], para[1], para[2]);
                 #endif
				 break;
			 case MODEL_EFC:
                 #if TEST_EFC_EN
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 para[3]  = UART_Receive();
				 TestModelEFC(func, item, para[0], para[1], para[2], para[3]);
			     #endif
				 break;
			 case MODEL_SYSC:
				 break;
			 case MODEL_PMU:
				 break;
			 default:
				 break;
			 }
		 }
	 }

#endif
    return 0;
}

