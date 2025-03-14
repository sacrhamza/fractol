/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsacr <hsacr@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:35:53 by hsacr             #+#    #+#             */
/*   Updated: 2025/01/03 21:10:33 by hsacr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_PRINTF_H
# define FN_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_printf(char *format, ...);
int		fn_global(char c, va_list args, int *there_is_an_error);
int		fn_putchar(char c, int *error);
int		fn_putstr(char *str, int *error);
int		fn_putptr(void *pointer, int *error);
int		fn_puthexptr(size_t n, int (*f)(int), int *error);
int		fn_puthex(unsigned int n, int (*f)(int), int *error);
int		fn_putnbr(int number, int *error);
char	*fn_itoa(int n);
int		ft_itoa_length(long number);
int		fn_putus(unsigned int n, int *error);
int		fn_tolower(int c);
int		fn_toupper(int c);

#endif
