/**
 * @file wdt.c
 * @author David Lin
 * @brief
 * @version 0.1
 * @date 2021-05-17
 *
 * @copyright Fanhai Data Tech. (c) 2021
 *
 */

#include "wdt.h"
#include "sysc.h"
/**
 * @brief wdt init
 *
 * @param iDel:  delay ms  (lrc:max 256s xtl:max 64s)
 * @param iClkSrc: PMU_CR_LPTCLKSEL_LRC , PMU_CR_LPTCLKSEL_XTL
 * @param iOVMode :WDT_OV_INT , WDT_OV_RST
 * note:clk source = lrc  at least 4ms err
 */
void WDT_Init(int iDel, int iClkSrc, eOVModeType iOVMode) {
    int iTmp = 1;
    PARAM_CHECK((iClkSrc != PMU_CR_LPTCLKSEL_LRC) &&
                (iClkSrc != PMU_CR_LPTCLKSEL_XTL));
    PARAM_CHECK((iOVMode != WDT_OV_INT) && (iOVMode != WDT_OV_RST));
    SYSC->CLKENCFG |= SYSC_CLKENCFG_LPWDT_PCKEN;

    iDel = iDel >> 2;

    while (iDel > 2) {
        ++iTmp;
        iDel >>= 1;
    }
    PARAM_CHECK((iTmp > 16) || (iTmp == 0));
    WDT_CR_REG = iTmp - 1;
    if (iOVMode == WDT_OV_INT) {
        WDT_CR_REG |= WDT_CR_WINTEN;
    } else {
        WDT_CR_REG &= ~WDT_CR_WINTEN;
    }
    WDT_StartCount();
}

/**
 * @brief wdt deinit
 *
 */
void WDT_DeInit(void) {
    SYSC->CLKENCFG &= ~SYSC_CLKENCFG_LPWDT_PCKEN;
}
