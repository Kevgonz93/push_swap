#include "moves.h"

static void	reverse(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack->top;
	while (node->next->next)
		node = node->next;
	node->next->next = stack->top;
	stack->top = node->next;
	node->next = NULL;
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	reverse(stack_a);
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	reverse(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}
