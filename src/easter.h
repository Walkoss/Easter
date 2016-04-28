#ifndef __EASTER_H__
# define __EASTER_H__

/*** Standard Libraries ***/
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include <fcntl.h>
#include "string.h"

/*** Libraries ***/
#include "../libmy/libmy.h"
#include "../liblist/liblist.h"

/*** Define ***/
#define RETURN_SUCCESS 0
#define RETURN_FAIL 1

#define RESET   "\x1B[0m"

#define FG_BLACK   "\x1B[0;30m"
#define FG_RED     "\x1B[0;31m"
#define FG_GREEN   "\x1B[0;32m"
#define FG_YELLOW  "\x1B[0;33m"
#define FG_BLUE    "\x1B[0;34m"
#define FG_PURPLE  "\x1B[0;35m"
#define FG_CYAN    "\x1B[0;36m"
#define FG_WHITE   "\x1B[0;37m"

#define BG_BLACK   "\x1B[0;40m"
#define BG_RED     "\x1B[0;41m"
#define BG_GREEN   "\x1B[0;42m"
#define BG_YELLOW  "\x1B[0;44m"
#define BG_BLUE    "\x1B[0;44m"
#define BG_PURPLE  "\x1B[0;45m"
#define BG_CYAN    "\x1B[0;46m"
#define BG_WHITE   "\x1B[0;47m"

/*** Structures ***/
typedef struct s_coord
{
	int 		x;
	int 		y;
}				t_coord;

typedef struct s_solution
{
	t_coord 	coord_debut;
	t_coord 	coord_fin;
	char 		*mot;
	char 		color_fg[8];
}				t_solution;

typedef struct s_env
{
	char 		**grille;
	int 		grille_y;
	char 		**liste;
	int 		liste_y;
	char 		**liste_rev;
	int 		liste_rev_y;
	t_list 		*solutions;
	int 		diago_start_x;
	int 		diago_start_y;
	int 		diago_end_x;
	int 		diago_end_y;
}				t_env;

/*** Prototypes ***/
int check_argc(int argc);
int check_grille(char **argv);

int check_liste(char **argv);

char **init_grille(char *grille_path, t_env *env);
char **init_liste(char *liste_path, t_env *env);
char **init_liste_rev(char *liste_path, t_env *env);
int count_lines(char *grille_content);
char *get_content_grille(char *grille_path);
char *get_content_liste(char *liste_path);
char *get_content_liste_rev(char *liste_rev_path);

void solve_diago(t_env *env);
void solve_diago_inverse(t_env *env);
void solve_crossword(t_env *env);

#endif
