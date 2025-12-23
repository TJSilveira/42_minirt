/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoiseik <amoiseik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:51:05 by tsilveir          #+#    #+#             */
/*   Updated: 2025/12/17 15:28:44 by amoiseik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char *argv[])
{
	t_engine	eng;

	(void)(argv);
	if (argc != 2)
		show_help();
	rt_extension_check(argv);
	ft_memset(&eng, 0, sizeof(t_engine));
	init_engine(argv, &eng);
	mlx_put_image_to_window(eng.mlx, eng.window, eng.img.img, 0, 0);
	mlx_key_hook(eng.window, key_fig, &eng);
	mlx_hook(eng.window, 17, 0L, close_win, &eng);
	mlx_loop(eng.mlx);
	cleanup_engine(&eng);
	return (0);
}
