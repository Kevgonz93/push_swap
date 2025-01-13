#include "push_swap.h"

static int	mid_low_high(t_stack *stack_a, t_stack *stack_b)
{
	printf("sa\n");
	swap(stack_a);
	printer(stack_a, stack_b);
	return (1);
}

static int	mid_high_low(t_stack *stack_a, t_stack *stack_b)
{
	printf("rra\n");
	reverse(stack_a);
	printer(stack_a, stack_b);
	return (1);
}

static int	high_low_mid(t_stack *stack_a, t_stack *stack_b)
{
	printf("ra\n");
	rotate(stack_a);
	printer(stack_a, stack_b);
	return (1);
}

int	short_sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top;
	t_node	*bottom;

	top = stack_a->top;
	bottom = ft_lstlast(stack_a);
	if (top->value > top->next->value && top->next->value < bottom->value
		&& top->value > bottom->value)
		return (high_low_mid(stack_a, stack_b));
	else if (top->value > bottom->value && top->value > top->next->value
		&& top->next->value > bottom->value)
		return (high_low_mid(stack_a, stack_b)
			+ mid_low_high(stack_a, stack_b));
	else if (top->value < top->next->value && top->value > bottom->value
		&& top->next->value > bottom->value)
		return (mid_high_low(stack_a, stack_b));
	else if (top->value < top->next->value && top->value < bottom->value
		&& top->next->value > bottom->value)
		return (mid_low_high(stack_a, stack_b)
			+ high_low_mid(stack_a, stack_b));
	else
		return (mid_low_high(stack_a, stack_b));
}
