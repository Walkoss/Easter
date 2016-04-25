#ifndef __LIBMY__
#define __LIBMY__

#include <stdio.h>
#include <stdlib.h>

int		my_getnbr(char *str);
int		my_isneg(int n);
void	my_put_nbr(int nb);
void	my_putchar(char c);
void	my_putstr(char *str);
char	**my_str_to_wordtab(char *str);
char	*my_strcat(char *str1, char *str2);
int		my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
void	*my_strdup(char *str);
int		my_strlen(char *str);
char	*my_strncat(char *str1, char *str2, int n);
int		my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(char *str, char *to_find);
void	my_swap(int *a, int *b);
int		isint(char *str);
int 	my_abs(int num);
int 	my_strchr(char c, char *str);
void 	*malloc_failed(char *msg);

#endif