#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "test_wdt.h"
#include "test.h"

#define TEST_DEBUG_EN        (0)

int test_entry(void)
{
#if TEST_DEBUG_EN
    test_wdt();
#endif

    return 0;
}

