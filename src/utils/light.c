#include "../includes/minirt.h"

t_bool in_shadow(t_engine *e, t_light *l, t_hit *hit)
{
	t_ray	shadow_ray;
	float	distance_to_light;
	t_bool	occluded;

	shadow_ray.dir = vec3_sub_2inst_copy(l->center, hit->p);
	distance_to_light = vec3_length(&shadow_ray.dir);
	shadow_ray.orig = hit->p;
	shadow_ray.itv.min = EPSILON;
	shadow_ray.itv.max = distance_to_light;
	occluded = hit_occluded(e, &shadow_ray);
	shadow_ray.itv.max = distance_to_light;
	return (occluded);
}