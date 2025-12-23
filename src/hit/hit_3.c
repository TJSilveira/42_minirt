/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 22:55:43 by devriez           #+#    #+#             */
/*   Updated: 2025/12/19 15:47:59 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//added hole new file

static t_bool	check_height_limit(t_cylinder *c, t_ray *r, float t)
{
	t_vec3	hit_point;
	t_vec3	cp;
	float	projection;

	hit_point = point_at_ray(r, t);
	cp = vec3_sub_2inst_copy(hit_point, c->center);
	projection = vec3_dot(&cp, &c->normal);
	return (projection >= -c->h * 0.5f && projection <= c->h * 0.5f);
}

static void	fill_side_hit(t_cylinder *c, t_ray *r, t_hit *hit, float t)
{
	t_vec3	cp;
	t_vec3	axis_projection;

	hit->p = point_at_ray(r, t);
	cp = vec3_sub_2inst_copy(hit->p, c->center);
	axis_projection = vec3_mul_const_copy(c->normal, vec3_dot(&cp, &c->normal));
	hit->normal = vec3_sub_2inst_copy(cp, axis_projection);
	hit->normal = unit_vec3(&hit->normal);
	record_hit(r, hit, &hit->normal, t);
	set_face_normal(r, hit);
	hit->color = c->color;
}

static t_bool	hit_cylinder_side(t_cylinder *c, t_ray *r, t_hit *hit)
{
	t_vec3	oc;
	t_vec3	d_perp;
	t_vec3	oc_perp;
	t_quad	q;
	float	t[2];

	oc = vec3_sub_2inst_copy(r->orig, c->center);
	d_perp = vec3_sub_2inst_copy(r->dir,
			vec3_mul_const_copy(c->normal, vec3_dot(&r->dir, &c->normal)));
	oc_perp = vec3_sub_2inst_copy(oc,
			vec3_mul_const_copy(c->normal, vec3_dot(&oc, &c->normal)));
	q.a = vec3_dot(&d_perp, &d_perp);
	q.b = 2.0f * vec3_dot(&d_perp, &oc_perp);
	q.c = vec3_dot(&oc_perp, &oc_perp) - (c->diam * 0.5f) * (c->diam * 0.5f);
	if (cy_solve_quadratic(&q, &t[0], &t[1]) == 0)
		return (FALSE);
	if (t[0] > r->itv.min && t[0] < r->itv.max 
		&& check_height_limit(c, r, t[0]))
		return (fill_side_hit(c, r, hit, t[0]), TRUE);
	if (t[1] > r->itv.min && t[1] < r->itv.max 
		&& check_height_limit(c, r, t[1]))
		return (fill_side_hit(c, r, hit, t[1]), TRUE);
	return (FALSE);
}

static t_bool	hit_cylinder_cap(
	t_cylinder *c, t_ray *r, t_hit *hit, float sign)
{
	t_vec3	cap_center;
	t_vec3	p_to_center;
	t_vec3	to_cap;
	float	t;
	float	denom;

	cap_center = vec3_add_2inst_copy(c->center,
			vec3_mul_const_copy(c->normal, sign * c->h * 0.5f));
	denom = vec3_dot(&r->dir, &c->normal);
	if (fabsf(denom) < EPSILON)
		return (FALSE);
	to_cap = vec3_sub_2inst_copy(cap_center, r->orig);
	t = vec3_dot(&to_cap, &(c->normal)) / denom;
	if (t <= r->itv.min || t >= r->itv.max)
		return (FALSE);
	p_to_center = vec3_sub_2inst_copy(point_at_ray(r, t), cap_center);
	if (vec3_length_squared(&p_to_center) > (c->diam * 0.5f) * (c->diam * 0.5f))
		return (FALSE);
	hit->normal = vec3_mul_const_copy(c->normal, sign);
	record_hit(r, hit, &hit->normal, t);
	set_face_normal(r, hit);
	hit->color = c->color;
	return (TRUE);
}

t_bool	hit_cylinder(t_cylinder *c, t_ray *r, t_hit *hit)
{
	t_bool	is_hit;
	t_hit	temp_hit;

	is_hit = FALSE;
	if (hit_cylinder_side(c, r, &temp_hit))
	{
		*hit = temp_hit;
		r->itv.max = temp_hit.t;
		is_hit = TRUE;
	}
	if (hit_cylinder_cap(c, r, &temp_hit, 1.0f))
	{
		*hit = temp_hit;
		r->itv.max = temp_hit.t;
		is_hit = TRUE;
	}
	if (hit_cylinder_cap(c, r, &temp_hit, -1.0f))
	{
		*hit = temp_hit;
		r->itv.max = temp_hit.t;
		is_hit = TRUE;
	}
	return (is_hit);
}
