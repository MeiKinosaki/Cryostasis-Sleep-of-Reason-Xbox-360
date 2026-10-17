#ifndef CRYOSTASIS_INPUT_H
#define CRYOSTASIS_INPUT_H

typedef struct cryostasis_input_state {
    float move_forward; /* -1..1 */
    float move_right;   /* -1..1 */
    float look_yaw;     /* -1..1 */
    float look_pitch;   /* -1..1 */
} cryostasis_input_state;

/* Clamp finite axes to [-1, 1]; invalid values become zero. */
cryostasis_input_state cryostasis_input_normalize(cryostasis_input_state input);

#endif
