#include "fractol.h"


typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;


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
float	power3(float number)
{
	return (pow(number, 3));
}

typedef struct fractal
{
	float	x;
	float	y;
}	t_fractal;

t_fractal	iteration(t_fractal fractal, int count)
{
	t_fractal new = {0, 0};
	float	tmpx;
	while (count)
	{
		tmpx = new.x;
		new.x = power2(new.x) - power2(new.y) + fractal.x;
		new.y = 2 * tmpx * new.y + fractal.y;
		count--;
	}
	return (new);
}

int	is_within(float x, float y)
{
	int iter = 0;
	t_fractal fractal = {x, y};
	t_fractal fractal1;

	float	magnitude;

	magnitude = 0;
	while (magnitude < 4 && iter < 50)
	{
		fractal1 = iteration(fractal, iter);
		magnitude = power2(fractal1.x) + power2(fractal1.y);
		iter++;
	}
	//printf("%f | %f\n", x, y);
	//return (0x00000000 + iter * 50 + (iter / 100 * pow(256, 4)));
	return (0x0000000 + iter * 265 * 265 * 265 * 2);
	//return (iter * pow(265, 1));
}

int	draw_fractol(void *mlx, void *mlx_window, int x_size, int y_size)
{
	int	y = 0;
	int	x = 0;
	t_data	img;
	img.img = mlx_new_image(mlx, x_size, y_size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		y = 0;
		while (y < y_size)
		{
			x = 0;
			while (x < x_size)
			{
				int color = is_within((-x_size / 2 + (float)x) / (x_size / 4), (y_size /2 - (float)y) / (y_size / 4)); 
				my_mlx_pixel_put(&img, x, y, color);
				x++;
			}
			y++;
		}
		mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
}

int	main()
{
	void	*mlx;
	void	*mlx_window;
	int	(y_size) = 1000;
	int	(x_size) = 1000;

	//initilize mlx pointer
	mlx = mlx_init();

	//create a window for my fractol project
	mlx_window = mlx_new_window(mlx, x_size, y_size, "fractol");

	draw_fractol(mlx, mlx_window, x_size, y_size);

	mlx_loop(mlx);	

	//cleanup everything
	mlx_destroy_window(mlx, mlx_window);
	mlx_destroy_display(mlx);
	free(mlx);
}
