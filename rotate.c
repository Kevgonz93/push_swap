#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = ft_lstlast(stack);
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack *stack)
{
	rotate(stack);
}

void	rb(t_stack *stack)
{
	rotate(stack);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
