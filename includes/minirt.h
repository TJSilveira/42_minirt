/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:16:39 by tsilveir          #+#    #+#             */
/*   Updated: 2025/08/18 18:16:40 by tsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../libft/libft.h"
# include <math.h>
# include "../minilibx-linux/mlx.h"

#include <stdio.h>

typedef struct vec3 
{
	double e[3];
} vec3, color3, point3;

typedef struct ray
{
	struct vec3 dir;
	point3 orig;
}ray;

// utils.c function prototypes
double		length_squared(vec3 *v);
double		length(vec3 *v);

vec3		vec3_mul_const_copy(vec3 v, double t);
void		vec3_mul_const(vec3 *v, double t);

vec3		vec3_div_const_copy(vec3 v, double t);
void		vec3_div_const(vec3 *v, double t);

vec3		vec3_add_2inst_copy(vec3 v1, vec3 v2);
void		vec3_add_2inst(vec3 *v1, vec3 *v2);

vec3		vec3_sub_2inst_copy(vec3 v1, vec3 v2);
void		vec3_sub_2inst(vec3 *v1, vec3 *v2);

// colors.c
void write_color(color3 *c);


#endif