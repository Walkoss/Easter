#include "libmy.h"

char **my_revstr_to_wordtab(char **liste, int y)
{
	char **listerev;
	int i;

	if ((listerev = malloc(sizeof(char *) * y * 1024)) == NULL)
		return ((char **)NULL);
	for (i = 0; i < y; i++)
		listerev[i] = my_revstr(my_strdup(liste[i]));
	return (listerev);
}