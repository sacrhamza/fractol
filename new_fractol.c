#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float	power2(float number)
{
	return (pow(number, 2));
}




t_fractal	iteration(t_fractal fractal, int count, float bye)
{
	t_fractal new = {0, 0};
	float	tmpx;
	while (count)
	{
		tmpx = new.x;
		new.x = power2(new.x) - power2(new.y) + fractal.x + bye;
		new.y = 2 * tmpx * new.y + fractal.y;
		count--;
	}
	return (new);
}

int	is_within(float x, float y, float bye)
{
	int iter = 0;
	t_fractal fractal = {x, y};
	t_fractal fractal1;

	float	magnitude;

	magnitude = 0;
	while (magnitude < 4 && iter < 50)
	{
		fractal1 = iteration(fractal, iter, bye);
		magnitude = power2(fractal1.x) + power2(fractal1.y);
		iter++;
	}
	//printf("%f | %f\n", x, y);
	//return (0x00000000 + iter * 50 + (iter / 100 * pow(256, 4)));
	return (0x0000000 + iter * 265 * 265 * 265 * 2);
	//return (iter * pow(265, 1));
}

int	draw_fractol(t_vars *vars, int x_size, int y_size, float bye)
{
	int	y;
	int	x;
	vars->img.img = mlx_new_image(vars->mlx, x_size, y_size);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	y = 0;
	while (y < y_size)
	{
		x = 0;
		while (x < x_size)
		{
			int color = is_within((-x_size / 2 + (float)x) / (x_size / 4), (y_size /2 - (float)y) / (y_size / 4), bye);	 
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
	static float bye;

	if (keycode == RARROW)
		bye += 5;
	else if (keycode == LARROW)
		bye -= 5;
	//else if (keycode == UARROW)
	//	;
	//else if (keycode == DARROW)
	//	;
	else if (keycode == ESC)
		close_window_and_exit(vars);
	//draw_fractol(vars, 1000, 1000, bye);

	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, bye, 0);
	printf("%f\n", bye);
	return (0);
}

void	close_window_and_exit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}

int	main()
{
	t_vars	vars;
	int	(y_size) = 1000;
	int	(x_size) = 1000;

	//initilize mlx pointer
	vars.mlx = mlx_init();

	//create a window for my fractol project
	vars.win = mlx_new_window(vars.mlx, x_size, y_size, "fractol");

	mlx_hook(vars.win, 2, 1, moves, &vars); 

	draw_fractol(&vars, x_size, y_size, 0);

	mlx_loop(vars.mlx);	
}
