#include "get_next_line.h"

void cat_n_rem(char *dst, char *src, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(dst[j])
		j++;
	while(src[i])
	{
		dst[i + j] = src[i];
		src[i] = '\0';
    i++;
		if (flag && dst[i + j - 1] == '\n')
			break;
	}
  if (src[i])
    cat_n_rem(src, src + i, 0);
	/*j = 0;
	
	 while (i < BUFFER_SIZE)
	{
    if (src[i] != '\n' && src[i] != '\0')
    {
      src[j] = src[i];
      j++;
    }
    src[i] = 0;
    i++;
	}*/
               //printf("dst:<%s> src:<%s>\n", dst, src);
}

void	*ft_strealloc(char *str, int cycle)
{
	char	*ret;

  if (cycle == 1)
    return (str);
  ret = (char *)ft_calloc(sizeof(char), ((cycle * BUFFER_SIZE) + 1));
  if (str && ret)
  {
    cat_n_rem(ret, str, 0);
    free(str);
  }
	return (ret);
}

char	*hasnl(char *str)
{
  int i;

  i = 0;
	while(str && str[i])
	{
		if (str[i] == '\n')
			return (str + i + 1);
		i++;
	}
	return (0);
}

void *ft_calloc(size_t num, size_t size)
{
  size_t i;
  void *ret;

  ret = malloc(num * size);
  if (ret == NULL)
    return (ret);
  i = 0;
  while (i < num * size)
  {
    ((unsigned char *)ret)[i] = '\0';
    i++;
  }
  return (ret);
}
