#include "lib_include.h"
#include "test_timer.h"
#include "test_main.h"
#include "timer.h"

#if TEST_TIM_EN

u16 gDel;

void TIMER1_IrqHandler(void)
{
    static int tog;
    Timer_ClrIntFlag(TIMER1);
    Timer_DeInit(TIMER1);
    Timer_Timing_Init(TIMER1, gDel);
    Timer_EnableControl(TIMER1, ENABLE);
    if (tog)
    {
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
        GPIO_SetPin(GPIO_PIN14);
    }
    tog = !tog;
}

void TIMER2_IrqHandler(void)
{
    static int tog;
    Timer_ClrIntFlag(TIMER2);
    Timer_DeInit(TIMER2);
    Timer_Timing_Init(TIMER2, gDel);
    Timer_EnableControl(TIMER2, ENABLE);
    if (tog)
    {
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
        GPIO_SetPin(GPIO_PIN14);
    }
    tog = !tog;
}

void TIMER3_IrqHandler(void)
{
    static int tog;
    Timer_ClrIntFlag(TIMER3);
    Timer_DeInit(TIMER3);
    Timer_Timing_Init(TIMER3, gDel);
    Timer_EnableControl(TIMER3, ENABLE);
    if (tog)
    {
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
        GPIO_SetPin(GPIO_PIN14);
    }
    tog = !tog;
}

void TIMER4_IrqHandler(void)
{
    static int tog;
    Timer_ClrIntFlag(TIMER4);
    Timer_DeInit(TIMER4);
    Timer_Timing_Init(TIMER4, gDel);
    Timer_EnableControl(TIMER4, ENABLE);
    if (tog)
    {
        GPIO_ClrPin(GPIO_PIN14);
    }
    else
    {
        GPIO_SetPin(GPIO_PIN14);
    }
    tog = !tog;
}

void TestModelTimer(u8 func, u8 item, u8 para0, u8 para1, u8 para2, u8 para3, u8 para4)
{
	u16 Dat;
	u16 freq;
	u16 duty;

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
    default:
        break;
    }
}
#endif
