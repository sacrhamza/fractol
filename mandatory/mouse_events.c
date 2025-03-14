#include "fractol.h"

int	mouse_up_down(int button, int x, int y, void *param)
{
	t_vars	*vars;
	double	mouse_re;
	double	mouse_img;

	vars = param;
	if (button == MOUSE_UP || button == MOUSE_DOWN)
	{
		mouse_re = ((-WIDTH / 2) + x) / (WIDTH / vars->zoom);
		mouse_img = ((HEIGHT / 2) - y) / (HEIGHT / vars->zoom);
		vars->translation.vertical += mouse_re * (1 - 0.5);
		vars->translation.horizontal += mouse_img * (1 - 0.5);
		if (button == MOUSE_UP)
			vars->zoom *= 0.5;
		else if (button == MOUSE_DOWN)
			vars->zoom /= 0.5;
		draw_fractol(vars);
	}
	return (0);
}
