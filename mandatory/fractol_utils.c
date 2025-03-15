#include "fractol.h"



int	check_sign(t_check *check, int index)
{
	int	is_sign;

	is_sign = ft_issign(check->str[index]);
	if ((is_sign && (!ft_isdigit(check->str[index + 1]) 
		&& check->str[index + 1] != 'i'))
			|| (is_sign && index != 0))
		return (NBR_NOT_VALID);	
	if (is_sign)
		check->sign_number++;
	if (check->sign_number > 1)
		return (NBR_NOT_VALID);
	return (NBR_VALID);
}

int	check_dot(t_check *check, int index)
{
	int	is_dot;
	int	len;

	len = check->len;
	is_dot = check->str[index] == '.';
	if ((is_dot && ft_isdigit(check->str[index + 1]) != VALID)
		|| (is_dot && (index + 1 == len || index == 0)))
		return (NBR_NOT_VALID);
	if (is_dot)
		check->dot_number++;
	if (check->dot_number > 1)
		return (NBR_NOT_VALID);
	return (NBR_VALID);
}

int	check_valid_chars(char c)
{
	if (!ft_issign(c) && !ft_isdigit(c) && c != 'i' && c != '.' && !ft_isspace(c))
		return (NBR_NOT_VALID);
	return (NBR_VALID);
}

int	check_complex_nbr(t_check *check, int index)
{
	int	is_complex_nbr;
	int	len;

	len = check->len;
	is_complex_nbr = check->str[index] == 'i';
	if (is_complex_nbr && index + 1 != len)
		return (NBR_NOT_VALID);
	if (is_complex_nbr)
		check->complex_number++;
	if (check->complex_number > 1)
		return (NBR_NOT_VALID);
	return (NBR_VALID);
}

int	double_valid(char *str)
{
	size_t	i;
	t_check check;

	check = (t_check){strlen(str), str, 0, 0, 0};
	i = 0;
	while (str[i])
	{
		if (check_sign(&check, i) == NBR_NOT_VALID)
			return (NBR_NOT_VALID);
		if (check_dot(&check, i) == NBR_NOT_VALID)
			return (NBR_NOT_VALID);
		if (check_complex_nbr(&check, i) == NBR_NOT_VALID)
			return (NBR_NOT_VALID);
		if (check_valid_chars(str[i]) == NBR_NOT_VALID)
			return (NBR_NOT_VALID);
		i++;	
	}	
	return (NBR_VALID + check.complex_number);
}

