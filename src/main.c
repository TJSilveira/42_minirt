#include "../includes/minirt.h"

int main(int argc, char *argv[])
{
	t_engine	eng;

	(void)(argv);
	if (argc == 1)
		// show_help();
		
	ft_memset(&eng, 0, sizeof(t_engine));
	init_engine(&eng);
	mlx_put_image_to_window(eng.mlx, eng.window, eng.img.img, 0, 0);
	mlx_loop(eng.mlx);
	
    return(0);
}
