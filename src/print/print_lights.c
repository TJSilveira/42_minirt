/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:38:27 by amoiseik          #+#    #+#             */
/*   Updated: 2025/12/19 15:37:38 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

//added new file for printing lights and ambient. Devided print_scene_elements.c
void	print_scene_ambient(t_engine *e)
{
	if (e->scene.amb->has_ambient)
	{
		printf("[Ambient Color]\n");
		printf("Ambient Color:");
		print_vec3(&e->scene.amb->color);
		printf("Ambient Intensity: %f\n", e->scene.amb->intensity);
	}
	else
		printf("No Ambient light loaded\n");
}

void	print_scene_lights(t_engine *e)
{
	int	i;

	i = -1;
	if (e->scene.l_count == 0)
		printf("No Lights loaded\n");
	else
		printf("[%li Lights loaded]\n", e->scene.l_count);
	while (e->scene.lights[++i])
	{
		printf("[%i] Brightness: %f\n", i, e->scene.lights[i]->brightness);
		printf("[%i] Color:\n", i);
		print_vec3(&e->scene.lights[i]->color);
		printf("[%i] Center:\n", i);
		print_vec3(&e->scene.lights[i]->center);
		printf("\n");
	}
}
