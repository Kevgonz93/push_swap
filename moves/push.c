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

// MOVE THE FIRST NODE OF STACK_A TO STACK_B
void	pb(t_stack *stack_a, t_stack *stack_b, bool print)
{
	push(stack_b, stack_a);
	if (print)
	{
		printf("pb\n");
<<<<<<< HEAD
=======
		update_stack(stack_a, stack_b);
>>>>>>> refs/remotes/origin/main
	}
}

// MOVE THE FIRST NODE OF STACK_B TO STACK_A
void	pa(t_stack *stack_a, t_stack *stack_b, bool print)
{
	push(stack_a, stack_b);
	if (print)
	{
		printf("pa\n");
		update_stack(stack_a, stack_b);
	}
}
