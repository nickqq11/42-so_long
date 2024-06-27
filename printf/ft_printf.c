/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:53:53 by nhuang            #+#    #+#             */
/*   Updated: 2023/07/18 19:52:21 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int	ft_portal(va_list args, char cha)
{
	unsigned long	ptr;

	if (cha == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (cha == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (cha == 'd' || cha == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (cha == 'u')
		return (ft_putnbr_un(va_arg(args, unsigned int)));
	if (cha == 'x' || cha == 'X')
		return (ft_puthex(va_arg(args, unsigned int), cha));
	if (cha == 'p')
	{
		ptr = va_arg(args, size_t);
		return (ft_pointer(ptr));
	}
	if (cha == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_eval(char cha)
{
	if (cha == 'c' || cha == 's' || cha == 'p' || cha == 'p' || cha == 'd'
		|| cha == 'i' || cha == 'u' || cha == 'x' || cha == 'X' || cha == '%')
		return (1);
	else
		return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && (ft_eval(s[i + 1]) == 1))
		{
			length += ft_portal(args, s[i + 1]);
			i++;
		}
		else
			length += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}
