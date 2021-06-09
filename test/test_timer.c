#include "lib_include.h"
#include "test_timer.h"
#include "test_main.h"
#include "timer.h"

#if TEST_TIM_EN

u16 gDel;

void TIMER1_IrqHandler(void)
{
    static int tog;

    if (tog)
    {
        //GPIO_ClrPin(GPIO_PIN14);
    	printf("tog = 1\r\n");
    }
    else
    {
        //GPIO_SetPin(GPIO_PIN14);
    	printf("tog = 0\r\n");
    }
    tog = !tog;

    Timer_ClrIntFlag(TIMER1);
}

void TIMER2_IrqHandler(void)
{
    static int tog;

    if (tog)
    {
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
        GPIO_SetPin(GPIO_PIN14);
    }
    tog = !tog;

    Timer_ClrIntFlag(TIMER2);
}

void TIMER3_IrqHandler(void)
{
    static int tog;

    if (tog)
    {
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
        GPIO_SetPin(GPIO_PIN14);
    }
    tog = !tog;

    Timer_ClrIntFlag(TIMER3);
}

void TIMER4_IrqHandler(void)
{
    static int tog;

    if (tog)
    {
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
        GPIO_SetPin(GPIO_PIN14);
    }
    tog = !tog;

    Timer_ClrIntFlag(TIMER4);

}

