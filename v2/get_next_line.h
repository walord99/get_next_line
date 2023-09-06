/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:36:12 by bplante           #+#    #+#             */
/*   Updated: 2023/07/17 15:10:19 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char *ft_strchr(char *str, char c);
int ft_strlen(char *str);
char *ft_strjoin_s(char *s1, char *s2);

#endif
