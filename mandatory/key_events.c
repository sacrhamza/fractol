#include "fractol.h"

int	moves(int keycode, t_vars *vars)
{
	if ((keycode >= 65361 && keycode <= 65364) || keycode == ESC)
	{
		if (keycode == RARROW)
			vars->translation.vertical -= 0.04 * vars->zoom;
		else if (keycode == LARROW)
			vars->translation.vertical += 0.04 * vars->zoom;
		else if (keycode == UARROW)
			vars->translation.horizontal -= 0.04 * vars->zoom;
		else if (keycode == DARROW)
			vars->translation.horizontal += 0.04 * vars->zoom;
		else if (keycode == ESC)
			close_window_and_exit(vars);
		draw_fractol(vars);
	}
	return (0);
}
