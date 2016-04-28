#include "easter.h"

int	is_a_letter(char c)
{
	return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')));
}

int count_lines(char *str)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (str[i])
	{
		if (is_a_letter(str[i]))
		{
			y = 0;
			while (is_a_letter(str[i]))
			{
				i++;
				y++;
			}
			x++;
		}
		while (str[i] && !is_a_letter(str[i]))
			i++;
	}
	return (x);
}

char  **init_grille(char *grille_path, t_env *env)
{
	char *grille_content;
	char **grille;

	if ((grille_content = malloc(sizeof(char) * 1024)) == NULL)
		return ((char **)RETURN_FAIL);
	grille_content = get_content_grille(grille_path);
	grille = my_str_to_wordtab(grille_content);
	env->grille_y = count_lines(grille_content);
	free(grille_content);
	return (grille);
}

char  **init_liste(char *liste_path, t_env *env)
{
	char *liste_content;
	char **liste;

	if ((liste_content = malloc(sizeof(char) * 1024)) == NULL)
		return ((char **)RETURN_FAIL);
	liste_content = get_content_liste(liste_path);
	liste = my_str_to_wordtab(liste_content);
	env->liste_y = count_lines(liste_content);
	free(liste_content);
	return (liste);
}

char  **init_liste_rev(char *liste_rev_path, t_env *env)
{
	char *liste_rev_content;
	char **liste_rev;

	if ((liste_rev_content = malloc(sizeof(char) * 1024)) == NULL)
		return ((char **)RETURN_FAIL);
	liste_rev_content = get_content_liste_rev(liste_rev_path);
	env->liste_rev_y = count_lines(liste_rev_content);
	liste_rev = my_revstr_to_wordtab(env->liste, env->liste_rev_y);
	free(liste_rev_content);
	return (liste_rev);
}