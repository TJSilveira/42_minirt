#include "../includes/minirt.h"

int main(int argc, char *argv[])
{
	t_engine	eng;

	(void)(argv);
	if (argc == 1)
		show_help();
	rt_extension_check(argv);

	ft_memset(&eng, 0, sizeof(t_engine));
	init_engine(argv, &eng);
	mlx_put_image_to_window(eng.mlx, eng.window, eng.img.img, 0, 0);
	mlx_hook(eng.window, 17, 0L, close_win, &eng);
	mlx_loop(eng.mlx);
	
    return(0);
}
