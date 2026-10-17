#ifndef CRYOSTASIS_PLATFORM_H
#define CRYOSTASIS_PLATFORM_H

/* Minimal platform boundary; target-specific APIs must be verified separately. */
int cryostasis_platform_init(void);
void cryostasis_platform_shutdown(void);

#endif
