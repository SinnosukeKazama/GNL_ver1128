/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:18:12 by skazama           #+#    #+#             */
/*   Updated: 2025/11/30 12:42:50 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(const int fd, char *buf)
{
	static char*	bufp;//bufがfreeされたときもこれはそのポインタを参照し続けるー＞セグフォの原因。
	static int	n = 0;

	if (n == 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		bufp = buf;
	}
	if (n == 0)
		return (EOF);
	else if (n < 0)
		return (ERROR);
	--n;
	return ((unsigned char)*bufp++);
}

int	reallocate_str(t_string *str)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + str->capa));
	if (!tmp)
		return (ALLOCATE_FALSE);
	if (str->str)
		ft_strlcpy(tmp, str->str, str->len + 1);
	free(str->str);
	str->str = tmp;
	str->capa += BUFFER_SIZE;
	return (0);
}

int	ft_putc(t_string *str, char c)
{
	if (str->len + 1 > str->capa)
	{
		if (reallocate_str(str) == ALLOCATE_FALSE)
			return (ALLOCATE_FALSE);
	}
	str->str[str->len] = c;
	str->len++;
	return (0);
}

char	*get_next_line(int fd)
{
	t_string	ret;
	char		c;
	char		*buf;

	buf = malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;
	while (1)
	{
		c = ft_getc(fd, buf);

		if (c == EOF)
			break ;
		if (c == ERROR)
			return (free(buf), free(ret.str), NULL);
		if (ft_putc(&ret, c) == ALLOCATE_FALSE)
			return (free(buf), free(ret.str), NULL);
		if (c == '\n')
			break ;
	}
	if (ret.len > 0)
		ft_putc(&ret, '\0');
	return (free(buf), ret.str);
}

/*
<Reference site>https://zenn.dev/grigri_grin/articles/bf45a9fa50f25f
*/
