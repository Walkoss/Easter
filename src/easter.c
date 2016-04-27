#include "easter.h"

int easter(int argc, char **argv)
{
	t_env env;
	int x;
	int y;

	env.grille = init_grille(argv[1], &env);
	
	printf("\n-------------------------\n");
	for (y = 0; y < env.grille_y; y++)
	{
		for (x = 0; env.grille[y][x] != '\0'; x++)
		{
			my_putstr("| ");
			my_putchar(env.grille[y][x]);
			my_putstr(" |");
		}
		my_putchar(10);
	}

	printf("-------------------------\n");
	
	env.liste = init_liste(argv[2], &env);

	printf("Y liste = %d\n", env.liste_y);
	for (y = 0; y < env.liste_y; y++)
	{
		for (x = 0; env.liste[y][x] != '\0'; x++)
		{
			my_putstr("| ");
			my_putchar(env.liste[y][x]);
			my_putstr(" |");
		}
		my_putchar(10);
	}

	printf("-----------------------------\n");
	
	env.liste_rev = init_liste_rev(argv[2], &env);

	printf("Y liste_rev = %d\n", env.liste_rev_y);
	for (y = 0; y < env.liste_rev_y; y++)
	{
		for (x = 0; env.liste_rev[y][x] != '\0'; x++)
		{
			my_putstr("| ");
			my_putchar(env.liste_rev[y][x]);
			my_putstr(" |");
		}
		my_putchar(10);
	}


	solve_crossword(&env);
	return (RETURN_SUCCESS);
}

int main(int argc, char **argv)
{
  if (!check_argc(argc) && !check_grille(argc, argv) 
  						&& !check_liste(argc, argv))
      easter(argc, argv);
  return (RETURN_SUCCESS);
}