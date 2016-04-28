#include "libmy.h"

char	*my_strcpy2(char *dest, char *src)
{
  int i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup2(char *str)
{
  char *tab;

  if ((tab = malloc(my_strlen(str) * sizeof(char))) == 0)
    return ((char *)0);
  my_strcpy2(tab, str);
  return (tab);
}
