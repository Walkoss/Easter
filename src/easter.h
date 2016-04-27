#ifndef __EASTER_H__
# define __EASTER_H__

/*** Standard Libraries ***/
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include <fcntl.h>

/*** Libraries ***/
#include "../libmy/libmy.h"
#include "../liblist/liblist.h"

/*** Define ***/
#define RETURN_SUCCESS 0
#define RETURN_FAIL 1

/*** Structures ***/
typedef struct s_liste
{
	char 		*word;
	char 		*rev_word;
}				t_liste;

typedef struct s_env
{
	char 		**grille;
	int 		grille_y;
	char 		**liste;
	int 		liste_y;
	char 		**liste_rev;
	int 		liste_rev_y;
}				t_env;

/*** Prototypes ***/
int check_argc(int argc);
int check_grille(int argc, char **argv);
int check_liste(int argc, char **argv);

char **init_grille(char *grille_path, t_env *env);
char **init_liste(char *liste_path, t_env *env);
char **init_liste_rev(char *liste_path, t_env *env);
int count_lines(char *grille_content);

void solve_crossword(t_env *env);
#endif
