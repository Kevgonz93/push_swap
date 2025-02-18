#include "moves.h"

static void	swap(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack->top;
	stack->top = stack->top->next;
	node->next = stack->top->next;
	stack->top->next = node;
}

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	swap(stack_a);
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;
	swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
