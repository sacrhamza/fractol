#include "fractol.h"

int	mouse_up_down(int button, int x, int y, void *param)
{
	t_vars		*vars;
	t_fractal	mouse;

	vars = param;
	if (button == MOUSE_UP || button == MOUSE_DOWN)
	{
		mouse.x = ((-WIDTH / 2) + x) / (WIDTH / vars->zoom);
		mouse.y = ((HEIGHT / 2) - y) / (HEIGHT / vars->zoom);
		vars->translation.horizontal += mouse.x * (1 - 0.5);
		vars->translation.vertical += mouse.y * (1 - 0.5);
		if (button == MOUSE_UP)
			vars->zoom *= 0.5;
		else if (button == MOUSE_DOWN)
			vars->zoom /= 0.5;
		draw_fractol(vars);
	}
	return (0);
}
