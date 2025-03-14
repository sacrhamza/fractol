#include "fractol.h"

float	power2(float number)
{
	return (pow(number, 2));
}

int	ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') * 32 + c);
}

void	ft_strlower(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_tolower(str[index]);
		index++;
	}
}
