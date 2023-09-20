#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	do
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	} while (line);
}
