#ifndef G_COLLECTOR_H
# define G_COLLECTOR_H
# include <stdlib.h>

typedef struct s_col
{
	void			*ptr;
	struct s_col	*next;
}t_col;

typedef enum e_call
{
	FREE,
	MALLOC
}t_call;


t_col	*new_node(void	*ptr);
t_col	*last_node(t_col **head);
void	add_back(t_col	**head, t_col *new);
void	clear_all(t_col **head);
void	*g_malloc(size_t size, t_call call);

#endif