void TestModelTimer(void)
{
	u8 func;
	u8 item;
	u8 para0;
	u8 para1;
	u8 para2;
	u8 para3;
	u8 para4;

	u16 Dat;
	u16 freq;
	u16 duty;
	u16 i;

	printf("enter timer func: \r\n");
	func = UART_Receive();

    switch (func)
    {
    case TIMER_FUNC_CFG:
        switch (item)
        {
        case TIMER_CFG_TIMER:
        	switch(para0)
        	{
        	case 0:
        		break;
        	case 1:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER1);
                Timer_Timing_Init(TIMER1, Dat);
                break;
        	case 2:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER2);
                Timer_Timing_Init(TIMER2, Dat);
                break;
        	case 3:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER3);
                Timer_Timing_Init(TIMER3, Dat);
                break;
        	case 4:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER4);
                Timer_Timing_Init(TIMER4, Dat);
                break;
        	default:
        		break;
        	}
            break;
        case TIMER_CFG_CNT:
        	switch(para0)
        	{
        	case 0:
        		break;
        	case 1:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER1);
                Timer_Count_Init(TIMER1, Dat);
                break;
        	case 2:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER2);
                Timer_Count_Init(TIMER2, Dat);
                break;
        	case 3:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER3);
                Timer_Count_Init(TIMER3, Dat);
                break;
        	case 4:
                Dat = (u16)(para2 << 8 | para1);
                gDel = Dat;
                Timer_DeInit(TIMER4);
                Timer_Count_Init(TIMER4, Dat);
                break;
        	default:
        		break;
        	}
            break;
        case TIMER_CFG_PWM:
        	switch(para0)
        	{
        	case 0:
        		break;
        	case 1:
                freq = (u16)(para2 << 8 | para1);
                duty = (u16)(para4 << 8 | para3);
                Timer_DeInit(TIMER1);
                Timer_PWMInit(TIMER1, freq, duty);
                break;
        	case 2:
                freq = (u16)(para2 << 8 | para1);
                duty = (u16)(para4 << 8 | para3);
                Timer_DeInit(TIMER2);
                Timer_PWMInit(TIMER2, freq, duty);
                break;
        	case 3:
                freq = (u16)(para2 << 8 | para1);
                duty = (u16)(para4 << 8 | para3);
                Timer_DeInit(TIMER2);
                Timer_PWMInit(TIMER2, freq, duty);
                break;
        	case 4:
                freq = (u16)(para2 << 8 | para1);
                duty = (u16)(para4 << 8 | para3);
                Timer_DeInit(TIMER2);
                Timer_PWMInit(TIMER2, freq, duty);
                break;
        	default:
        		break;
        	}
            break;
        case TIMER_CFG_IE_CTL:
        	switch(para0)
        	{
        	case 0:
        		break;
        	case 1:
        		 PLIC_SetPriority(TIMER1_IRQn, 1);
        		 PLIC_EnableIRQ(TIMER1_IRQn);
        		 Timer_ClrIntFlag(TIMER1);
        		 if (para1 == 0)
        		 {
        			 Timer_DisableIRQ(TIMER1);
        		 }
        		 else
        		 {
        		     GPIO_PinConfigure(GPIO_PIN14, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
        		     Timer_EnableIRQ(TIMER1);
        		 }
                break;
        	case 2:
       		     PLIC_SetPriority(TIMER2_IRQn, 1);
       		     PLIC_EnableIRQ(TIMER2_IRQn);
       		     Timer_ClrIntFlag(TIMER2);
       		     if (para1 == 0)
       		     {
       			     Timer_DisableIRQ(TIMER2);
       		     }
       		     else
       		     {
       		         GPIO_PinConfigure(GPIO_PIN14, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
       		         Timer_EnableIRQ(TIMER2);
       		     }
                break;
        	case 3:
      		     PLIC_SetPriority(TIMER3_IRQn, 1);
      		     PLIC_EnableIRQ(TIMER3_IRQn);
      		     Timer_ClrIntFlag(TIMER3);
      		     if (para1 == 0)
      		     {
      			     Timer_DisableIRQ(TIMER3);
      		     }
      		     else
      		     {
      		         GPIO_PinConfigure(GPIO_PIN14, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
      		         Timer_EnableIRQ(TIMER3);
      		     }
                break;
        	case 4:
      		     PLIC_SetPriority(TIMER4_IRQn, 1);
      		     PLIC_EnableIRQ(TIMER4_IRQn);
      		     Timer_ClrIntFlag(TIMER4);
      		     if (para1 == 0)
      		     {
      			     Timer_DisableIRQ(TIMER4);
      		     }
      		     else
      		     {
      		         GPIO_PinConfigure(GPIO_PIN14, DISABLE, ENABLE, DISABLE, DISABLE, DISABLE);
      		         Timer_EnableIRQ(TIMER4);
      		     }
                break;
        	default:
        		break;
        	}
            break;
        default:
            break;
        }
        break;
    case TIMER_FUNC_PAUSE_TIM1:
        break;
    case TIMER_FUNC_RESTORE_TIM1:
        break;
    case TIMER_FUNC_PAUSE_TIM2:
        break;
    case TIMER_FUNC_RESTORE_TIM2:
        break;
    case TIMER_FUNC_PAUSE_TIM3:
        break;
    case TIMER_FUNC_RESTORE_TIM3:
        break;
    case TIMER_FUNC_PAUSE_TIM4:
        break;
    case TIMER_FUNC_RESTORE_TIM4:
        break;
    case TIMER_FUNC_RUN_TIM1:
    	Timer_EnableControl(TIMER1, ENABLE);
        break;
    case TIMER_FUNC_STOP_TIM1:
    	Timer_EnableControl(TIMER1, DISABLE);
        break;
    case TIMER_FUNC_RUN_TIM2:
    	Timer_EnableControl(TIMER2, ENABLE);
        break;
    case TIMER_FUNC_STOP_TIM2:
    	Timer_EnableControl(TIMER2, DISABLE);
        break;
    case TIMER_FUNC_RUN_TIM3:
    	Timer_EnableControl(TIMER3, ENABLE);
        break;
    case TIMER_FUNC_STOP_TIM3:
    	Timer_EnableControl(TIMER3, DISABLE);
        break;
    case TIMER_FUNC_RUN_TIM4:
    	Timer_EnableControl(TIMER4, ENABLE);
        break;
    case TIMER_FUNC_STOP_TIM4:
    	Timer_EnableControl(TIMER4, DISABLE);
        break;
    case TIMER_FUNC_TIMING:
    	break;
    case TIMER_FUNC_COUNT:
    	break;
    case TIMER_FUNC_PWM:
    	printf("choose pwm: 1-4\r\n");
    	item = UART_Receive();

    	switch(item)
    	{
    	case TIMER1:
    		GPIO_PinSelect(GPIO_PIN14, PIN_FUNC_3);
    		Timer_PWMInit(TIMER1, 400, 0xFF);
            PLIC_EnableIRQ(TIMER1_IRQn);
            PLIC_SetPriority(TIMER1_IRQn, 1);
            Timer_EnableIRQ(TIMER1);
            Timer_EnableControl(TIMER1, ENABLE);
            Timer_ClrIntFlag(TIMER1);
            printf("pwm 1 enable\r\n");
            break;
    	case TIMER2:
    		Timer_PWMInit(TIMER2, 400, 0xFF);
            PLIC_EnableIRQ(TIMER2_IRQn);
            PLIC_SetPriority(TIMER2_IRQn, 1);
            Timer_EnableIRQ(TIMER2);
            Timer_EnableControl(TIMER2, ENABLE);
            Timer_ClrIntFlag(TIMER2);
            printf("pwm 2 enable\r\n");
    		break;
    	case TIMER3:
    		Timer_PWMInit(TIMER3, 400, 0xFF);
            PLIC_EnableIRQ(TIMER3_IRQn);
            PLIC_SetPriority(TIMER3_IRQn, 1);
            Timer_EnableIRQ(TIMER3);
            Timer_EnableControl(TIMER3, ENABLE);
            Timer_ClrIntFlag(TIMER3);
            printf("pwm 3 enable\r\n");
    		break;
    	case TIMER4:
    		Timer_PWMInit(TIMER4, 400, 0xFF);
            PLIC_EnableIRQ(TIMER4_IRQn);
            PLIC_SetPriority(TIMER4_IRQn, 1);
            Timer_EnableIRQ(TIMER4);
            Timer_EnableControl(TIMER4, ENABLE);
            Timer_ClrIntFlag(TIMER4);
            printf("pwm 4 enable\r\n");
    		break;
    	}
        break;
    case TIMER_FUNC_PWM_BREATHE:
        printf("choose pwm: 1-4\r\n");
        item = UART_Receive();

        switch (item)
        {
        case TIMER1:
            GPIO_PinSelect(GPIO_PIN14, PIN_FUNC_3);
            GPIO_PinConfigure(GPIO_PIN14, ENABLE, ENABLE, ENABLE, DISABLE,ENABLE);
            for (i = 0; i < 0xFFFF; i++)
            {
                Timer_PWMInit(TIMER1, 400, i);
                PLIC_EnableIRQ(TIMER1_IRQn);
                PLIC_SetPriority(TIMER1_IRQn, 1);
                Timer_EnableIRQ(TIMER1);
                Timer_EnableControl(TIMER1, ENABLE);
                Timer_ClrIntFlag(TIMER1);
            }
            printf("pwm 1 breathe\r\n");
            break;
        case TIMER2:
            Timer_PWMInit(TIMER2, 400, 0xFF);
            PLIC_EnableIRQ(TIMER2_IRQn);
            PLIC_SetPriority(TIMER2_IRQn, 1);
            Timer_EnableIRQ(TIMER2);
            Timer_EnableControl(TIMER2, ENABLE);
            Timer_ClrIntFlag(TIMER2);
            printf("pwm 2 enable\r\n");
            break;
        case TIMER3:
            Timer_PWMInit(TIMER3, 400, 0xFF);
            PLIC_EnableIRQ(TIMER3_IRQn);
            PLIC_SetPriority(TIMER3_IRQn, 1);
            Timer_EnableIRQ(TIMER3);
            Timer_EnableControl(TIMER3, ENABLE);
            Timer_ClrIntFlag(TIMER3);
            printf("pwm 3 enable\r\n");
            break;
        case TIMER4:
            Timer_PWMInit(TIMER4, 400, 0xFF);
            PLIC_EnableIRQ(TIMER4_IRQn);
            PLIC_SetPriority(TIMER4_IRQn, 1);
            Timer_EnableIRQ(TIMER4);
            Timer_EnableControl(TIMER4, ENABLE);
            Timer_ClrIntFlag(TIMER4);
            printf("pwm 4 enable\r\n");
            break;
        }
        break;
    default:
        break;
    }
}
#endif
