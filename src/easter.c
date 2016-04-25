#include "easter.h"

int main(int argc, char **argv)
{
  if (!check_argc(argc))
    if (check_fopen(argv))
      easter();
    else
      my_putstr("Erreur lors de l'ouverture d'un fichier\n");
  else
    my_putstr("Nombre d'arguments incorrects\n");
}

int easter()
{
  return (1);
}
