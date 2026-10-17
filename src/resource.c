#include <stdio.h>
#include <stdlib.h>
#include "cryostasis/resource.h"

cryostasis_resource_status cryostasis_read_file(
    const char *path,
    size_t max_bytes,
    unsigned char **out_data,
    size_t *out_size)
{
    FILE *file;
    long file_length;
    unsigned char *buffer = NULL;
    size_t bytes_read;

    if (out_data == NULL || out_size == NULL) {
        return CRYOSTASIS_RESOURCE_INVALID_ARGUMENT;
    }
    *out_data = NULL;
    *out_size = 0U;

    if (path == NULL || path[0] == '\0') {
        return CRYOSTASIS_RESOURCE_INVALID_ARGUMENT;
    }

    file = fopen(path, "rb");
    if (file == NULL) {
        return CRYOSTASIS_RESOURCE_NOT_FOUND;
    }

    if (fseek(file, 0L, SEEK_END) != 0 || (file_length = ftell(file)) < 0L ||
        fseek(file, 0L, SEEK_SET) != 0) {
        fclose(file);
        return CRYOSTASIS_RESOURCE_IO_ERROR;
    }

    if ((unsigned long)file_length > (unsigned long)max_bytes) {
        fclose(file);
        return CRYOSTASIS_RESOURCE_TOO_LARGE;
    }

    if (file_length > 0L) {
        buffer = (unsigned char *)malloc((size_t)file_length);
        if (buffer == NULL) {
            fclose(file);
            return CRYOSTASIS_RESOURCE_OUT_OF_MEMORY;
        }
        bytes_read = fread(buffer, 1U, (size_t)file_length, file);
        if (bytes_read != (size_t)file_length || ferror(file)) {
            free(buffer);
            fclose(file);
            return CRYOSTASIS_RESOURCE_IO_ERROR;
        }
    }

    if (fclose(file) != 0) {
        free(buffer);
        return CRYOSTASIS_RESOURCE_IO_ERROR;
    }

    *out_data = buffer;
    *out_size = (size_t)file_length;
    return CRYOSTASIS_RESOURCE_OK;
}

const char *cryostasis_resource_status_string(cryostasis_resource_status status)
{
    switch (status) {
    case CRYOSTASIS_RESOURCE_OK: return "ok";
    case CRYOSTASIS_RESOURCE_INVALID_ARGUMENT: return "invalid argument";
    case CRYOSTASIS_RESOURCE_NOT_FOUND: return "not found";
    case CRYOSTASIS_RESOURCE_TOO_LARGE: return "file exceeds size limit";
    case CRYOSTASIS_RESOURCE_IO_ERROR: return "I/O error";
    case CRYOSTASIS_RESOURCE_OUT_OF_MEMORY: return "out of memory";
    default: return "unknown resource status";
    }
}
