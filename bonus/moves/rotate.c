#include "moves.h"

// FIRST NODE GOES TO THE END
void	rotate(t_stack *stack)
{
	t_node	*node;

	if (!stack->top || !stack->top->next)
		return ;
	node = ft_lstlast(stack);
	node->next = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	node->next->prev = node;
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
