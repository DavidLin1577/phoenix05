#include "test_main.h"
#include "lib_include.h"
#include "demo.h"
#include "test_wdt.h"

#define TEST_DEBUG_EN        (1)

char test_info[20] = {'p','h','o','e','n','i','x','0','5',' ','t', 'e', 's','t','\r'};

static void input_info(u8 model, u8 func, u8 item, u8 para)
{
	u8 i;
	u8 model_msg[10] = {'m','o','d','e','l','=',' '};
	u8 func_msg[10]  = {'f','u','n','c',' ','=',' '};
	u8 item_msg[10]  = {'i','t','e','m',' ','=',' '};
	u8 para_msg[10]  = {'p','a','r','a',' ','=',' '};

	//model
	model_msg[7] = model + '0';
	model_msg[8] = '\r';
    for(i = 0; i < sizeof(model_msg);i++)
    {
        UART_Send(model_msg[i]);
    }
	//func
    func_msg[7] = func + '0';
    func_msg[8] = '\r';
    for(i = 0; i < sizeof(func_msg);i++)
    {
        UART_Send(func_msg[i]);
    }
	//item
    item_msg[7] = item + '0';
    item_msg[8] = '\r';
    for(i = 0; i < sizeof(item_msg);i++)
    {
        UART_Send(item_msg[i]);
    }
	//para
	para_msg[7] = para + '0';
	para_msg[8] = '\r';
    for(i = 0; i < sizeof(para_msg);i++)
    {
        UART_Send(para_msg[i]);
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

static void test_fail(void)
{
	u8 i;
	u8 msg[10]  = {'t','e','s','t',' ', 'f','a','i','l','\r'};
    for(i = 0; i < sizeof(msg);i++)
    {
        UART_Send(msg[i]);
    }
}

int test_entry(void)
{
#if TEST_DEBUG_EN

	 u8 recv_header;
	 u8 model;
	 u8 func;
	 u8 item;
	 u8 para;

	 int i;

	 GPIO_PinConfigure(LED_RED, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);

	 GPIO_PinSelect(UART1_RX | UART1_TX, PIN_FUNC_1);
	 UART_Init(UART_MODE_10B_ASYNC, 9600);
	 for(i = 0; i < sizeof(test_info);i++)
	 {
		 UART_Send(test_info[i]);
	 }

	 while(1)
	 {
		 recv_header =  UART_Receive();

		 if(recv_header == 0xcc)
		 {
			 LED_OFF(LED_RED);
			 model = UART_Receive();
			 func  = UART_Receive();
			 item  = UART_Receive();
			 para  = UART_Receive();

			 input_info(model, func, item, para);

			 switch(model)
			 {
			 case MODEL_CTL:
				 switch(func)
				 {
				 case CTRL_FUNC_CORE_RST:
					 LED_ON(LED_RED);
					 test_pass();
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
				 break;
			 case MODEL_IOM:
				 TestModelIOM(func, item, para);
				 test_pass();
				 break;
			 case MODEL_WDT:
				 TestModelWDT(func, item, para);
				 test_pass();
				 break;
			 case MODEL_LPTIMER:
				 break;
			 case MODEL_TIMER:
				 break;
			 case MODEL_UART:
				 break;
			 case MODEL_EFC:
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

