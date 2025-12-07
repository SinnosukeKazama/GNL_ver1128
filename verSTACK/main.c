#include "get_next_line.h"
# include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test", O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
