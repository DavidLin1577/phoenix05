#ifndef _DEMO_H_
#define _DEMO_H_

#include "wdt_demo.h"
#include "lptimer_demo.h"
#include "timer_demo.h"
#include "uart_demo.h"

#define LED_RED             GPIO_PIN14
#define LED_ON(pin)         GPIO_SetPin(pin)
#define LED_OFF(pin)        GPIO_ClrPin(pin)

#define UART1_RX            GPIO_PIN0
#define UART1_TX            GPIO_PIN1

void demo_entry(void);

#endif /*_DEMO_H_*/
