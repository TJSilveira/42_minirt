#include "../includes/minirt.h"

t_point3 point_at_ray(ray *r, double t)
{
	t_point3 result;

	result = vec3_mul_const_copy(*r->dir, t);
	vec3_add_2inst(&result, r->orig);

	return (result);
}

unsigned int t_color3_to_uint(t_color3 c)
{
	unsigned int color_final;
	
	color_final = 0;
    color_final |= (unsigned int)(c.e[B] * 255);
    color_final |= (unsigned int)(c.e[G] * 255) << 8;
    color_final |= (unsigned int)(c.e[R] * 255) << 16;
    return (color_final);
}

unsigned int ray_color(ray *r)
{
	t_sphere s;
	s.center = (t_point3){{0.0, 0.0, 1.0}};
	s.ray = 0.5;

	if (hit_sphere(&s, r))
		return ((unsigned int)(0xFF0000));
	
	t_vec3 unit_direction = unit_vec3(r->dir);
	double a = 0.5 * (unit_direction.e[1] + 1.0);
	t_color3 black = {{1.0,1.0,1.0}};
	t_color3 blue = {{0.5,0.7,1.0}};
	black = vec3_mul_const_copy(black, 1.0 - a); 
	blue = vec3_mul_const_copy(blue, a); 
	return t_color3_to_uint(vec3_add_2inst_copy(black, blue));
}

int	hit_sphere(t_sphere *s, ray *r)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;

	oc = vec3_sub_2inst_copy(s->center, *r->orig);
	a = vec3_dot(r->dir, r->dir);
	b = -2 * vec3_dot(&oc, r->dir);
	c = vec3_dot(&oc, &oc) - (s->ray * s->ray);

	// printf("a: %f b: %f c: %f; This is the remaining: %f\n", a,b,c,(b * b - 4.0 * a * c));
	return((b * b - 4.0 * a * c) >= 0.0);
}