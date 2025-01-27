#include "sort.h"

void	update_index(t_stack *stack)
{
	t_node	*node;
	int		i;
	int		mid;

	i = 0;
	mid = ft_lstsize(stack) / 2;
	node = stack->top;
	while (node)
	{
		node->index = i;
		if (i <= mid)
			node->second_half = false;
		else
			node->second_half = true;
		node = node->next;
		i++;
	}
}

void	update_size(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = stack_a->top;
	node_b = stack_b->top;
	stack_a->size = 0;
	stack_b->size = 0;
	while (node_a)
	{
		stack_a->size++;
		node_a = node_a->next;
	}
	while (node_b)
	{
		stack_b->size++;
		node_b = node_b->next;
	}
}
