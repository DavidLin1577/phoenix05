#ifndef _DEMO_H_
#define _DEMO_H_

#include "wdt_demo.h"
#include "lptimer_demo.h"

#define LED_RED             GPIO_PIN14
#define LED_ON(pin)         GPIO_SetPin(pin)
#define LED_OFF(pin)        GPIO_ClrPin(pin)

void demo_entry(void);

#endif /*_DEMO_H_*/
