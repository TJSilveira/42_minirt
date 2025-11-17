#include "../includes/minirt.h"

void write_color(color3 *c)
{
	ft_putnbr_fd((int)(255.999 * c->e[0]), STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putnbr_fd((int)(255.999 * c->e[1]), STDOUT_FILENO);
	ft_putstr_fd(" ", STDOUT_FILENO);
	ft_putnbr_fd((int)(255.999 * c->e[2]), STDOUT_FILENO);
}