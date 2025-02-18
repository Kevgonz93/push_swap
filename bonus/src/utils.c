#include "../checker.h"

void	make_moves(char **moves, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (!ft_strncmp(moves[i], "s", 1))
			is_swap(stack_a, stack_b, moves[i]);
		else if (!ft_strncmp(moves[i], "p", 1))
			is_push(stack_a, stack_b, moves[i]);
		else if (!ft_strncmp(moves[i], "rra", 3))
			rra(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rrb", 3))
			rrb(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rrr", 3))
			rrr(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "ra", 2))
			ra(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rb", 2))
			rb(stack_a, stack_b);
		else
			rr(stack_a, stack_b);
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
