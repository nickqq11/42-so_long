/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:29:15 by nhuang            #+#    #+#             */
/*   Updated: 2023/07/18 18:53:16 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long int n)
{
	int		count;
	char	*base;

	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		count += 1;
		n = n * -1;
	}
	base = "0123456789";
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		write(1, &base[n], 1);
		count++;
	}
	return (count);
}
