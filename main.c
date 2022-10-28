#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = open("get_next_line.c", O_WRONLY);
	char	*s = get_next_line(fd);
	printf("%s", s);
}
