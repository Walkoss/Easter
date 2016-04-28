#include "libmy.h"

int my_strpos(char *haystack, char *needle)
{
   char *p = my_strstr(haystack, needle);
   if (p)
      return p - haystack;
   return 0;
}