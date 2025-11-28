#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define ERROR -2
#define ALLOCATE_FALSE -3
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif//BUFFER_SIZE

typedef struct	s_string
{
	char	*str;
	size_t len;
	size_t capa;
}	t_string;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int	ft_getc(const int fd);
int	ft_putc(t_string *str, char c);
int	reallocate_str(t_string *str);
