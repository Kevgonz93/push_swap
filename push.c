#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (!stack_b->top)
		return ;
	node = stack_b->top;
	stack_b->top = node->next;
	node->next = stack_a->top;
	stack_a->top = node;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (!stack_a->top)
		return ;
	node = stack_a->top;
	stack_a->top = node->next;
	node->next = stack_b->top;
	stack_b->top = node;
}
