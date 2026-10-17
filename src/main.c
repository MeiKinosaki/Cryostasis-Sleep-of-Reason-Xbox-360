/*
 * Cryostasis360 v0.2b
 * Diagnostic startup entry point. This is not the original game engine.
 */
#include <stdio.h>
#include "cryostasis/platform.h"

int main(void)
{
    if (cryostasis_platform_init() != 0) {
        fputs("Cryostasis360: platform initialization failed.\n", stderr);
        return 1;
    }

    puts("Cryostasis360: startup diagnostics completed.");
    puts("Game renderer, assets, physics, and audio are not implemented yet.");
    cryostasis_platform_shutdown();
    return 0;
}
