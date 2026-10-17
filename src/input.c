#include <math.h>
#include "cryostasis/input.h"

static float normalize_axis(float value)
{
    if (!isfinite(value)) {
        return 0.0f;
    }
    if (value > 1.0f) {
        return 1.0f;
    }
    if (value < -1.0f) {
        return -1.0f;
    }
    return value;
}

cryostasis_input_state cryostasis_input_normalize(cryostasis_input_state input)
{
    cryostasis_input_state result;
    result.move_forward = normalize_axis(input.move_forward);
    result.move_right = normalize_axis(input.move_right);
    result.look_yaw = normalize_axis(input.look_yaw);
    result.look_pitch = normalize_axis(input.look_pitch);
    return result;
}
