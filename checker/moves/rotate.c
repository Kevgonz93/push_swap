#include "moves.h"

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack->top;
	while (node->next)
		node = node->next;
	node->next = stack->top;
	stack->top = stack->top->next;
	node->next->next = NULL;
}

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	rotate(stack_a);
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
