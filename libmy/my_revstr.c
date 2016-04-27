#include "libmy.h"

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  char	c;
  
  i = 0;
  for (i = 0, j = my_strlen(str) - 1; i < j; i++, j--)
    {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
    }
  return (str);
}
