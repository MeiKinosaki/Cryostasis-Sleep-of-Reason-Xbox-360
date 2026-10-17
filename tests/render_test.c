#include <math.h>
#include <stdio.h>
#include "cryostasis/render.h"

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
        return 1; \
    } \
} while (0)

static int close_enough(float a, float b)
{
    return fabsf(a - b) < 0.0001f;
}

int main(void)
{
    cryostasis_projected_point out;
    cryostasis_vec3 triangle[3];

    CHECK(cryostasis_project_point((cryostasis_vec3){0.0f, 0.0f, 2.0f},
          100.0f, 320.0f, 240.0f, 0.1f, &out) == CRYOSTASIS_RENDER_OK);
    CHECK(close_enough(out.x, 320.0f));
    CHECK(close_enough(out.y, 240.0f));
    CHECK(close_enough(out.depth, 2.0f));

    CHECK(cryostasis_project_point((cryostasis_vec3){1.0f, 1.0f, 2.0f},
          100.0f, 320.0f, 240.0f, 0.1f, &out) == CRYOSTASIS_RENDER_OK);
    CHECK(close_enough(out.x, 370.0f));
    CHECK(close_enough(out.y, 190.0f));

    CHECK(cryostasis_project_point((cryostasis_vec3){0.0f, 0.0f, 0.01f},
          100.0f, 320.0f, 240.0f, 0.1f, &out) == CRYOSTASIS_RENDER_BEHIND_NEAR_PLANE);
    CHECK(cryostasis_project_point((cryostasis_vec3){0.0f, 0.0f, 2.0f},
          0.0f, 320.0f, 240.0f, 0.1f, &out) == CRYOSTASIS_RENDER_INVALID_ARGUMENT);
    CHECK(cryostasis_project_point((cryostasis_vec3){0.0f, 0.0f, 2.0f},
          100.0f, 320.0f, 240.0f, 0.1f, 0) == CRYOSTASIS_RENDER_INVALID_ARGUMENT);

    CHECK(cryostasis_get_diagnostic_triangle(triangle) == 1);
    CHECK(close_enough(triangle[0].z, 3.0f));
    CHECK(close_enough(triangle[1].z, 3.0f));
    CHECK(close_enough(triangle[2].z, 3.0f));
    CHECK(cryostasis_get_diagnostic_triangle(0) == 0);

    puts("render projection tests: PASS");
    return 0;
}
