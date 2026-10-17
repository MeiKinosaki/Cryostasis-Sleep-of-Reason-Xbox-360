#ifndef CRYOSTASIS_RESOURCE_H
#define CRYOSTASIS_RESOURCE_H

#include <stddef.h>

typedef enum cryostasis_resource_status {
    CRYOSTASIS_RESOURCE_OK = 0,
    CRYOSTASIS_RESOURCE_INVALID_ARGUMENT,
    CRYOSTASIS_RESOURCE_NOT_FOUND,
    CRYOSTASIS_RESOURCE_TOO_LARGE,
    CRYOSTASIS_RESOURCE_IO_ERROR,
    CRYOSTASIS_RESOURCE_OUT_OF_MEMORY
} cryostasis_resource_status;

/*
 * Read a file into an allocated buffer, rejecting files larger than max_bytes.
 * On success, caller owns *out_data and must free it. Empty files return
 * *out_data == NULL and *out_size == 0. Outputs are reset on entry.
 */
cryostasis_resource_status cryostasis_read_file(
    const char *path,
    size_t max_bytes,
    unsigned char **out_data,
    size_t *out_size);

const char *cryostasis_resource_status_string(cryostasis_resource_status status);

#endif
