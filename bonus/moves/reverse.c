#include "moves.h"

// LAST NODE GOES TO THE BEGINNING
static void	reverse(t_stack *stack)
{
	t_node	*node;

	if (!stack->top || !stack->top->next)
		return ;
	node = ft_lstlast(stack);
	node->prev->next = NULL;
	node->next = stack->top;
	node->prev = NULL;
	stack->top = node;
	node->next->prev = node;
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
