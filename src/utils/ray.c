#include "../includes/minirt.h"

point3 point_at_ray(ray *r, double t)
{
	point3 result;

	result = vec3_mul_const_copy(r->dir, t);
	vec3_add_2inst(&result, &r->orig);

	return (result);
}