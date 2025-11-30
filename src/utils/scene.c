#include "../includes/minirt.h"

void add_object_to_scene(t_scene *s, t_object *obj)
{
	if (s->obj_count > s->obj_capacity)
		exit(1); // TODO: Add error handling function
	s->objects[s->obj_count] = obj;
	s->obj_count += 1;
}

void add_light_to_scene(t_scene *s, t_light *light)
{
	if (s->l_count > s->l_capacity)
		exit(1); // TODO: Add error handling function
	s->lights[s->l_count] = light;
	s->l_count += 1;
}

void	init_scene(t_engine *e)
{
	e->scene.objects = ft_calloc(sizeof(t_object*), MAX_OBJECTS);
	if (!e->scene.objects)
		error_handler("Calloc was not successful\n", e);
	e->scene.lights = ft_calloc(sizeof(t_light*), MAX_OBJECTS);
	if (!e->scene.lights)
		error_handler("Calloc was not successful\n", e);
	e->scene.obj_capacity = MAX_OBJECTS;
	e->scene.obj_count = 0;
	e->scene.l_capacity = MAX_OBJECTS;
	e->scene.l_count = 0;
	e->scene.amb = NULL;
}

void import_rt_file_definitions(char *argv[], t_engine *e)
{
	int		fd;
	char	*buffer;
	char	**params;
	
	init_scene(e);
	fd = open(argv[1], O_RDONLY);
	buffer = get_next_line(fd, TO_USE);
	while (buffer)
	{
		params = rt_file_parser(buffer);
		if (params)
		{
			if (rt_importer_params(params, e) == EXIT_FAILURE)
			{
				free(buffer);
				buffer = get_next_line(fd, TO_CLEAN);
				close(fd);
				error_handler("Failure importing parameters\n", e);
			}
		}		
		free(buffer);
		free_arrays(params);
		buffer = NULL;
		buffer = get_next_line(fd, TO_USE);
	}
	close(fd);
}
