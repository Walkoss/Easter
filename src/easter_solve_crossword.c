#include "easter.h"

void solve_lines(t_env *env)
{
	int i;
	int y;
	int x;

	for (i = 0; i < env->grille_y; i++)
	{
		for (y = 0; y < env->liste_y; y++)
		{
			if (my_strcmp(my_strstr(env->grille[i], env->liste[y]), "null"))
				printf("Mot [%s] trouvé a la ligne [%d] dans la grille\n", env->liste[y], i);
			else if (my_strcmp(my_strstr(env->grille[i], env->liste_rev[y]), "null"))
				printf("Mot [%s] trouvé a la ligne [%d] dans la grille\n", my_revstr(env->liste_rev[y]), i);
		}
	}
}

char **grille_rotated(t_env *env)
{







}

void solve_column(t_env *env)
{
	int i;
	int y;
	int x;
	char **grille_rotated;

	grille_rotated = grille_rotated(env);
	for (i = 0; i < env->grille_y; i++)
	{
		for (y = 0; y < env->liste_y; y++)
		{
			//printf("Strstr entre [%s] et [%s]\n", env->liste[y], env->grille[y]);
			if (my_strcmp(my_strstr(env->grille[i], env->liste[y]), "null"))
				printf("Mot [%s] trouvé a la ligne [%d] dans la grille\n", env->liste[y], i);
			else if (my_strcmp(my_strstr(env->grille[i], env->liste_rev[y]), "null"))
				printf("Mot [%s] trouvé a la ligne [%d] dans la grille\n", my_revstr(env->liste_rev[y]), i);
		}
	}
}

void solve_crossword(t_env *env)
{
	solve_lines(env);
}