#include "fractol.h"

int	moves(int keycode, t_vars *vars)
{
	t_fractal	tr_factor;

	tr_factor.x = 2 / (HEIGHT / vars->zoom);
	tr_factor.y = 2 / (HEIGHT / vars->zoom);
	if ((keycode >= 65361 && keycode <= 65364) || keycode == ESC)
	{
		if (keycode == RARROW)
			vars->translation.vertical -= tr_factor.x;
		else if (keycode == LARROW)
			vars->translation.vertical += tr_factor.x;
		else if (keycode == UARROW)
			vars->translation.horizontal -= tr_factor.y;
		else if (keycode == DARROW)
			vars->translation.horizontal += tr_factor.y;
		else if (keycode == ESC)
			close_window_and_exit(vars);
		draw_fractol(vars);
	}
	return (0);
}
