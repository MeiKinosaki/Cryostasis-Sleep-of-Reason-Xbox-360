#ifndef CRYOSTASIS_CAMERA_H
#define CRYOSTASIS_CAMERA_H

#include "cryostasis/input.h"
#include "cryostasis/render.h"

typedef struct cryostasis_camera {
    cryostasis_vec3 position;
    float yaw_radians;
    float pitch_radians;
} cryostasis_camera;

/*
 * Apply normalized input over dt seconds.
 * Invalid/negative dt is rejected. Pitch is clamped away from +/-90 degrees.
 * This updates CPU camera state only; it does not poll a physical controller.
 */
int cryostasis_camera_update(
    cryostasis_camera *camera,
    cryostasis_input_state input,
    float dt_seconds,
    float move_speed,
    float look_speed);

#endif
