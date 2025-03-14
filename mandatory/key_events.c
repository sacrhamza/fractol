#include "fractol.h"

int	moves(int keycode, t_vars *vars)
{
	t_fractal	tr_factor;

	tr_factor.x = SAMPLE_TRANSLATION_HORIZONTAL / (HEIGHT / vars->zoom);
	tr_factor.y = SAMPLE_TRANSLATION_VERTICAL / (HEIGHT / vars->zoom);
	if ((keycode >= 65361 && keycode <= 65364) || keycode == ESC || keycode == 'k' || keycode == 'j')
	{
		if (keycode == RARROW)
			vars->translation.horizontal -= tr_factor.x;
		else if (keycode == LARROW)
			vars->translation.horizontal += tr_factor.x;
		else if (keycode == UARROW)
			vars->translation.vertical -= tr_factor.y;
		else if (keycode == DARROW)
			vars->translation.vertical += tr_factor.y;
		else if (keycode == ESC)
			close_window_and_exit(vars);
		else if (keycode == 'k')
			vars->max_iteration++;
		else if (keycode == 'j')
			vars->max_iteration--;
		draw_fractol(vars);
	}
	return (0);
}
