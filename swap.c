#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = stack->top->next;
	stack->top->next = first;
}

void	sa(t_stack *stack)
{
	swap(stack);
}

void	sb(t_stack *stack)
{
	swap(stack);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
