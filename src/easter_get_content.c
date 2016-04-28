#include "easter.h"

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