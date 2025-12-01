#include "../includes/minirt.h"

void	get_pixel_color_anti_alaising_rt(t_engine *e, t_pixel *p)
{
	t_ray		r;
	t_point3	curr_sample;
	int			i;
	int			j;

	p->top_left = calculate_pixel_top_left(e->cam, p->x, p->y);
	i = 0;
	while (i < RAY_SAMPLE_SIDE_SIZE)
	{
		j = 0;
		while (j < RAY_SAMPLE_SIDE_SIZE)
		{
			curr_sample = get_sample_location(e, p, i, j);
			init_ray(&r, e, &curr_sample);
            p->clr = vec3_add_2inst_copy(p->clr, vec3_div_const_copy(ray_tracer(&r, e), RAY_SAMPLE_SIDE_SIZE * RAY_SAMPLE_SIDE_SIZE));
			j++;
		}
		i++;
	}
}

// TODO: Investigate what is going on with the sampling. I belive this is the source of the bugs when the camera is not aligned with z axis
t_point3	get_sample_location(t_engine *e, t_pixel *p, int i, int j)
{
	t_vec3		pixel_sample_delta_right;
	t_vec3		pixel_sample_delta_down;
	t_vec3		pixel_sample_delta;
	t_point3	curr_sample;

	pixel_sample_delta_right = vec3_mul_const_copy(e->cam->pixel_delta_right, RAY_SAMPLE_PADDING + i * (1.0 - 2.0 * RAY_SAMPLE_PADDING) / (RAY_SAMPLE_SIDE_SIZE - 1.0));
	pixel_sample_delta_down = vec3_mul_const_copy(e->cam->pixel_delta_down, RAY_SAMPLE_PADDING + j * (1.0 - 2.0 * RAY_SAMPLE_PADDING) / (RAY_SAMPLE_SIDE_SIZE - 1.0));	
	pixel_sample_delta = vec3_add_2inst_copy(pixel_sample_delta_right, pixel_sample_delta_down);
	curr_sample = vec3_add_2inst_copy(p->top_left, pixel_sample_delta);
	return (curr_sample);
}