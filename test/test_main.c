#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "test_wdt.h"
#include "test.h"

int test_entry(void)
{
    test_wdt();

    return 0;
}

