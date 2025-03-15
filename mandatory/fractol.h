#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
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
# define SAMPLE_TRANSLATION_VERTICAL 10
# define SAMPLE_TRANSLATION_HORIZONTAL 30

# define RED "\e[31m"
# define GREEN "\e[32m"
# define BLUE "\e[36m"
# define YELLOW "\e[33m"
# define PURPLE "\e[34m"
# define CYAN "\e[36m"
# define RESET "\e[00m"

# define NBR_NOT_VALID 0
# define NBR_VALID 1
# define VALID 1
# define NBR_IS_COMPLEX 2

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
	t_translation	translation;
	int		max_iteration;
}	t_vars;

typedef struct s_fractal
{
	double	x;
	double	y;
}	t_fractal;

typedef struct s_check
{
	size_t	len;
	char	*str;
	int	dot_number;
	int	sign_number;
	int	complex_number;
	
}	t_check;

int		close_window_and_exit(t_vars *vars);
int		moves(int keycode, t_vars *vars);
int		mouse_up_down(int button, int x, int y, void *param);
int		draw_fractol(t_vars *vars);
int		close_window_and_exit(t_vars *vars);
int		ft_tolower(int c);
char	*ft_strlower(char *str);
void	check_arguments(int n, char *argv[]);
void	fractal_init();
void	display_help(void);
double	power2(double number);
double	ft_atod(char *str);
int	ft_printf(char *format, ...);
int	double_valid(char *str);
int	ft_isspace(int c);
int	ft_issign(int c);
int	ft_isdigit(int c);
#endif
