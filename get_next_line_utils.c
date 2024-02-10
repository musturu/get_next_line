#include "get_next_line.h"

char  *cat_n_rem(char *dst, char *src)
{
	int	i;
	int	j;
  //printf("dst:<%s> src:<%s>\n", dst, src);
	i = 0;
	j = 0;
	while(dst[j])
		j++;
	while(src[i])
	{
		dst[i + j] = src[i];
		src[i] = '\0';
		if (dst[i + j] == '\n')
			break;
    i++;
	}
	j = 0;
 // printf("dst:<%s> src:<%s>\n", dst, src);
	while (src[i])
	{
		src[j++] = src[i++];
	}
  //printf("dst:<%s> src:<%s>\n", dst, src);
  return dst;
}

void	*ft_strealloc(char *str, int cycle)
{
	char	*ret;
	int	i;

	i = 0;
	ret = (char *)ft_calloc(sizeof(char), ((++cycle * BUFFER_SIZE) + 1));
  if (str && ret)
  {
    cat_n_rem(ret, str);
    free(str);
  }
	return (ret);
}

int	hasnl(char *str)
{
  int i;

  i = 0;
	while(str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void *ft_calloc(size_t num, size_t size)
{
  int i;
  void *ret;

  ret = malloc(num * size);
  if (ret == NULL)
    return (ret);
  i = 0;
  while (i < num)
  {
    ((unsigned char *)ret)[i] = '\0';
    i++;
  }
  return (ret);
}
