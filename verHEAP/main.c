#include "get_next_line.h"
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
