#include "easter.h"

void push_into_list_diago(t_env *env, char *liste, char *grille)
{
	t_coord coord_debut;
	t_coord coord_fin;
	t_solution *solution;

	printf("TEST liste avec %s\n", liste);
	if ((solution = malloc(sizeof(t_solution))) == 0)
		return ;
	if ((solution->mot = malloc(my_strlen(liste))) == 0)
		return ;
	printf("env diago start_x %d\n", env->diago_start_x);
	printf("env diago start_y %d\n", env->diago_start_y);
	printf("env diago end_x %d\n", env->diago_end_x);
	printf("env diago end_y %d\n", env->diago_end_y);
	if (env->diago_start_y <= env->diago_end_y)
	{
		coord_debut.x = my_strpos(grille, liste) + env->diago_start_y;
		coord_debut.y = env->diago_start_x + my_strpos(grille, liste);
		coord_fin.x = my_strpos(grille, liste) + my_strlen(liste) - 1 + env->diago_start_y;
		coord_fin.y = env->diago_end_x - my_strpos(my_revstr(my_strdup2(grille)), my_revstr(my_strdup2(liste)));
	}
	else
	{
		coord_debut.x = env->diago_start_y - my_strpos(grille, liste);
		coord_debut.y = env->diago_start_x + my_strpos(grille, liste);
		coord_fin.x = my_strpos(my_revstr(my_strdup2(grille)), my_revstr(my_strdup2(liste)));
		coord_fin.y = env->diago_end_x - my_strpos(my_revstr(my_strdup2(grille)), my_revstr(my_strdup2(liste)));
	}
	solution->coord_debut = coord_debut;
	solution->coord_fin = coord_fin;
	my_strcpy2(solution->color_fg, FG_YELLOW);
	my_strcpy2(solution->mot, liste);
	list_append(&env->solutions, list_new(solution));
}


void push_into_listrev_diago(t_env *env, char *liste, char *grille)
{
	t_coord coord_debut;
	t_coord coord_fin;
	t_solution *solution;

	printf("TEST listrev avec %s\n", my_revstr(my_strdup2(liste)));
	(void)grille;
	if ((solution = malloc(sizeof(t_solution))) == 0)
		return ;
	if ((solution->mot = malloc(my_strlen(liste))) == 0)
		return ;
	printf("env diago start_x %d\n", env->diago_start_x);
	printf("env diago start_y %d\n", env->diago_start_y);
	printf("env diago end_x %d\n", env->diago_end_x);
	printf("env diago end_y %d\n", env->diago_end_y);
	if (env->diago_start_y <= env->diago_end_y)
	{
		coord_fin.x = my_strpos(grille, liste) + env->diago_start_y;
		coord_fin.y = env->diago_start_x + my_strpos(grille, liste);
		coord_debut.x = my_strpos(grille, liste) + my_strlen(liste) - 1 + env->diago_start_y;
		coord_debut.y = env->diago_end_x - my_strpos(my_revstr(my_strdup2(grille)), my_revstr(my_strdup2(liste)));
	}
	else
	{
		coord_fin.x = env->diago_start_y - my_strpos(grille, liste);
		coord_fin.y = env->diago_start_x + my_strpos(grille, liste);
		coord_debut.x = my_strpos(my_revstr(my_strdup2(grille)), my_revstr(my_strdup2(liste)));
		coord_debut.y = env->diago_end_x - my_strpos(my_revstr(my_strdup2(grille)), my_revstr(my_strdup2(liste)));
	}
	solution->coord_debut = coord_debut;
	solution->coord_fin = coord_fin;
	my_strcpy2(solution->color_fg, FG_YELLOW);
	my_strcpy2(solution->mot, my_revstr(my_strdup2(liste)));
	list_append(&env->solutions, list_new(solution));
}


void solve_diago_affichage(t_env *env, char* diago)
{
	int i;

	for (i = 0; i < env->liste_y; i++)
	{
		if (my_strcmp(my_strstr(diago, env->liste[i]), "null"))
			push_into_list_diago(env, env->liste[i], diago);
		else if (my_strcmp(my_strstr(diago, env->liste_rev[i]), "null"))
			push_into_listrev_diago(env, env->liste_rev[i], diago);
	}
}

void solve_diago_concatenation_inverse(t_env *env)
{
	int i;
	char *diago;
	int start_x;
	int start_y;

	i = 0;
	start_x = env->diago_start_x;
	start_y = env->diago_start_y;
	if ((diago = malloc(sizeof(char) * 1024)) == 0)
		return;

	if (start_x == env->diago_end_x && start_y == env->diago_end_y)
	{
		diago[0] = env->grille[start_x][start_y];
		diago[1] = '\0';
	}
	else
		while (start_x != env->diago_end_x + 1 && start_y != env->diago_end_y - 1)
		{
			diago[i] = env->grille[start_x][start_y];
			start_x++;
			start_y--;	
			i++;
		}
	solve_diago_affichage(env, diago);
}

void solve_diago_inverse(t_env *env)
{
	int i;
	int y;
	int x;
	int c;

	for (i = env->grille_y - 1, y = my_strlen(env->grille[0]) - 1, x = env->grille_y - 1, c = my_strlen(env->grille[0]) - 1; c > 0; i--, y--)
	{
		if (i < 0)
		{
			i++;
			c--;		
		}
		env->diago_start_x = i;
		env->diago_start_y = c;
		if (y >= my_strlen(env->grille[0] - 1))
			env->diago_end_y = y;
		else
		{
			x--;
			env->diago_end_y = 0;
		}
		env->diago_end_x = x;
		solve_diago_concatenation_inverse(env);
	}
}

void solve_diago_concatenation(t_env *env)
{
	int i;
	char *diago;
	int start_x;
	int start_y;

	i = 0;
	start_x = env->diago_start_x;
	start_y = env->diago_start_y;
	if ((diago = malloc(sizeof(char) * 1024)) == 0)
		return;

	if (start_x == env->diago_end_x && start_y == env->diago_end_y)
		diago[0] = env->grille[start_x][start_y];
	else
		while (start_x != env->diago_end_x + 1 && start_y != env->diago_end_y + 1)
		{
			diago[i] = env->grille[start_x][start_y];		
			start_x++;
			start_y++;	
			i++;
		}
	solve_diago_affichage(env, diago);
}

void solve_diago(t_env *env)
{
	int i;
	int y;
	int x;
	int c;

	for (i = env->grille_y - 1, y = 0, x = env->grille_y - 1, c = 0; c < my_strlen(env->grille[0]) - 1; i--, y++)
	{
		if (i < 0)
		{
			c++;
			i++;
		}
		env->diago_start_x = i;
		env->diago_start_y = c;
		if (y < my_strlen(env->grille[i]))
			env->diago_end_y = y;
		else
		{	
			x--;
			env->diago_end_y = my_strlen(env->grille[i]) - 1;
		}
		env->diago_end_x = x;
		solve_diago_concatenation(env);
	}
}