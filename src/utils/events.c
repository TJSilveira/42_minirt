#include "../includes/minirt.h"

int	close_win(t_engine *engine)
{
	cleanup_engine(engine);
	exit(EXIT_SUCCESS);
}

int	key_fig(int key, t_engine *e)
{
	if (key == KEY_ESC)
		close_win(e);
	// else if (key == '0')
	// 	zoom_reset(e);
	// else if (key == LEFTARROW)
	// 	arrow_move(e, 0.0, -1.0);
	// else if (key == RIGHTARROW)
	// 	arrow_move(e, 0.0, 1.0);
	// else if (key == UPARROW)
	// 	arrow_move(e, 1.0, 0.0);
	// else if (key == DOWNARROW)
	// 	arrow_move(e, -1.0, 0.0);
	// else if (key == 'q')
	// 	update_color_scheme(e, 0x0000FF00, 0x00FF0000);
	// else if (key == 'w')
	// 	update_color_scheme(e, 0x0000FF00, 0x000000FF);
	// else if (key == 'e')
	// 	update_color_scheme(e, 0x00FF0000, 0x0000FF00);
	// else if (key == 'r')
	// 	update_color_scheme(e, 0x000000FF, 0x00FF0000);
	return (0);
}
