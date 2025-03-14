/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:23:17 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 21:10:19 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_global(char c, va_list args, int *there_is_an_error)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = fn_putchar(va_arg(args, int), there_is_an_error);
	else if (c == 's')
		length = fn_putstr(va_arg(args, char *), there_is_an_error);
	else if (c == 'p')
		length = fn_putptr(va_arg(args, void *), there_is_an_error);
	else if (c == 'x')
		length = fn_puthex(va_arg(args, unsigned int),
				fn_tolower, there_is_an_error);
	else if (c == 'X')
		length = fn_puthex(va_arg(args, unsigned int),
				fn_toupper, there_is_an_error);
	else if (c == 'd' || c == 'i')
		length = fn_putnbr(va_arg(args, int), there_is_an_error);
	else if (c == 'u')
		length = fn_putus(va_arg(args, unsigned int), there_is_an_error);
	else if (c == '%')
		length = fn_putchar(c, there_is_an_error);
	return (length);
}
