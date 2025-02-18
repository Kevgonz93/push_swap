#include "moves.h"

static void	push(t_stack *stack_dst, t_stack *stack_src)
{
	t_node	*temp;

	if (!stack_src->top)
		return ;
	temp = stack_src->top;
	stack_src->top = stack_src->top->next;
	if (stack_src->top)
		stack_src->top->prev = NULL;
	temp->prev = NULL;
	if (!stack_dst->top)
	{
		stack_dst->top = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = stack_dst->top;
		temp->next->prev = temp;
		stack_dst->top = temp;
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
}

void	is_push(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (!ft_strncmp(move, "pa", 2))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(move, "pb", 2))
		pb(stack_a, stack_b);
}
