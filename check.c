/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:58:40 by nhuang            #+#    #+#             */
/*   Updated: 2024/06/28 11:12:17 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int check_ber(char **argv)
{
	char *temp;

	temp = ft_strrchr(argv[1], '.');
	if (!temp)
		return(ft_printf("map file format not .ber"));
	return(ft_strncmp(temp, ".ber", 4));
}

int check_all(char **argv)
{
	check_ber(argv);
}