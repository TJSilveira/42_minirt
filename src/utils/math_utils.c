/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:52:18 by tsilveir          #+#    #+#             */
/*   Updated: 2025/12/19 14:28:14 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_quadratic	solve_quadratic(t_sphere *s, t_ray *r)
{
	t_vec3		oc;
	t_quadratic	q;

	oc = vec3_sub_2inst_copy(s->center, r->orig);
	q.a = vec3_dot(&r->dir, &r->dir);
	q.h = vec3_dot(&oc, &r->dir);
	q.c = vec3_dot(&oc, &oc) - (s->ray * s->ray);
	q.discriminate = (q.h * q.h - q.a * q.c);
	if (q.discriminate < 0)
		q.has_solutions = FALSE;
	else
	{
		q.has_solutions = TRUE;
		q.t_minus = (q.h - sqrt(q.discriminate)) / q.a;
		q.t_plus = (q.h + sqrt(q.discriminate)) / q.a;
	}
	return (q);
}

float	degrees_to_radians(float degrees)
{
	return (degrees * PI / 180.0);
}

//added
int	cy_solve_quadratic(t_quad *q, float *t1, float *t2)
{
	float	sqrt_disc;

	q->disc = q->b * q->b - 4.0f * q->a * q->c;
	if (q->disc < 0)
		return (0);
	if (q->disc < EPSILON)
	{
		*t1 = -q->b / (2.0f * q->a);
		*t2 = *t1;
		return (1);
	}
	sqrt_disc = sqrtf(q->disc);
	*t1 = (-q->b - sqrt_disc) / (2.0f * q->a);
	*t2 = (-q->b + sqrt_disc) / (2.0f * q->a);
	return (2);
}
