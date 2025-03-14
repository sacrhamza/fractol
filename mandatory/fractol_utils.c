#include "fractol.h"

double	power2(double number)
{
	return (pow(number, 2));
}

int	ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') * 32 + c);
}

char	*ft_strlower(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		str[index] = ft_tolower(str[index]);
		index++;
	}
	return (str);
}

double	ft_atof(char *str)
{
	(void)str;
	return (2.0);	
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

int	double_valid(char *str)
{
	int	i;
	int	has_dot;
	int	has_i;

	has_dot = 0;
	i = 0;
	has_i = 0;
	while (str[i])
	{
		if ((str[i] == '.' && i == 0)
			|| has_dot > 1 || has_i > 1
			|| (ft_issign(str[i]) && ft_isdigit(str[i + 1]) != 1))
			return (NBR_NOT_VALID);
		if (str[i] == '.' || str[i] == 'i')
		{
			if (str[i] == '.')
				has_dot++;
			else if (str[i] == 'i')
				has_i++;
			i++;
			continue ;
		}
		if (ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0 && ft_issign(str[i]) == 0) 
			return (NBR_NOT_VALID);
		i++;		
	}	
	return (NBR_VALID);
}
