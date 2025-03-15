/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:01:55 by hsacr             #+#    #+#             */
/*   Updated: 2025/03/15 14:01:56 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

double	power2(double number)
{
	return (number * number);
}

int	ft_tolower(int c)
{
	return ((c >= 'A' && c <= 'Z') * 32 + c);
}
