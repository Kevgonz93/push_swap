#include "push_swap.h"

int	is_repeat(char *numbers[])
{
	int	i;
	int	j;

	i = 1;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (!ft_strncmp(numbers[i], numbers[j], ft_strlen(numbers[i])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	del(int content)
{
	if (content)
		(void)content;
	return ;
}

int	check(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_a->top;
	if (!node)
		return (0);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	if (stack_b->top)
		return (0);
	return (1);
}

void	move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	if (!ft_strncmp(move, "sa", 3))
		sa(stack_a);
	else if (!ft_strncmp(move, "sb", 3))
		sb(stack_b);
	else if (!ft_strncmp(move, "ss", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(move, "ra", 3))
		ra(stack_a);
	else if (!ft_strncmp(move, "rb", 3))
		rb(stack_b);
	else if (!ft_strncmp(move, "rr", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra", 4))
		rra(stack_a);
	else if (!ft_strncmp(move, "rrb", 4))
		rrb(stack_b);
	else if (!ft_strncmp(move, "rrr", 4))
		rrr(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa", 3))
		pa(stack_a, stack_b);
	else
		pb(stack_a, stack_b);
}
