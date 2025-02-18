#include "moves.h"

// SWAP THE FIRST TWO NODES
static void	swap(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	stack->top = stack->top->next;
	stack->top->prev->prev = stack->top;
	stack->top->prev->next = stack->top->next;
	if (stack->top->next)
		stack->top->next->prev = stack->top->prev;
	stack->top->next = stack->top->prev;
	stack->top->prev = NULL;
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

void	is_swap(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (!ft_strncmp(move, "sa", 2))
		sa(stack_a, stack_b);
	else if (!ft_strncmp(move, "sb", 2))
		sb(stack_a, stack_b);
	else if (!ft_strncmp(move, "ss", 2))
		ss(stack_a, stack_b);
}
