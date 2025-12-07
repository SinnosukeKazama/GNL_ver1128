/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:18:12 by skazama           #+#    #+#             */
/*   Updated: 2025/12/07 16:04:45 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_string	ret;
	char		c;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > STACK_MAX)
		return (NULL);
	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break ;
		if (c == ERROR)
			return (free(ret.str), NULL);
		if (ft_putc(&ret, c) == ALLOCATE_FALSE)
			return (free(ret.str), NULL);
		if (c == '\n')
			break ;
	}
	return (ret.str);
}

/*
<Reference site>https://zenn.dev/grigri_grin/articles/bf45a9fa50f25f
*/
