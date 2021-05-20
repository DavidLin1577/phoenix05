#ifndef _TEST_H_
#define _TEST_H_

#include "phnx05.h"

#define TEST_LOG_BASE               (SRAM_BASE                 + 0x500)
#define TEST_CASE_RESULT_BASE       (TEST_LOG_BASE             + 0x000)
#define TEST_ADC_BASE               (TEST_LOG_BASE             + 0x010)
#define TEST_ANAC_BASE              (TEST_LOG_BASE             + 0x020)
#define TEST_EFC_BASE               (TEST_LOG_BASE             + 0x030)
#define TEST_EST_BASE               (TEST_LOG_BASE             + 0x040)
#define TEST_IOM_BASE               (TEST_LOG_BASE             + 0x100)
#define TEST_LPTIMER_BASE           (TEST_LOG_BASE             + 0x120)
#define TEST_SYSC_BASE              (TEST_LOG_BASE             + 0x140)
#define TEST_TIMER_BASE             (TEST_LOG_BASE             + 0x160)
#define TEST_UART_BASE              (TEST_LOG_BASE             + 0x180)
#define TEST_WDT_BASE               (TEST_LOG_BASE             + 0x200)

//test result
#define TEST_CASE_TOTAL_ADDR        (TEST_CASE_RESULT_BASE     + 0x00 )
#define TEST_CASE_SUCCEEDED_ADDR    (TEST_CASE_RESULT_BASE     + 0x04 )
#define TEST_CASE_FAILED_ADDR       (TEST_CASE_RESULT_BASE     + 0x08 )

#define xprintf

static int g_case_total;
static int g_case_succeeded;
static int g_case_failed;

#define INTERNAL_USE_ONLY_SUCCEEDED(_a, _b)                               \
    //xprintf("Expected: \""#_a"\"" == \""#_b"\"\n Result: Succeeded\n")
#define INTERNAL_USE_ONLY_FAILED(_a, _b)                                  \
    //xprintf("Expected: \""#_a"\"" == \""#_b"\"\n (X) Result: Failed\n")
#define INTERNAL_USE_ONLY_CASE_SHOW()                                     \
    //xprintf("Case %d =====>\n", g_case_total);                          \
    //xprintf("  Location:%s:%d\n", __FILE_, __LINE__);                   \

#define UNITEST_ERROR(_string) do {                                       \
	xprintf("Error: "#_string"\n");                                       \
	return -1;                                                            \
}while(0)

#define UNITEST_EQUALS(_a, _b, _addr, _offset) do {                       \
    g_case_total++;                                                       \
    REG32(TEST_CASE_TOTAL_ADDR) = g_case_total;                           \
    INTERNAL_USE_ONLY_CASE_SHOW();                                        \
    if ((_a) == (_b)) {                                                   \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b);                              \
        REG32(_addr) |= BIT(_offset);                                     \
        g_case_succeeded++;                                               \
        REG32(TEST_CASE_SUCCEEDED_ADDR) = g_case_succeeded;               \
    }                                                                     \
    else {                                                                \
        INTERNAL_USE_ONLY_FAILED(_a, _b);                                 \
        REG32(_addr) &= ~BIT(_offset);                                    \
        g_case_failed++;                                                  \
        REG32(TEST_CASE_FAILED_ADDR) = g_case_failed;                     \
    }                                                                     \
	xprintf("\n");                                                        \
} while (0)

#define UNITEST_DIFFERS(_a, _b, _addr, _offset) do {                      \
    g_case_total++;                                                       \
    INTERNAL_USE_ONLY_CASE_SHOW();                                        \
    if ((_a) == (_b)) {                                                   \
        INTERNAL_USE_ONLY_FAILED(_a, _b);                                 \
        REG32(_addr) &= ~BIT(_offset);                                    \
        g_case_failed++;                                                  \
    }                                                                     \
    else {                                                                \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b);                              \
        g_case_succeeded++;                                               \
        REG32(_addr) |= BIT(_offset);                                     \
    }                                                                     \
	xprintf("\n");                                                        \
} while (0)

#define UNITEST_LESS_THAN(_a, _b) do {                                    \
    g_case_total++;                                                       \
    INTERNAL_USE_ONLY_CASE_SHOW();                                        \
    if ((_a) < (_b)) {                                                    \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b);                              \
        g_case_succeeded++;                                               \
    }                                                                     \
    else {                                                                \
        INTERNAL_USE_ONLY_FAILED(_a, _b);                                 \
        g_case_failed++;                                                  \
    }                                                                     \
	xprintf("\n");                                                        \
} while (0)

#define UNITEST_LESS_THAN_EQUALS(_a, _b) do {                             \
    g_case_total++;                                                       \
    INTERNAL_USE_ONLY_CASE_SHOW();                                        \
    if ((_a) <= (_b)) {                                                   \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b);                              \
        g_case_succeeded++;                                               \
    }                                                                     \
    else {                                                                \
        INTERNAL_USE_ONLY_FAILED(_a, _b);                                 \
        g_case_failed++;                                                  \
    }                                                                     \
	xprintf("\n");                                                        \
} while (0)

#define UNITEST_GREATER_THAN(_a, _b) do {                                 \
    g_case_total++;                                                       \
    INTERNAL_USE_ONLY_CASE_SHOW();                                        \
    if ((_a) > (_b)) {                                                    \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b);                              \
        g_case_succeeded++;                                               \
    }                                                                     \
    else {                                                                \
        INTERNAL_USE_ONLY_FAILED(_a, _b);                                 \
        g_case_failed++;                                                  \
    }                                                                     \
	xprintf("\n");                                                        \
} while (0)

#define UNITEST_GREATER_THAN_EQUALS(_a, _b) do {                          \
    g_case_total++;                                                       \
    INTERNAL_USE_ONLY_CASE_SHOW();                                        \
    if ((_a) >= (_b)) {                                                   \
        INTERNAL_USE_ONLY_SUCCEEDED(_a, _b);                              \
        g_case_succeeded++;                                               \
    }                                                                     \
    else {                                                                \
        INTERNAL_USE_ONLY_FAILED(_a, _b);                                 \
        g_case_failed++;                                                  \
    }                                                                     \
	xprintf("\n");                                                        \
} while (0)

int test_entry(void);

#endif /*_TEST_H_*/

