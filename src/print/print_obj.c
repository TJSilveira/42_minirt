/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:52:36 by tsilveir          #+#    #+#             */
/*   Updated: 2025/12/16 18:56:20 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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

void	print_scene_objects(t_engine *e)
{
	int	i;

	i = -1;
	if (e->scene.obj_count == 0)
		printf("No Objects loaded\n");
	else
		printf("[%li Objects loaded]\n", e->scene.obj_count);
	while (e->scene.objects[++i])
	{
		print_scene_sphere(e->scene.objects[i]);
		print_scene_plane(e->scene.objects[i]);
		print_scene_cylinder(e->scene.objects[i]);
	}
}

void	print_scene_sphere(t_object *obj)
{
	if (obj->id == id_sphere)
	{
		printf("[SPHERE]\n");
		printf("Color:\n");
		print_vec3(&obj->obj_union.sphere.color);
		printf("Center:\n");
		print_vec3(&obj->obj_union.sphere.center);
		printf("Ray: %f\n", obj->obj_union.sphere.ray);
		printf("\n");
	}
}

void	print_scene_plane(t_object *obj)
{
	if (obj->id == id_plane)
	{
		printf("[PLANE]\n");
		printf("Color:\n");
		print_vec3(&obj->obj_union.plane.color);
		printf("Normal:\n");
		print_vec3(&obj->obj_union.plane.normal);
		printf("Point:\n");
		print_vec3(&obj->obj_union.plane.point);
		printf("\n");
	}
}

void	print_scene_cylinder(t_object *obj) //added
{
	if (obj->id == id_cylinder)
	{
		printf("[CYLINDER]\n");
		printf("Color:\n");
		print_vec3(&obj->obj_union.cylinder.color);
		printf("Center:\n");
		print_vec3(&obj->obj_union.cylinder.center);
		printf("Normal/Axis:\n");
		print_vec3(&obj->obj_union.cylinder.normal);
		printf("Diameter: %f\n", obj->obj_union.cylinder.diam);
		printf("Height: %f\n", obj->obj_union.cylinder.h);
		printf("\n");
	}
}
