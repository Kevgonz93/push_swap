#include "push_swap.h"

static t_node	*create_node(int n, t_node *prev, int index)
{
	t_node	*node;

	node = ft_lstnew(n);
	node->index = index;
	node->cost_push = 0;
	node->second_half = false;
	node->cheapest = false;
	node->target = 0;
	node->prev = prev;
	node->next = 0;
	if (prev)
		prev->next = node;
<<<<<<< HEAD
=======
	// print_node_values(node);
>>>>>>> refs/remotes/origin/main
	return (node);
}

static t_stack	*full_matrix(int *num, int size)
{
	t_stack	*stack;
	t_node	*prev;
	t_node	*node;
	int		i;

	i = 0;
	stack = ft_calloc(1, sizeof(t_stack));
	prev = create_node(num[0], NULL, 1);
	stack->top = prev;
	i++;
	while (i < size)
	{
		node = create_node(num[i], prev, i);
		prev = node;
		i++;
	}
	stack->size = ft_lstsize(stack);
	return (stack);
}

static int	*numbers(char **nbrs, int size)
{
	int		*numbers;
	int		i;
	long	n;

	i = 0;
	numbers = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		if (!check_data(nbrs[i]))
		{
			free(numbers);
			exit(1);
		}
		n = ft_atol(nbrs[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free(numbers);
			exit(1);
		}
		numbers[i++] = (int)n;
	}
	return (numbers);
}

t_stack	*stack_init(char **nbrs)
{
	t_stack	*stack;
	int		*num;
	int		i;

	i = 0;
	while (nbrs[i])
		i++;
	num = numbers(nbrs, i);
	stack = full_matrix(num, i);
	i = 0;
	free(num);
	return (stack);
}
