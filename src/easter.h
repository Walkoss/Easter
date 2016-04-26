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
	t_list 		*liste;
}				t_env;

/*** Prototypes ***/
int check_argc(int argc);
int check_grille(int argc, char **argv);
int check_liste(int argc, char **argv);

#endif
