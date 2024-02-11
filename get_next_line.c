
#include "get_next_line.h"

char  *get_next_line(int fd)
{
	char        *line;
	static char buf[BUFFER_SIZE + 1];
	int          readr;
	int i;

	i = 0;
  readr = 1;
  line = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (readr >= 0 && hasnl(line) == 0)
	{
		if (!*buf)
			readr = read(fd, buf, BUFFER_SIZE);
    if (readr <= 0)
      break;
		i++;
		line = ft_strealloc(line, i);
		line = cat_n_rem(line, buf, 1);
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
