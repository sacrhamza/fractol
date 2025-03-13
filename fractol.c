#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int get_color(int iterations, int max_iterations) {
    double t = (double)iterations / max_iterations;
    // Smooth interpolation between colors
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    return (r << 16) | (g << 8) | b;
}

int	is_within(double x, double y, t_translation translation)
{
	int iter = 0;
	t_fractal z = {0, 0};
	double	tmpx;

	while (power2(z.x) + power2(z.y) < 4 && iter < 300)
	{
		tmpx = z.x;
		z.x = power2(z.x) - power2(z.y) + x + translation.vertical;
		z.y = 2 * tmpx * z.y + y + translation.horizontal;
		iter++;
	}
	return (get_color(iter, 50));
}

int	draw_fractol(t_vars *vars,  t_translation translation)
{
	double	y;
	double	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			int color = is_within(((-1 * vars->x_offset) / 2 + (x)) / (WIDTH / vars->zoom), (vars->y_offset /2 - (y)) / (HEIGHT / vars->zoom), translation);	 
			my_mlx_pixel_put(&vars->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	moves(int keycode, t_vars *vars)
{
	static t_translation translation;

	if ((keycode >= 65361 && keycode <= 65364) || keycode == ESC)
	{
		if (keycode == RARROW)
			translation.vertical -= 0.04 * vars->zoom;
		else if (keycode == LARROW)
			translation.vertical += 0.04 * vars->zoom;
		else if (keycode == UARROW)
			translation.horizontal -= 0.04 * vars->zoom;
		else if (keycode == DARROW)
			translation.horizontal += 0.04 * vars->zoom;
		else if (keycode == ESC)
			close_window_and_exit(vars);
	}
	draw_fractol(vars, translation);
	return (0);
}

int	close_window_and_exit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}


int	mouse_up_down(int button, int x, int y, void *param)
{
	t_vars	*vars;

	vars = param;
	if (button == MOUSE_UP)
		vars->zoom *= 0.5;
	else if (button == MOUSE_DOWN)
		vars->zoom /= 0.5;
	moves(0, vars);
	(void)x;
	(void)y;
	return (0);
}

int	main()
{
	t_vars	vars;

	//initilize mlx pointer
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);

	//create a window for my fractol project
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");

	//create a new image
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	//TO DO: understand every member of every struct you have used
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	vars.zoom = 4;
	vars.x_offset = WIDTH;
	vars.y_offset = HEIGHT;

	draw_fractol(&vars, (t_translation){0, 0});
	mlx_hook(vars.win, 2, 1, moves, &vars); 

	mlx_hook(vars.win, 17, 0, close_window_and_exit, &vars);

	mlx_mouse_hook(vars.win, mouse_up_down, &vars);

	mlx_loop(vars.mlx);	
}
