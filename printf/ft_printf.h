/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:53:09 by nhuang            #+#    #+#             */
/*   Updated: 2023/07/18 19:51:55 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h> 

/* printf functions */
int	ft_printf(const char *s, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long long int n);
int	ft_putnbr_un(unsigned int n);
int	ft_puthex(unsigned int n, char check);
int	ft_pointer(size_t n);

#endif