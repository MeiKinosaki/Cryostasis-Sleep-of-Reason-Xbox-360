#include <math.h>
#include "cryostasis/camera.h"

#define CRYOSTASIS_CAMERA_PITCH_LIMIT 1.55334306f

int cryostasis_camera_update(
    cryostasis_camera *camera,
    cryostasis_input_state input,
    float dt_seconds,
    float move_speed,
    float look_speed)
{
    cryostasis_input_state axes;
    float forward_x;
    float forward_z;
    float right_x;
    float right_z;
    float next_x;
    float next_y;
    float next_z;
    float next_yaw;
    float next_pitch;

    if (camera == 0 || !isfinite(dt_seconds) || !isfinite(move_speed) ||
        !isfinite(look_speed) || dt_seconds < 0.0f ||
        move_speed < 0.0f || look_speed < 0.0f ||
        !isfinite(camera->position.x) || !isfinite(camera->position.y) ||
        !isfinite(camera->position.z) || !isfinite(camera->yaw_radians) ||
        !isfinite(camera->pitch_radians)) {
        return 0;
    }

    axes = cryostasis_input_normalize(input);
    forward_x = sinf(camera->yaw_radians);
    forward_z = cosf(camera->yaw_radians);
    right_x = cosf(camera->yaw_radians);
    right_z = -sinf(camera->yaw_radians);

    next_x = camera->position.x +
        (forward_x * axes.move_forward + right_x * axes.move_right) *
        move_speed * dt_seconds;
    next_y = camera->position.y;
    next_z = camera->position.z +
        (forward_z * axes.move_forward + right_z * axes.move_right) *
        move_speed * dt_seconds;
    next_yaw = camera->yaw_radians + axes.look_yaw * look_speed * dt_seconds;
    next_pitch = camera->pitch_radians + axes.look_pitch * look_speed * dt_seconds;

    if (!isfinite(next_x) || !isfinite(next_y) || !isfinite(next_z) ||
        !isfinite(next_yaw) || !isfinite(next_pitch)) {
        return 0;
    }

    if (next_pitch > CRYOSTASIS_CAMERA_PITCH_LIMIT) {
        next_pitch = CRYOSTASIS_CAMERA_PITCH_LIMIT;
    } else if (next_pitch < -CRYOSTASIS_CAMERA_PITCH_LIMIT) {
        next_pitch = -CRYOSTASIS_CAMERA_PITCH_LIMIT;
    }

    camera->position.x = next_x;
    camera->position.y = next_y;
    camera->position.z = next_z;
    camera->yaw_radians = next_yaw;
    camera->pitch_radians = next_pitch;
    return 1;
}
