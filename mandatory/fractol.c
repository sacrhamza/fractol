#include "fractol.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	is_within(t_fractal c, t_vars *vars)
{
	int iteration;
	t_fractal z;
	double	tmpx;

	iteration = 0;
	z = (t_fractal){0, 0};
	while ((power2(z.x) + power2(z.y) < 4) && (iteration < vars->max_iteration))
	{
		tmpx = z.x;
		z.x = power2(z.x) - power2(z.y) + c.x + vars->translation.horizontal;
		z.y = (2 * tmpx * z.y) + c.y + vars->translation.vertical;
		iteration++;
	}
	return (iteration * 256 + (float)iteration / 9 * 256 * 256);
}

int	draw_fractol(t_vars *vars)
{
	double	y;
	double	x;
	int	color;

	t_fractal c;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.x = ((-WIDTH / 2) + x) / (WIDTH / vars->zoom);
			c.y = ((HEIGHT / 2) - y) / (HEIGHT / vars->zoom);
			color = is_within(c, vars);	 
			my_mlx_pixel_put(&vars->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

void	fractal_init()
{
	t_vars	vars;

	//initilize mlx pointer
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return ;

	//create a window for my fractol project
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");

	//create a new image
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	if (vars.img.img == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return ;
	}

	//TO DO: understand every member of every struct you have used
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	vars.zoom = 4;
	vars.translation.vertical = 0;
	vars.translation.horizontal = 0;
	vars.max_iteration = SAMPLE_ITERATION;

	draw_fractol(&vars);
	mlx_hook(vars.win, 2, 1, moves, &vars); 

	mlx_hook(vars.win, 17, 0, close_window_and_exit, &vars);

	mlx_mouse_hook(vars.win, mouse_up_down, &vars);

	mlx_loop(vars.mlx);
}

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		check_arguments(argc - 1, argv + 1);
		fractal_init();
	}	
	else
		display_help();
}
