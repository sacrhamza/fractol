#include "fractol.h"


double	ft_atod(char *str)
{
	double	number;
	size_t	i;
	int	sign;

	i = 0;
	number = 0;
	sign = 1;
	float	factor = 0.1;
	if (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + (str[i] - '0');
		i++;	
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			number += (str[i] - '0') * factor;
			factor *= 0.1;
			i++;	
		}
	}
	return (number * sign);
}
