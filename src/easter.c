#include "easter.h"

int easter(char **argv)
{
	t_env env;

	env.grille = init_grille(argv[1], &env);	
	env.liste = init_liste(argv[2], &env);
	env.liste_rev = init_liste_rev(argv[2], &env);

	solve_crossword(&env);
	return (RETURN_SUCCESS);
}

int main(int argc, char **argv)
{
  if (!check_argc(argc) && !check_grille(argv) 
  						&& !check_liste(argv))
      easter(argv);
  return (RETURN_SUCCESS);
}