#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cryostasis/resource.h"

static int write_file(const char *path, const char *contents, size_t length)
{
    FILE *file = fopen(path, "wb");
    int ok;
    if (file == NULL) return 0;
    ok = fwrite(contents, 1U, length, file) == length;
    if (fclose(file) != 0) ok = 0;
    return ok;
}

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
        return 1; \
    } \
} while (0)

int main(void)
{
    unsigned char *data = NULL;
    size_t size = 0U;
    const char *nonempty = "ship";
    const char *nonempty_path = "cryostasis_resource_test.bin";
    const char *empty_path = "cryostasis_resource_empty.bin";

    CHECK(write_file(nonempty_path, nonempty, 4U));
    CHECK(write_file(empty_path, "", 0U));

    CHECK(cryostasis_read_file(nonempty_path, 4U, &data, &size) == CRYOSTASIS_RESOURCE_OK);
    CHECK(size == 4U);
    CHECK(memcmp(data, nonempty, 4U) == 0);
    free(data);
    data = NULL;

    CHECK(cryostasis_read_file(nonempty_path, 3U, &data, &size) == CRYOSTASIS_RESOURCE_TOO_LARGE);
    CHECK(data == NULL && size == 0U);

    CHECK(cryostasis_read_file(empty_path, 0U, &data, &size) == CRYOSTASIS_RESOURCE_OK);
    CHECK(data == NULL && size == 0U);

    CHECK(cryostasis_read_file("cryostasis_missing_test_file.bin", 8U, &data, &size) == CRYOSTASIS_RESOURCE_NOT_FOUND);
    CHECK(data == NULL && size == 0U);

    CHECK(cryostasis_read_file(NULL, 8U, &data, &size) == CRYOSTASIS_RESOURCE_INVALID_ARGUMENT);
    CHECK(cryostasis_read_file(nonempty_path, 8U, NULL, &size) == CRYOSTASIS_RESOURCE_INVALID_ARGUMENT);

    remove(nonempty_path);
    remove(empty_path);
    puts("resource tests: PASS");
    return 0;
}
