/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:22:05 by nhuang            #+#    #+#             */
/*   Updated: 2023/11/27 19:36:28 by nhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *buffer, char *anchor)
{
	int		check;
	char	*temp;

	check = 1;
	while (check)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (NULL);
		else if (check == 0)
			break ;
		buffer[check] = '\0';
		if (!anchor)
			anchor = ft_strdup("");
		temp = anchor;
		anchor = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	return (anchor);
}

static char	*newline(char *theline)
{
	int		count;
	char	*anchor;

	count = 0;
	while (theline[count] != '\n' && theline[count] != '\0')
		count++;
	if (theline[count] == '\0' || theline[1] == '\0')
		return (0);
	anchor = ft_substr(theline, count + 1, ft_strlen(theline) - count);
	if (*anchor == '\0')
	{
		free(anchor);
		anchor = NULL;
	}
	theline[count + 1] = '\0';
	return (anchor);
}

char	*get_next_line(int fd)
{
	char		*theline;
	char		*buffer;
	static char	*anchor;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	theline = reader(fd, buffer, anchor);
	free(buffer);
	if (!theline)
		return (NULL);
	anchor = newline(theline);
	return (theline);
}
