#include "easter.h"

int easter(int argc, char **argv)
{
	/*t_env env;

	env.grille = init_grille(argv[1]);
	env.liste = init_liste(argv[2]);
	solve_crossword(&env);*/
	return (RETURN_SUCCESS);
}

int main(int argc, char **argv)
{
  if (!check_argc(argc) && !check_grille(argc, argv) 
  						&& !check_liste(argc, argv))
      easter(argc, argv);
  return (RETURN_SUCCESS);
}