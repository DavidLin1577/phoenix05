/**
 * @file timer.c
 * @author David Lin
 * @brief
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Fanhai Data Tech. (c) 2021
 *
 */

#include "sysc.h"
#include "timer.h"
#include "iom.h"

/**
 * @brief  timer init
 *
 * @param timer :timer 0-4
 * @param del :us
 */
void Timer_Init(timer_t timer,int del)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));

    switch(timer)
    {
    case TIMER0:
    	//TODO
    	break;
    case TIMER1:
    	//TODO
    	break;
    case TIMER2:
    	//TODO
    	break;
    case TIMER3:
    	//TODO
    	break;
    case TIMER4:
    	//TODO
    	break;
    default:
    	break;
    }
}

/**
 * @brief pwm init
 *
 * @param timer :timer 0-4
 * @param pwmPolarity :TIM_PMW_POL_xxxx;
 * @param freq : Hz
 * @param duty :exp:duty=50 (50%)
 * @param portSel :TIMN_PWM_PORT_xxxx;
 * @param dtGap :us
 */
void Timer_PWMInit(timer_t timer, int pwmPolarity, int freq, int duty,int dtGap)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));

    switch(timer)
    {
    case TIMER0:
    	//TODO
    	break;
    case TIMER1:
    	//TODO
    	break;
    case TIMER2:
    	//TODO
    	break;
    case TIMER3:
    	//TODO
    	break;
    case TIMER4:
    	//TODO
    	break;
    default:
    	break;
    }
}
/**
 * @brief Timer deinit
 *
 * @param timer:timer 0-4
 */
void Timer_DeInit(timer_t timer)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));

    switch(timer)
    {
    case TIMER0:
    	//TODO
    	break;
    case TIMER1:
    	//TODO
    	break;
    case TIMER2:
    	//TODO
    	break;
    case TIMER3:
    	//TODO
    	break;
    case TIMER4:
    	//TODO
    	break;
    default:
    	break;
    }
}
/**
 * @brief timer enable control
 *
 * @param timer : timer 0-4
 * @param iCtrl ENABLE or DISABLE
 */
void Timer_EnableControl(timer_t timer, int iCtrl)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));
    switch(timer)
    {
    case TIMER0:
    	TIMERS->TIF = (1 << 0);
    	if(iCtrl == ENABLE)
    	{
    		TIMERS->T0CR |= TIMER0_CTRL_EN;
    	}
    	else
    	{
    		TIMERS->T0CR &= ~TIMER0_CTRL_EN;
    	}
    	break;
    case TIMER1:
    	if(iCtrl == ENABLE)
    	{
    		TIMERS->TCR1 |= TIMER1_CTRL_EN;
    	}
    	else
    	{
    		TIMERS->TCR1 &= ~TIMER1_CTRL_EN;
    	}
    	break;
    case TIMER2:
    	if(iCtrl == ENABLE)
    	{
    		TIMERS->TCR2 |= TIMER2_CTRL_EN;
    	}
    	else
    	{
    		TIMERS->TCR2 &= ~TIMER2_CTRL_EN;
    	}
    	break;
    case TIMER3:
    	if(iCtrl == ENABLE)
    	{
    		TIMERS->TCR3 |= TIMER3_CTRL_EN;
    	}
    	else
    	{
    		TIMERS->TCR3 &= ~TIMER3_CTRL_EN;
    	}
    	break;
    case TIMER4:
    	if(iCtrl == ENABLE)
    	{
    		TIMERS->TCR4 |= TIMER4_CTRL_EN;
    	}
    	else
    	{
    		TIMERS->TCR4 &= ~TIMER4_CTRL_EN;
    	}
    	break;
    default:
    	break;
    }
}
/**
 * @brief Timer interrupt enable
 *
 * @param timer:timer 0-4
 */
void Timer_EnableIRQ(timer_t timer)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));
    switch(timer)
    {
    case TIMER0:
    	TIMERS->TIE |= (1 << 0);
    	break;
    case TIMER1:
    	TIMERS->TIE |= (1 << 1);
    	break;
    case TIMER2:
    	TIMERS->TIE |= (1 << 2);
    	break;
    case TIMER3:
    	TIMERS->TIE |= (1 << 3);
    	break;
    case TIMER4:
    	TIMERS->TIE |= (1 << 4);
    	break;
    default:
    	break;
    }
}

/**
 * @brief Timer interrupt disable
 *
 * @param timer:timer 0-4
 */
void Timer_DisableIRQ(timer_t timer)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));
    switch(timer)
    {
    case TIMER0:
    	TIMERS->TIE &= ~(1 << 0);
    	break;
    case TIMER1:
    	TIMERS->TIE &= ~(1 << 1);
    	break;
    case TIMER2:
    	TIMERS->TIE &= ~(1 << 2);
    	break;
    case TIMER3:
    	TIMERS->TIE &= ~(1 << 3);
    	break;
    case TIMER4:
    	TIMERS->TIE &= ~(1 << 4);
    	break;
    default:
    	break;
    }
}


/**
 * @brief get timer interrupt flag
 *
 * @param timer :timer 0-4
 * @return FlagStatus : SET , RESET
 */
FlagStatus Timer_GetIntFlag(timer_t timer)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));

    int ret = RESET;

    if(TIMER0 == timer)
    {
    	ret =  (TIMERS->TIF & (1 << 0) ? SET : RESET);
    }
    else if(TIMER1 == timer)
    {
    	ret =  (TIMERS->TIF & (1 << 1) ? SET : RESET);
    }
    else if(TIMER2 == timer)
    {
    	ret =  (TIMERS->TIF & (1 << 2) ? SET : RESET);
    }
    else if(TIMER3 == timer)
    {
    	ret =  (TIMERS->TIF & (1 << 3) ? SET : RESET);
    }
    else if(TIMER4 == timer)
    {
    	ret =  (TIMERS->TIF & (1 << 4) ? SET : RESET);
    }

    return (FlagStatus)ret;
}
/**
 * @brief clear timer interrupt flag
 *
 * @param timer :timer 0-4
 */
void Timer_ClrIntFlag(timer_t timer)
{
    PARAM_CHECK((timer != TIMER0) && (timer != TIMER1) && (timer != TIMER2) &&
                (timer != TIMER3)&&(timer != TIMER4));

    switch(timer)
    {
    case TIMER0:
    	TIMERS->TIF = (1 << 0);
    	break;
    case TIMER1:
    	TIMERS->TIF = (1 << 1);
    	break;
    case TIMER2:
    	TIMERS->TIF = (1 << 2);
    	break;
    case TIMER3:
    	TIMERS->TIF = (1 << 3);
    	break;
    case TIMER4:
    	TIMERS->TIF = (1 << 4);
    	break;
    default:
    	break;
    }
}
