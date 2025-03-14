#include "fractol.h"

void	display_help()
{

	ft_printf(BLUE"fractol:\t"GREEN"./fractol <OPTION> ...\n\n");
	ft_printf(PURPLE"list of valid options:\n\n");
	ft_printf(GREEN"-m, mandelbrot, --mandelbrot\t"YELLOW"display mandelbrot set\n\n");
	ft_printf(PURPLE"list of valid keybindings:\n\n"RESET);
	//ft_printf("");
	exit(0);
}

void	check_arguments(int n_arg, char *argv[])
{
	//t_fractal	nbr;

	if (n_arg == 1 && strcmp(ft_strlower(argv[0]), "mandelbrot") == 0)
		fractal_init();
	else if (n_arg == 3 && strcmp(ft_strlower(argv[0]), "julia") == 0)
	{
		if (!double_valid(argv[1]) || !double_valid(argv[2]))
			display_help();
	}
	else
		display_help();
}
