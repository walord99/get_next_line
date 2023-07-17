/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:36:20 by bplante           #+#    #+#             */
/*   Updated: 2023/07/17 15:26:37 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_into_buffer(int fd, char *buffer);
static char	*extract_remove(char **buffer);
static char	*extract_line(char *buffer);
static char	*remove_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;

	buffer = read_into_buffer(fd, buffer);
	return (extract_remove(&buffer));
	//read and append into buffer until contains newline if buffer doesnt contain
	//return up until newline
	//delete up until newline
}

static char	*read_into_buffer(int fd, char *buffer)
{
	size_t	read_check;
	char	read_buffer[BUFFER_SIZE + 1];

	read_check = BUFFER_SIZE;
	read_buffer[BUFFER_SIZE] = 0;
	while (!ft_strchr(buffer, '\n') && read_check == BUFFER_SIZE)
	{
		read_check = read(fd, read_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, read_buffer);
	}
	while (read_check != BUFFER_SIZE)
		buffer[ft_strlen(buffer) - (BUFFER_SIZE - read_check++)] = 0;
	return (buffer);
}

static char	*extract_remove(char **buffer)
{
	char	*line;

	line = extract_line(*buffer);
	*buffer = remove_line(*buffer);
	return (line);
}

static char	*extract_line(char *buffer)
{
	size_t	line_lenght;
	char	*line;
	size_t	i;

	if (ft_strchr(buffer, '\n'))
		line_lenght = ft_strchr(buffer, '\n') - buffer + 1;
	else
		line_lenght = ft_strlen(buffer);
	if (line_lenght == 0)
		return (NULL);
	line = malloc(line_lenght + 1);
	line[line_lenght] = 0;
	i = 0;
	while (line_lenght--)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

static char	*remove_line(char *buffer)
{
	char	*new_buffer;

	if (ft_strchr(buffer, '\n'))
		new_buffer = ft_strdup(ft_strchr(buffer, '\n') + 1);
	else
		new_buffer = NULL;
	free(buffer);
	return (new_buffer);
}
