/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_lights.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:16:25 by amoiseik          #+#    #+#             */
/*   Updated: 2025/12/19 15:24:51 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

//added new file for lights and ambient import

int	rt_import_light(char **params, t_engine *e)
{
	int		i;
	t_light	*l;

	i = -1;
	l = malloc(sizeof(t_light));
	if (!l)
		error_handler("Malloc was not successful.\n", e);
	while (params[++i])
		;
	if (i != NUM_PARAM_LIGHT)
		return (EXIT_FAILURE);
	if (rt_import_vec3(params[0], &l->center) == EXIT_FAILURE
		|| rt_import_float_between_01(params[1], &l->brightness) == EXIT_FAILURE
		|| rt_import_color(params[2], &l->color) == EXIT_FAILURE)
	{
		free(l);
		return (EXIT_FAILURE);
	}
	add_light_to_scene(e, l);
	return (EXIT_SUCCESS);
}

int	rt_import_ambient(char **params, t_engine *e)
{
	int	i;

	if (e->scene.amb)
		return (EXIT_FAILURE);
	e->scene.amb = malloc(sizeof(t_ambient));
	if (!e->scene.amb)
		error_handler("Malloc was not successful.\n", e);
	i = -1;
	while (params[++i])
		;
	if (i != NUM_PARAM_AMBIENT)
		return (EXIT_FAILURE);
	if (rt_import_float_between_01(params[0],
			&e->scene.amb->intensity) == EXIT_FAILURE
		|| rt_import_color(params[1], &e->scene.amb->color) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	e->scene.amb->has_ambient = 1;
	return (EXIT_SUCCESS);
}
