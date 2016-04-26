#include "easter.h"

int check_argc(int argc)
{
	if (argc == 3)
		return (RETURN_SUCCESS);
	my_putstr("Nombre d'argument incorrect\n");
	// TO DO : usage...
	return (RETURN_FAIL);
}

int check_grille(int argc, char **argv)
{
	char	*content;
	int	handle;

	if (!my_strcmp(argv[1], argv[2]))
	{
		my_putstr("Les fichiers grille et liste doivent être différents\n");
		return (RETURN_FAIL);
	}
	if ((content = malloc(sizeof(char) * 1024)) == 0)
		return (RETURN_FAIL);
	handle = open(argv[1], O_RDONLY);
	if (handle < 0)
	{
		my_putstr("\nProblème d'ouverture du fichier grille\n");
		return (RETURN_FAIL);
	}
	if (read(handle, content, 1024) < 0)
	{
		my_putstr("\nProblème de lecture du fichier grille\n");
		return (RETURN_FAIL);
	}
	close(handle);
	free(content);
	return (RETURN_SUCCESS);
}

int check_liste(int argc, char **argv)
{
	char	*content;
	int	handle;

	if (!my_strcmp(argv[1], argv[2]))
	{
		my_putstr("Les fichiers grille et liste doivent être différents\n");
		return (RETURN_FAIL);
	}
	if ((content = malloc(sizeof(char) * 1024)) == 0)
		return (RETURN_FAIL);
	handle = open(argv[2], O_RDONLY);
	if (handle < 0)
	{
		my_putstr("\nProblème d'ouverture du fichier liste\n");
		return (RETURN_FAIL);
	}
	if (read(handle, content, 1024) < 0)
	{
		my_putstr("\nProblème de lecture du fichier liste\n");
		return (RETURN_FAIL);
	}
	close(handle);
	free(content);
	return (RETURN_SUCCESS);
}