#include "g_collector.h"

t_col	*new_node(void	*ptr)
{
	t_col	*new;

	new = malloc(sizeof(t_col));
	if (!new)
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

t_col	*last_node(t_col **head)
{
	t_col	*tmp;

	if (!head || !*head)
		return (NULL);
	tmp = *head;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	add_back(t_col	**head, t_col *new)
{
	if (!head || !new)
		return ;
	if (!*head)
		*head = new;
	else
		last_node(head)->next = new;
}

void	clear_all(t_col **head)
{
	t_col	*cur;
	t_col	*tmp;

	if (!head || !*head)
		return ;
	cur = *head;
	while (cur)
	{
		tmp = cur->next;
		free(cur->ptr);
		cur->ptr = NULL;
		free(cur);
		cur = tmp;
	}
	*head = NULL;
}

void	*g_malloc(size_t size, t_call call)
{
	static t_col	*head;
	t_col			*tmp;
	void			*ptr;

	if (call == MALLOC)
	{
		ptr = malloc(size);
		if (!ptr)
			return (clear_all(&head), NULL);
		tmp = new_node(ptr);
		if (!tmp)
			return (clear_all(&head), free(ptr), NULL);
		add_back(&head, tmp);
		return (ptr);
	}
	else if (call == FREE)
		clear_all(&head);
	return (NULL);
}
