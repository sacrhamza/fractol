/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:31:41 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 21:11:27 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_puthex(unsigned int n, int (*f)(int), int *error)
{
	int		length;
	char	ch_number;
	char	*numbers;

	if (*error == -1)
		return (-1);
	numbers = "0123456789abcdef";
	length = 0;
	if (n >= 16)
	{
		ch_number = f(*(numbers + (n % 16)));
		length += fn_puthex(n / 16, f, error);
		n -= (n % 16);
		length += fn_putchar(ch_number, error);
	}
	if (n < 16)
		length += fn_putchar(f(*(numbers + n)), error);
	return (length);
}
