#ifndef CRYOSTASIS_RENDER_H
#define CRYOSTASIS_RENDER_H

typedef struct cryostasis_vec3 {
    float x;
    float y;
    float z;
} cryostasis_vec3;

typedef struct cryostasis_projected_point {
    float x;
    float y;
    float depth;
} cryostasis_projected_point;

typedef enum cryostasis_render_status {
    CRYOSTASIS_RENDER_OK = 0,
    CRYOSTASIS_RENDER_INVALID_ARGUMENT,
    CRYOSTASIS_RENDER_BEHIND_NEAR_PLANE
} cryostasis_render_status;

/*
 * CPU-side perspective projection for renderer bring-up.
 * Coordinates are camera-space; positive z points forward.
 * This does not submit geometry to the Xbox 360 GPU.
 */
cryostasis_render_status cryostasis_project_point(
    cryostasis_vec3 point,
    float focal_length,
    float center_x,
    float center_y,
    float near_plane,
    cryostasis_projected_point *out_point);

/* Returns a fixed diagnostic triangle in camera-space. */
int cryostasis_get_diagnostic_triangle(cryostasis_vec3 out_vertices[3]);

#endif
