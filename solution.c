#include "push_swap.h"

static void	split_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	half;
	int	i;

	size = ft_lstsize(stack_a);
	half = size / 2;
	i = 0;
	while (i < half)
	{
		pb(stack_a, stack_b);
		i++;
	}
}

static void	merge_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;

	size = ft_lstsize(stack_b);
	i = 0;
	while (i < size)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

static void	sort_stack(t_stack *stack)
{
	int	size;
	int	i;

	size = ft_lstsize(stack);
	i = 0;
	while (i < size)
	{
		ra(stack);
		i++;
	}
}

void	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	split_stack(stack_a, stack_b);
	sort_stack(stack_a);
	sort_stack(stack_b);
	merge_stack(stack_a, stack_b);
}
