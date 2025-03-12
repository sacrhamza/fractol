#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_fractal	iteration(t_fractal fractal, int count, t_translation translation)
{
	t_fractal new = {0, 0};
	float	tmpx;
	while (count)
	{	
		tmpx = new.x;
		new.x = power2(new.x) - power2(new.y) + fractal.x + translation.vertical;
		new.y = 2 * tmpx * new.y + fractal.y + translation.horizontal;
		count--;
	}
	return (new);
}

int	is_within(float x, float y, t_translation translation)
{
	int iter = 0;
	t_fractal fractal = {x, y};
	t_fractal fractal1;

	float	magnitude;

	magnitude = 0;
	while (magnitude < 4 && iter < 30)
	{
		fractal1 = iteration(fractal, iter, translation);
		magnitude = power2(fractal1.x) + power2(fractal1.y);
		iter++;
	}
	//printf("%f | %f | %d\n", x, y, iter);
	//return (0x00000000 + iter * 50 + (iter / 100 * pow(256, 4)));
	//return (0x0000000 + iter * 265 * 265 * 265 * 2);
	return (iter * pow(10, 3));
}

int	draw_fractol(t_vars *vars, int x_size, int y_size, t_translation translation)
{
	int	y;
	int	x;
	y = 0;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			int color = is_within((-x_size / 2 + ((float)x)) / (x_size / vars->zoom), (y_size /2 - ((float)y)) / (y_size / vars->zoom), translation);	 
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

	if (keycode == RARROW)
		translation.vertical -= 0.04;
	else if (keycode == LARROW)
		translation.vertical += 0.04;
	else if (keycode == UARROW)
		translation.horizontal -= 0.04;
	else if (keycode == DARROW)
		translation.horizontal += 0.04;
	else if (keycode == ESC)
		close_window_and_exit(vars);
	//printf("vertical = %f horizontal = %f\n", translation.vertical, translation.horizontal);
	draw_fractol(vars, 1000, 1000, translation);

	//mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, bye, 0);
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
		vars->zoom += 0.5;
	else if (button == MOUSE_DOWN)
		vars->zoom -= 0.5;
	moves(0, vars);
	(void)x;
	(void)y;
	//printf("button = %d | x = %d | y = %d | %p\n", button, x, y, vars);
	return (0);
}

int	main()
{
	t_vars	vars;
	int	(y_size) = 1000;
	int	(x_size) = 1000;

	//initilize mlx pointer
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (1);

	//create a window for my fractol project
	vars.win = mlx_new_window(vars.mlx, x_size, y_size, "fractol");

	//create a new image
	vars.img.img = mlx_new_image(vars.mlx, x_size, y_size);
	//TO DO: understand every member of every struct you have used
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	vars.zoom = 4;

	draw_fractol(&vars, x_size, y_size, (t_translation){0, 0});
	mlx_hook(vars.win, 2, 1, moves, &vars); 

	mlx_hook(vars.win, 17, 0, close_window_and_exit, &vars);

	mlx_mouse_hook(vars.win, mouse_up_down, &vars);

	mlx_loop(vars.mlx);	
}
