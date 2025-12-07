/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:18:21 by skazama           #+#    #+#             */
/*   Updated: 2025/12/07 16:10:05 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define ERROR -2
# define ALLOCATE_FALSE -3
# define STACK_MAX 8192000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif//BUFFER_SIZE

typedef struct s_string
{
	char	*str;
	size_t	len;
	size_t	capa;
}	t_string;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_getc(const int fd);
int		ft_putc(t_string *str, char c);
int		reallocate_str(t_string *str);

#endif//GET_NEXT_LINE_H
