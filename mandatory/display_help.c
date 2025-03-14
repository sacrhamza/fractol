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
	if (n_arg == 1 && strcmp(ft_strlower(argv[0]), "mandelbrot") == 0)
		fractal_init();
	else if (n_arg == 3 && strcmp(ft_strlower(argv[0]), "julia") == 0)
		;
	else
		display_help();
}
