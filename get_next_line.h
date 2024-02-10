#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
# endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

char  *cat_n_rem(char *dst, char *src);
void	*ft_strealloc(char *str, int cycle);
int	hasnl(char *str);
void *ft_calloc(size_t num, size_t size);

#endif
