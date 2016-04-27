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


char *get_content_grille(char *grille_path)
{
	char	*content;
	int	handle;

	if ((content = malloc(sizeof(char) * 1024)) == 0)
		return ((char *)RETURN_FAIL);
	handle = open(grille_path, O_RDONLY);
	if (handle < 0)
	{
		my_putstr("\nProblème d'ouverture du fichier grille\n");
		return ((char *)RETURN_FAIL);
	}
	if (read(handle, content, 1024) < 0)
	{
		my_putstr("\nProblème de lecture du fichier grille\n");
		return ((char *)RETURN_FAIL);
	}
	close(handle);
	return (content);
}

char  **init_grille(char *grille_path, t_env *env)
{
	char *grille_content;
	char **grille;
	int y,x;

	if ((grille_content = malloc(sizeof(char) * 1024)) == NULL)
		return ((char **)RETURN_FAIL);
	grille_content = get_content_grille(grille_path);
	grille = my_str_to_wordtab(grille_content);
	env->grille_y = count_lines(grille_content);
	free(grille_content);
	return (grille);
}

char *get_content_liste(char *liste_path)
{
	char	*content;
	int	handle;

	if ((content = malloc(sizeof(char) * 1024)) == 0)
		return ((char *)RETURN_FAIL);
	handle = open(liste_path, O_RDONLY);
	if (handle < 0)
	{
		my_putstr("\nProblème d'ouverture du fichier liste\n");
		return ((char *)RETURN_FAIL);
	}
	if (read(handle, content, 1024) < 0)
	{
		my_putstr("\nProblème de lecture du fichier liste\n");
		return ((char *)RETURN_FAIL);
	}
	close(handle);
	return (content);
}

char  **init_liste(char *liste_path, t_env *env)
{
	char *liste_content;
	char **liste;
	int y,x;

	if ((liste_content = malloc(sizeof(char) * 1024)) == NULL)
		return ((char **)RETURN_FAIL);
	liste_content = get_content_liste(liste_path);
	liste = my_str_to_wordtab(liste_content);
	env->liste_y = count_lines(liste_content);
	free(liste_content);
	return (liste);
}


char *get_content_liste_rev(char *liste_rev_path)
{
	char	*content;
	int	handle;

	if ((content = malloc(sizeof(char) * 1024)) == 0)
		return ((char *)RETURN_FAIL);
	handle = open(liste_rev_path, O_RDONLY);
	if (handle < 0)
	{
		my_putstr("\nProblème d'ouverture du fichier liste_rev\n");
		return ((char *)RETURN_FAIL);
	}
	if (read(handle, content, 1024) < 0)
	{
		my_putstr("\nProblème de lecture du fichier liste_rev\n");
		return ((char *)RETURN_FAIL);
	}
	close(handle);
	return (content);
}

char  **init_liste_rev(char *liste_rev_path, t_env *env)
{
	char *liste_rev_content;
	char **liste_rev;
	int y,x;

	if ((liste_rev_content = malloc(sizeof(char) * 1024)) == NULL)
		return ((char **)RETURN_FAIL);
	liste_rev_content = get_content_liste_rev(liste_rev_path);
	env->liste_rev_y = count_lines(liste_rev_content);
	liste_rev = my_revstr_to_wordtab(env->liste, env->liste_rev_y);
	free(liste_rev_content);
	return (liste_rev);
}