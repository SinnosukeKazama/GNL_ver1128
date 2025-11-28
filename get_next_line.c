#include "get_next_line.h"

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
		return EOF;
	else if (n < 0)
		return ERROR;
	--n;
	return (unsigned char) *bufp++;
}

int	reallocate_str(t_string *str)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + str->capa));
	if (!tmp)
		return ALLOCATE_FALSE;
	if (str->str)
		ft_strlcpy(tmp, str->str, str->len +1);
	free (str->str);
	str->str = tmp;
	str->capa += BUFFER_SIZE;
	return 0;
}

int	ft_putc(t_string *str, char c)
{
	if (str->len + 1 > str->capa)
	{
		if (reallocate_str(str)==ALLOCATE_FALSE)
			return ALLOCATE_FALSE;
	}
	str->str[str->len] = c;
	str->len++;
	return 0;
}

char	*get_next_line(int fd)
{
	t_string	ret;
	char		c;

	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;
	while (1)
	{
		c = ft_getc(fd);
		if (c == EOF)
			break;
		if (c == ERROR)
			return (free(ret.str), NULL);
		int f = ft_putc(&ret, c);
		if (f == ALLOCATE_FALSE)
			return (free(ret.str), NULL);
		if (c == '\n')
			break;
	}
	if (ret.len > 0)
		ft_putc(&ret, '\0');
	return ret.str;
}

////////////////////
#include <stdio.h>
int main(void)
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *s;
	while ((s = get_next_line(fd)))
	{
		printf("%s",s);
		free(s);
	}
	close(fd);
	return 0;
}
