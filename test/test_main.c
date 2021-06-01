#include "test_main.h"
#include "lib_include.h"
#include "demo.h"
#include "test_wdt.h"
#include "test_iom.h"
#include "test_efc.h"

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
	model_msg[8] = '\t';
    for(i = 0; i < sizeof(model_msg);i++)
    {
        UART_Send(model_msg[i]);
    }
	//func
    func_msg[7] = func + '0';
    func_msg[8] = '\t';
    for(i = 0; i < sizeof(func_msg);i++)
    {
        UART_Send(func_msg[i]);
    }
	//item
    item_msg[7] = item + '0';
    item_msg[8] = '\t';
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

static void input_para(u8 para0, u8 para1, u8 para2, u8 para3)
{
	u8 i;
	u8 para_msg[20]  = {'p','a','r','a',' ','=',' '};

	para_msg[7]  = para0 + '0';
	para_msg[8]  = ',';

    para_msg[9]  = para1 + '0';
    para_msg[10] = ',';

    para_msg[11] = para2 + '0';
    para_msg[12] = ',';

    para_msg[13] = para3 + '0';
    para_msg[14] = '\r';
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
	 u8 para[10] = {0};

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

			 switch(model)
			 {
			 case MODEL_CTL:
				 func     = UART_Receive();
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
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 input_info(model, func, item, para[0]);
				 input_para(para[0], para[1], para[2], 0);
				 TestModelIOM(func, item, para[0], para[1], para[2]);
				 test_pass();
				 break;
			 case MODEL_WDT:
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 input_info(model, func, item, para[0]);
				 input_para(para[0], para[1], para[2], 0);
				 TestModelWDT(func, item, para[0], para[1], para[2]);
				 test_pass();
				 break;
			 case MODEL_LPTIMER:
				 break;
			 case MODEL_TIMER:
				 break;
			 case MODEL_UART:
				 break;
			 case MODEL_EFC:
				 func     = UART_Receive();
				 item     = UART_Receive();
				 para[0]  = UART_Receive();
				 para[1]  = UART_Receive();
				 para[2]  = UART_Receive();
				 para[3]  = UART_Receive();
				 input_info(model, func, item, para[0]);
				 input_para(para[0], para[1], para[2], para[3]);
				 TestModelEFC(func, item, para[0], para[1], para[2], para[3]);
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

