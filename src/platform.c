/*
 * Cryostasis360 v0.2b platform boundary.
 *
 * This portable implementation validates program startup and provides a
 * seam for a future verified Xbox 360 runtime adapter. It deliberately does
 * not pretend to initialize Xenos, controller, audio, or libXenon services.
 */
#include <stdio.h>
#include "cryostasis/platform.h"

int cryostasis_platform_init(void)
{
#if defined(__powerpc__) || defined(__PPC__)
    puts("Cryostasis360: PowerPC compilation target detected.");
#else
    puts("Cryostasis360: host diagnostic build detected (not an Xbox 360 build).");
#endif
    puts("Cryostasis360: platform adapter is diagnostic-only.");
    return 0;
}

void cryostasis_platform_shutdown(void)
{
    puts("Cryostasis360: diagnostic shutdown.");
}
