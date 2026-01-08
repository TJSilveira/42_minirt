/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilveir <tsilveir@student.42luxembourg.l  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:51:19 by tsilveir          #+#    #+#             */
/*   Updated: 2025/12/19 15:26:07 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	rt_import_sphere(char **params, t_engine *e)
{
	int			i;
	t_object	*sp;

	sp = malloc(sizeof(t_object));
	if (!sp)
		error_handler("Malloc was not successful.\n", e);
	i = 0;
	while (params[i])
		i++;
	if (i != NUM_PARAM_SPHERE)
		return (EXIT_FAILURE);
	if (rt_import_vec3(params[0], &sp->obj_union.sphere.center) == EXIT_FAILURE
		|| rt_import_float_non_negative(params[1],
			&sp->obj_union.sphere.ray) == EXIT_FAILURE
		|| rt_import_color(params[2],
			&sp->obj_union.sphere.color) == EXIT_FAILURE)
	{
		free(sp);
		return (EXIT_FAILURE);
	}
	sp->id = id_sphere;
	add_object_to_scene(e, sp);
	return (EXIT_SUCCESS);
}

int	rt_import_plane(char **params, t_engine *e)
{
	int			i;
	t_object	*pl;

	i = -1;
	pl = malloc(sizeof(t_object));
	if (!pl)
		error_handler("Malloc was not successful.\n", e);
	while (params[++i])
		;
	if (i != NUM_PARAM_PLANE)
		return (EXIT_FAILURE);
	if (rt_import_vec3(params[0], &pl->obj_union.plane.point) == EXIT_FAILURE
		|| rt_import_vec3_normalized(params[1],
			&pl->obj_union.plane.normal) == EXIT_FAILURE
		|| rt_import_color(params[2],
			&pl->obj_union.plane.color) == EXIT_FAILURE)
	{
		free(pl);
		return (EXIT_FAILURE);
	}
	pl->id = id_plane;
	pl->obj_union.plane.normal = unit_vec3(&pl->obj_union.plane.normal);
	add_object_to_scene(e, pl);
	return (EXIT_SUCCESS);
}

int	rt_import_camera(char **params, t_engine *e)
{
	int	i;

	if (e->cam)
		return (EXIT_FAILURE);
	e->cam = malloc(sizeof(t_camera));
	if (!e->cam)
		error_handler("Malloc was not successful.\n", e);
	i = -1;
	while (params[++i])
		;
	if (i != NUM_PARAM_CAMERA)
		return (EXIT_FAILURE);
	if (rt_import_vec3(params[0], &e->cam->camera_center) == EXIT_FAILURE
		|| rt_import_vec3_normalized(params[1],
			&e->cam->direction) == EXIT_FAILURE || rt_import_fov(params[2],
			&e->cam->fov) == EXIT_FAILURE)
		error_handler("Camera inputs not provided correctly\n", e);
	return (EXIT_SUCCESS);
}

int	rt_import_cylinder(char **params, t_engine *e)
{
	int			i;
	t_object	*cy;

	cy = malloc(sizeof(t_object));
	if (!cy)
		error_handler("Malloc was not successful.\n", e);
	i = 0;
	while (params[i])
		i++;
	if (i != NUM_PARAM_CYLINDER)
		return (EXIT_FAILURE);
	if (rt_import_vec3(params[0],
			&cy->obj_union.cylinder.center) == EXIT_FAILURE
		|| rt_import_vec3_normalized(params[1],
			&cy->obj_union.cylinder.normal) == EXIT_FAILURE
		|| rt_import_float_non_negative(params[2],
			&cy->obj_union.cylinder.diam) == EXIT_FAILURE
		|| rt_import_float_non_negative(params[3],
			&cy->obj_union.cylinder.h) == EXIT_FAILURE
		|| rt_import_color(params[4],
			&cy->obj_union.cylinder.color) == EXIT_FAILURE)
		return (free(cy), EXIT_FAILURE);
	cy->id = id_cylinder;
	cy->obj_union.cylinder.normal = unit_vec3(&cy->obj_union.cylinder.normal);
	return (add_object_to_scene(e, cy), EXIT_SUCCESS);
}
