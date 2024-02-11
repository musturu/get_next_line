
#include "get_next_line.h"

char  *get_next_line(int fd)
{
	char        *line;
	static char buf[4096][BUFFER_SIZE + 1];
	int          readr;
	int i;

	i = 0;
  readr = 1;
  line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (readr >= 0 && hasnl(line) == 0)
	{
		if (!*buf[fd])
			readr = read(fd, buf[fd], BUFFER_SIZE);
    if (readr <= 0)
      break;
		i++;
		line = ft_strealloc(line, i);
		cat_n_rem(line, buf[fd], 1);
	}
  //if (hasnl(line))
    //*hasnl(line) = '\0';
	if (line && *line)
		return (line);
	free(line);
	return (0);
}

/*
#include <string.h>

int	main()
{
	int fd = open("prova", O_RDONLY);

	int i = 0;
	while (i++ < 8)
	{
		printf("line%d:%s", i, get_next_line(fd));
	}
}*/
