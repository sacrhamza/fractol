/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:36:48 by hsacr             #+#    #+#             */
/*   Updated: 2024/11/25 16:20:13 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_putus(unsigned int n, int *error)
{
	int	length;

	if (*error == -1)
		return (-1);
	length = 0;
	if (n >= 10)
	{
		length += fn_putus(n / 10, error);
		length += fn_putchar((n % 10) + '0', error);
	}
	if (n < 10)
		length += fn_putchar(n + '0', error);
	return (length);
}
