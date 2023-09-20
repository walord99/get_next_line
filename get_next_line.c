/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 10:18:33 by bplante           #+#    #+#             */
/*   Updated: 2023/09/20 12:30:44 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *buffer);
static char	*remove_line(char *buffer);
static char	*read_to_buff(char *buffer, int fd);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	buffer = read_to_buff(buffer, fd);
	line = get_line(buffer);
	buffer = remove_line(buffer);
	return (line);
}

char	*read_to_buff(char *buffer, int fd)
{
	char	*read_buffer;
	int		read_check;

	read_buffer = malloc(BUFFER_SIZE + 1);
	read_check = BUFFER_SIZE;
	while (!ft_strchr(buffer, '\n') && read_check == BUFFER_SIZE)
	{
		read_check = read(fd, read_buffer, BUFFER_SIZE);
		if (read_check == -1)
		{
			free(read_buffer);
			free(buffer);
			return (NULL);
		}
		read_buffer[read_check] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
	}
	free(read_buffer);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	if (ft_strlen(buffer) == 0)
		return (NULL);
	else if (ft_strchr(buffer, '\n'))
		line = malloc(ft_strchr(buffer, '\n') - buffer + 2);
	else
		line = malloc(ft_strlen(buffer) + 1);
	i = 0;
	while (buffer[i])
	{
		line[i] = buffer[i];
		i++;
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

char	*remove_line(char *buffer)
{
	char	*new_buff;
	char	*next_line;
	int		i;

	if (ft_strlen(buffer) == 0 || !ft_strchr(buffer, '\n'))
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_strchr(buffer, '\n') + 1;
	new_buff = malloc(ft_strlen(next_line) + 1);
	i = 0;
	while (next_line[i])
	{
		new_buff[i] = next_line[i];
		i++;
	}
	new_buff[i] = '\0';
	free(buffer);
	return (new_buff);
}
