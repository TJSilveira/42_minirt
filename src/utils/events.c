#include "../includes/minirt.h"

int	close_win(t_engine *engine)
{
	cleanup_engine(engine);
	exit(EXIT_SUCCESS);
}
