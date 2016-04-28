#include "easter.h"

void print_solution(t_solution *solution)
{
	printf("Mot '%s%s%s' trouvé ", solution->color_fg, solution->mot, RESET);
	printf("[%d,%d] ", solution->coord_debut.y, solution->coord_debut.x);
	printf("[%d,%d]\n", solution->coord_fin.y, solution->coord_fin.x);
}

void push_into_listrev_lines(char *grille, char *liste, int y, t_env *env)
{
	t_coord coord_debut;
	t_coord coord_fin;
	t_solution *solution;

	if ((solution = malloc(sizeof(t_solution))) == 0)
		return ;
	if ((solution->mot = malloc(my_strlen(liste))) == 0)
		return ;
	coord_debut.y = y;
	coord_debut.x = my_strpos(grille, liste) + my_strlen(liste) - 1;
	coord_fin.x = my_strpos(grille, liste);
	coord_fin.y = y;
	solution->coord_debut = coord_debut;
	solution->coord_fin = coord_fin;
	my_strcpy2(solution->color_fg, FG_YELLOW);
	my_strcpy2(solution->mot, my_revstr(my_strdup2(liste)));	
	list_append(&env->solutions, list_new(solution));
}

void push_into_list_lines(char *grille, char *liste, int y, t_env *env)
{
	t_coord coord_debut;
	t_coord coord_fin;
	t_solution *solution;

	if ((solution = malloc(sizeof(t_solution))) == 0)
		return ;
	if ((solution->mot = malloc(my_strlen(liste))) == 0)
		return ;
	coord_debut.y = y;
	coord_debut.x = my_strpos(grille, liste);
	coord_fin.x = my_strpos(grille, liste) + my_strlen(liste) - 1;
	coord_fin.y = y;
	solution->coord_debut = coord_debut;
	solution->coord_fin = coord_fin;
	my_strcpy2(solution->color_fg, FG_YELLOW);
	my_strcpy2(solution->mot, liste);
	list_append(&env->solutions, list_new(solution));
}

void solve_lines(t_env *env)
{
	int i;
	int y;

	for (i = 0; i < env->grille_y; i++)
	{
		for (y = 0; y < env->liste_y; y++)
		{
			if (my_strcmp(my_strstr(env->grille[i], env->liste[y]), "null"))
			{
				push_into_list_lines(env->grille[i], env->liste[y], i, env);
			}
			else if (my_strcmp(my_strstr(env->grille[i], env->liste_rev[y]), "null"))
			{
				push_into_listrev_lines(env->grille[i], env->liste_rev[y], i, env);
//				printf("Le mot %s de coordonnées (%d;%d)\n", my_strdup2(env->liste_rev[y]), 5, i);
			}
		}
	}
}

void push_into_listrev_col(char *grille, char *liste, int y, t_env *env)
{
	t_coord coord_debut;
	t_coord coord_fin;
	t_solution *solution;

	if ((solution = malloc(sizeof(t_solution))) == 0)
		return ;
	if ((solution->mot = malloc(my_strlen(liste))) == 0)
		return ;
	coord_debut.x = y;
	coord_debut.y = my_strpos(grille, liste) + my_strlen(liste) - 1;
	coord_fin.y = my_strpos(grille, liste);
	coord_fin.x = y;
	solution->coord_debut = coord_debut;
	solution->coord_fin = coord_fin;
	my_strcpy2(solution->color_fg, FG_YELLOW);
	my_strcpy2(solution->mot, my_revstr(my_strdup2(liste)));	
	list_append(&env->solutions, list_new(solution));
}

void push_into_list_col(char *grille, char *liste, int y, t_env *env)
{
	t_coord coord_debut;
	t_coord coord_fin;
	t_solution *solution;

	if ((solution = malloc(sizeof(t_solution))) == 0)
		return ;
	if ((solution->mot = malloc(my_strlen(liste))) == 0)
		return ;
	coord_debut.x = y;
	coord_debut.y = my_strpos(grille, liste);
	coord_fin.y = my_strpos(grille, liste) + my_strlen(liste) - 1;
	coord_fin.x = y;
	solution->coord_debut = coord_debut;
	solution->coord_fin = coord_fin;
	my_strcpy2(solution->color_fg, FG_YELLOW);
	my_strcpy2(solution->mot, liste);
	list_append(&env->solutions, list_new(solution));
}

void solve_column(t_env *env)
{
	int i;
	int y;
	int x;
	char *column;

	if ((column = malloc(sizeof(char) * 1024)) == 0)
		return;
	for (i = 0; i < my_strlen(env->grille[i]); i++)
	{
		for (x = 0; x < env->grille_y; x++)
			column[x] = env->grille[x][i];
		for (y = 0; y < env->liste_y; y++)
		{
			if (my_strcmp(my_strstr(column, env->liste[y]), "null"))
			{
				push_into_list_col(column, env->liste[y], i, env);
			}
			else if (my_strcmp(my_strstr(column, env->liste_rev[y]), "null"))
			{
				push_into_listrev_col(column, env->liste_rev[y], i, env);
			}
		}
	}
	free(column);
}

void display_crossword_solved(t_env *env)
{
	int i;
	int y;
	int x;

	for (i = 0; i < my_strlen(env->grille[0]) * 4 + 1; i++)
		my_putchar('-');
	my_putchar(10);
	for (y = 0; y < env->grille_y; y++)
	{
		for (x = 0; env->grille[y][x] != '\0'; x++)
		{
			my_putstr("| ");
			my_putchar(env->grille[y][x]);
			my_putstr(" ");
		}
		my_putstr("|");
		my_putchar(10);
	}
	for (i = 0; i < my_strlen(env->grille[0]) * 4 + 1; i++)
		my_putchar('-');
	my_putchar(10);
}

void display_solutions(t_env *env)
{
	t_list *copy;

	copy = list_copy(env->solutions);
	copy = copy->next;
	for (; copy; copy = copy->next)
	{
		if (copy)
		{
			print_solution((t_solution*)copy->data);
		}
	}
}

int in_array(char *str, char **array, int array_size) {
	int i;
	for (i = 0; i < array_size; i++)
		if (my_strcmp(str, array[i]) == 0)
			return 1;
	return 0;
}

void display_unsolvable2(t_env *env, char **liste_solved, int array_size)
{
	int i;

	for (i = 0; i < env->liste_y; i++)
	{
		if (!in_array(env->liste[i], liste_solved, array_size))
			printf("Ce mot n'est pas trouve %s\n", env->liste[i]);
	}

}

void display_unsolvable(t_env *env)
{
	t_list *copy;
	t_solution *solution;
	char 	**liste_solved;
	int y;
	int i;

	i = 0;
	if ((liste_solved = malloc(sizeof(char *) * 1024)) == NULL)
		return ;
	for (y = 0; y < env->liste_y; y++)
	{
		copy = list_copy(env->solutions)->next;
		if ((liste_solved[y] = malloc(sizeof(char) * 1024)) == NULL)
			return ;
		for (; copy; copy = copy->next)
		{
			solution = (t_solution *)copy->data;
			if (!my_strcmp(solution->mot, env->liste[y]))
			{
				liste_solved[i] = solution->mot;
				i++;
			}
		}
	}
	display_unsolvable2(env, liste_solved, i);
}

void solve_crossword(t_env *env)
{

	t_solution *solution;

	solution = NULL;
	env->solutions = list_new(solution);
	solve_lines(env);
	solve_column(env);
	solve_diago(env);
	solve_diago_inverse(env);
	display_crossword_solved(env);
	display_solutions(env);
	display_unsolvable(env);
	list_free(env->solutions);
}