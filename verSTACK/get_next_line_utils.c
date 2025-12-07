/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skazama <skazama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:18:31 by skazama           #+#    #+#             */
/*   Updated: 2025/12/07 15:54:25 by skazama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			++i;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_getc(const int fd)
{
	static char	buf[BUFFER_SIZE];
	static char	*bufp;
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
	return ((unsigned char) *bufp++);
}

int	reallocate_str(t_string *str)
{
	char			*tmp;
	const size_t	new_capa = str->capa + BUFFER_SIZE;

	tmp = malloc((new_capa + 1) * sizeof(char));
	if (!tmp)
		return (ALLOCATE_FALSE);
	if (str->str)
		ft_strlcpy(tmp, str->str, str->len + 1);
	free (str->str);
	str->str = tmp;
	str->capa = new_capa;
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
	str->str[str->len] = '\0';
	return (0);
}
