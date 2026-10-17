#include <math.h>
#include <stdio.h>
#include "cryostasis/camera.h"

#define CHECK(condition) do { \
    if (!(condition)) { \
        fprintf(stderr, "FAIL %s:%d: %s\n", __FILE__, __LINE__, #condition); \
        return 1; \
    } \
} while (0)

static int close_enough(float a, float b)
{
    return fabsf(a - b) < 0.001f;
}

int main(void)
{
    cryostasis_input_state raw = {2.0f, -2.0f, NAN, 0.5f};
    cryostasis_input_state axes = cryostasis_input_normalize(raw);
    cryostasis_camera camera = {{0.0f, 1.5f, 0.0f}, 0.0f, 0.0f};
    cryostasis_input_state forward = {1.0f, 0.0f, 0.0f, 0.0f};
    cryostasis_input_state look = {0.0f, 0.0f, 1.0f, 1.0f};

    CHECK(close_enough(axes.move_forward, 1.0f));
    CHECK(close_enough(axes.move_right, -1.0f));
    CHECK(close_enough(axes.look_yaw, 0.0f));
    CHECK(close_enough(axes.look_pitch, 0.5f));

    CHECK(cryostasis_camera_update(&camera, forward, 1.0f, 2.0f, 1.0f) == 1);
    CHECK(close_enough(camera.position.x, 0.0f));
    CHECK(close_enough(camera.position.y, 1.5f));
    CHECK(close_enough(camera.position.z, 2.0f));

    CHECK(cryostasis_camera_update(&camera, look, 1.0f, 2.0f, 1.0f) == 1);
    CHECK(close_enough(camera.yaw_radians, 1.0f));
    CHECK(camera.pitch_radians > 1.5f && camera.pitch_radians < 1.56f);

    CHECK(cryostasis_camera_update(&camera, forward, -1.0f, 1.0f, 1.0f) == 0);
    CHECK(cryostasis_camera_update(0, forward, 1.0f, 1.0f, 1.0f) == 0);

    puts("input/camera tests: PASS");
    return 0;
}
