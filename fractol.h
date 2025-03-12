#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# define ESC 65307
# define LARROW 65361
# define RARROW 65363
# define UARROW 65362 
# define DARROW 65364

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
}	t_vars;

typedef struct s_dimention
{
	int	x_size;
	int	y_size;	
}	t_dimention;

typedef struct fractal
{
	float	x;
	float	y;
}	t_fractal;

typedef struct s_translation
{
	float	vertical;
	float	horizontal;
}	t_translation;

float	power2(float number);
int		ft_tolower(int c);
void	ft_strlower(char *str);
int		close_window_and_exit(t_vars *vars);

#endif
