#include "../mandatory/fractol.h"
#include <limits.h>
#include <float.h>

int main(int argc, char **argv)
{
	printf("%.25lf\n", ft_atod(argv[1]));
	printf("%.100lf\n", FLT_MIN);
	return (0);
}
