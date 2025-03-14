/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:19:00 by hsacr             #+#    #+#             */
/*   Updated: 2024/12/04 15:37:11 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_putstr(char *str, int *error)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (fn_putstr("(null)", error));
	while (*(str + i))
	{
		fn_putchar(str[i], error);
		if (*error == -1)
			return (-1);
		i++;
	}
	return (i);
}
