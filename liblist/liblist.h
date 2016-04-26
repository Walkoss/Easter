#ifndef __LIBLIST__
#define __LIBLIST__

#include "../libmy/libmy.h"

typedef struct s_list
{
  	void		*data;
	struct s_list 	*next;
}		t_list;

t_list 	*list_new(void 	*data);
t_list 	*list_last(t_list *node);
t_list 	*list_copy(t_list *node);
t_list	*list_n_node(t_list *node, int n);
t_list 	*list_search(t_list *node, void *value, int (*cmp)());
void 	*malloc_failed(char *msg);
void 	list_debug(t_list *node);
void 	list_free(t_list *node);
void	list_reverse(t_list **begin);
void	list_apply(t_list *begin, int (*f)());
void	list_apply(t_list *begin, int (*f)());
void 	list_append(t_list** node, t_list* new_node);
void 	list_remove(t_list** node_begin, t_list* rm_node);
void 	list_swap_data(t_list *first_node, t_list *scd_node);
int	list_size(t_list *begin);



#endif
