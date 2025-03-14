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
# define MOUSE_UP 5
# define MOUSE_DOWN 4 
# define WIDTH 800 
# define HEIGHT 800 
# define SAMPLE_ITERATION 100

# define power2(var) (var * var)

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_translation
{
	double	vertical;
	double	horizontal;
}	t_translation;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	double	zoom;
	t_translation translation;
	int	max_iteration;
}	t_vars;

typedef struct fractal
{
	double	x;
	double	y;
}	t_fractal;

int		ft_tolower(int c);
void	ft_strlower(char *str);
int		close_window_and_exit(t_vars *vars);
int	moves(int keycode, t_vars *vars);
int	mouse_up_down(int button, int x, int y, void *param);
int	draw_fractol(t_vars *vars);
int	close_window_and_exit(t_vars *vars);
#endif
