#include <math.h>
#include "cryostasis/render.h"

cryostasis_render_status cryostasis_project_point(
    cryostasis_vec3 point,
    float focal_length,
    float center_x,
    float center_y,
    float near_plane,
    cryostasis_projected_point *out_point)
{
    if (out_point == 0 || !isfinite(point.x) || !isfinite(point.y) ||
        !isfinite(point.z) || !isfinite(focal_length) ||
        !isfinite(center_x) || !isfinite(center_y) ||
        !isfinite(near_plane) || focal_length <= 0.0f || near_plane <= 0.0f) {
        return CRYOSTASIS_RENDER_INVALID_ARGUMENT;
    }

    out_point->x = 0.0f;
    out_point->y = 0.0f;
    out_point->depth = 0.0f;

    if (point.z < near_plane) {
        return CRYOSTASIS_RENDER_BEHIND_NEAR_PLANE;
    }

    out_point->x = center_x + (point.x * focal_length) / point.z;
    out_point->y = center_y - (point.y * focal_length) / point.z;
    out_point->depth = point.z;

    if (!isfinite(out_point->x) || !isfinite(out_point->y)) {
        out_point->x = 0.0f;
        out_point->y = 0.0f;
        out_point->depth = 0.0f;
        return CRYOSTASIS_RENDER_INVALID_ARGUMENT;
    }

    return CRYOSTASIS_RENDER_OK;
}

int cryostasis_get_diagnostic_triangle(cryostasis_vec3 out_vertices[3])
{
    if (out_vertices == 0) {
        return 0;
    }

    out_vertices[0].x = -1.0f;
    out_vertices[0].y = -0.75f;
    out_vertices[0].z = 3.0f;

    out_vertices[1].x = 1.0f;
    out_vertices[1].y = -0.75f;
    out_vertices[1].z = 3.0f;

    out_vertices[2].x = 0.0f;
    out_vertices[2].y = 0.9f;
    out_vertices[2].z = 3.0f;

    return 1;
}
