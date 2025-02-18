#include "moves.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_b->size == 0)
		return ;
	node = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->size--;
	node->next = stack_a->top;
	stack_a->top = node;
	stack_a->size++;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (stack_a->size == 0)
		return ;
	node = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->size--;
	node->next = stack_b->top;
	stack_b->top = node;
	stack_b->size++;
}
