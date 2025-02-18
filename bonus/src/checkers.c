#include "../checker.h"

void	check_moves(char **moves, t_stack *stack_a)
{
	if ((!moves || !moves[0]) || !ft_strncmp(moves[0], "Error", 5))
	{
		write(2, "Error\n", 6);
		free_matrix(moves);
		free_stack(stack_a);
		exit(0);
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}
