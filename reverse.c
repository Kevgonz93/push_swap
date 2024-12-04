#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = ft_lstlast(stack);
	while (first->next != last)
		first = first->next;
	first->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
