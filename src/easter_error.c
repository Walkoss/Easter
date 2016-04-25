#include "easter.h"

int check_argc(int argc)
{
  if (argc == 3)
    return (0);
  else
    return (1);
}

int check_fopen(char **argv)
{

  if (fopen(argv[1],"r") == 0 && fopen(argv[2],"r") == 0 )
    return (0);
  else
    return (1);
}
