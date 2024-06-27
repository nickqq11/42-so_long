/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:51:44 by nhuang            #+#    #+#             */
/*   Updated: 2023/07/18 20:00:26 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uppercase(char up)
{
	if (up >= 'a' && up <= 'f')
		up -= 32;
	write(1, &up, 1);
}

int	ft_puthex(unsigned int n, char check)
{
	int		count;
	char	*base_x;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count += 1;
		n *= -1;
	}
	base_x = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_puthex(n / 16, check);
		count += ft_puthex(n % 16, check);
	}
	else
	{
		if (check == 'x')
			write(1, &base_x[n], 1);
		if (check == 'X')
			ft_uppercase(base_x[n]);
		count++;
	}
	return (count);
}
