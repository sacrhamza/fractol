/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:00:54 by hsacr             #+#    #+#             */
/*   Updated: 2024/11/25 15:34:31 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_putnbr(int number, int *error)
{
	char	*ptr;
	int		length;

	if (*error == -1)
		return (-1);
	ptr = fn_itoa(number);
	length = fn_putstr(ptr, error);
	free(ptr);
	return (length);
}
