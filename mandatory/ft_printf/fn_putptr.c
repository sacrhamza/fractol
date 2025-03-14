/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:00:57 by hsacr             #+#    #+#             */
/*   Updated: 2024/11/27 09:44:06 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_printf.h"

int	fn_putptr(void *pointer, int *error)
{
	size_t	ptr;
	int		length;

	if (pointer == NULL)
		return (fn_putstr("(nil)", error));
	ptr = (size_t)pointer;
	length = fn_putstr("0x", error);
	length += fn_puthexptr(ptr, fn_tolower, error);
	return (length);
}
