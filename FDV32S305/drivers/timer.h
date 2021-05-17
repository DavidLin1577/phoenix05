/**
 * @file timer.h
 * @author David Lin
 * @brief
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Fanhai Data Tech. (c) 2021
 *
 */
#ifndef __TIMER_H__
#define __TIMER_H__
#include "../include/phnx05.h"

typedef enum timer
{
    TIMER0 = 0,
	TIMER1 = 1,
	TIMER2 = 2,
	TIMER3 = 3,
	TIMER4 = 4,
	TIMER_MAX,
} timer_t;

// reg bit definitions
#define TIM_PWCON_PWMCPOL BITS(17, 18)
#define TIM_PWCON_DTEN BITS(16)
#define TIM_PWCON_DTUGAP BITS(0, 15)

#define TIM_PWCON_PWMCPOL_pos (17) // 0-3

#define TIM_PWCON_DTUGAP_pos (0) // 0-0xffff

#define TIM_CON_PAUSE BITS(24, 27)
#define TIM_CON_PAUSE_TIM1 BIT(24)
#define TIM_CON_PAUSE_TIM2 BIT(25)
#define TIM_CON_PAUSE_TIM3 BIT(26)
#define TIM_CON_PAUSE_TIM4 BIT(27)

#define TIM_CON_EXTPOL BITS(20, 23)
#define TIM_CON_EXTPOL_TIM1 BIT(20)

#define TIM_CON_EXTPOL_TIM2 BIT(21)
#define TIM_CON_EXTPOL_TIM3 BIT(22)
#define TIM_CON_EXTPOL_TIM4 BIT(23)

#define TIM_CON_EXTEN BITS(16, 19)
#define TIM_CON_EXTEN_TIM1 BIT(16)
#define TIM_CON_EXTEN_TIM2 BIT(17)
#define TIM_CON_EXTEN_TIM3 BIT(18)
#define TIM_CON_EXTEN_TIM4 BIT(19)

#define TIM_CON_PWM BITS(12, 15)
#define TIM_CON_PWM_TIM1 BIT(12)
#define TIM_CON_PWM_TIM2 BIT(13)
#define TIM_CON_PWM_TIM3 BIT(14)
#define TIM_CON_PWM_TIM4 BIT(15)

#define TIM_CON_IE BITS(8, 11)
#define TIM_CON_IE_TIM1 BIT(8)
#define TIM_CON_IE_TIM2 BIT(9)
#define TIM_CON_IE_TIM3 BIT(10)
#define TIM_CON_IE_TIM4 BIT(11)

#define TIM_CON_TM BITS(4, 7)
#define TIM_CON_TM_TIM1 BIT(4)
#define TIM_CON_TM_TIM2 BIT(5)
#define TIM_CON_TM_TIM3 BIT(6)
#define TIM_CON_TM_TIM4 BIT(7)


#define TIM_INTFLAG BITS(0, 3)
#define TIM_INTFLAG_TIM1 BIT(0)
#define TIM_INTFLAG_TIM2 BIT(1)
#define TIM_INTFLAG_TIM3 BIT(2)
#define TIM_INTFLAG_TIM4 BIT(3)

#define TIM_INTCLR BITS(0, 3)
#define TIM_INTCLR_TIM1 BIT(0)
#define TIM_INTCLR_TIM2 BIT(1)
#define TIM_INTCLR_TIM3 BIT(2)
#define TIM_INTCLR_TIM4 BIT(3)

// extend define
#define TIM_TM_AUTO_RUN 0
#define TIM_TM_AUTO_LOAD 1

#define TIM_CNT_POLARITY_HIGH 0
#define TIM_CNT_POLARITY_LOW 1


#define TIM_PWM_POL_PWM0_PWM1 0
#define TIM_PWM_POL_NPWM0_PWM1 1
#define TIM_PWM_POL_PWM0_NPWM1 2
#define TIM_PWM_POL_NPWM0_NPWM1 3

#define TIMER0_CTRL_EN                          BIT(7)
#define TIMER1_CTRL_EN                          BIT(0)
#define TIMER2_CTRL_EN                          BIT(0)
#define TIMER3_CTRL_EN                          BIT(0)
#define TIMER4_CTRL_EN                          BIT(0)

// timer function declare
void Timer_DisableIRQ(timer_t timer);
FlagStatus Timer_GetIntFlag(timer_t timer);
void Timer_ClrIntFlag(timer_t timer) ;

#endif /*__TIMER_H__ */
