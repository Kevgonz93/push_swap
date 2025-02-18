#include "checker.h"

void	make_moves(char **moves, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (moves[i])
	{
		if (!ft_strncmp(moves[i], "sa", 2))
			sa(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "sb", 2))
			sb(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "ss", 2))
			ss(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "pa", 2))
			pa(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "pb", 2))
			pb(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "ra", 2))
			ra(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rb", 2))
			rb(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rr", 2))
			rr(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rra", 3))
			rra(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rrb", 3))
			rrb(stack_a, stack_b);
		else if (!ft_strncmp(moves[i], "rrr", 3))
			rrr(stack_a, stack_b);
		else
		{
			write(2, "Error\n", 6);
			free_matrix(moves);
			free_stack(stack_a);
			free_stack(stack_b);
			exit(1);
		}
		i++;
	}
}

t_stack	*init_stack(int argc, char **args)
{
	int		i;
	t_stack	*stack;
	t_node	*top;
	t_node	*node;

	stack = malloc(sizeof(t_stack));
	stack->size = argc - 1;
	i = 0;
	top = malloc(sizeof(t_node));
	// CHECK IF MALLOC FAILS
	top = ft_new_node(ft_atoi(args[i]));
	stack->top = top;
	while (i++ < argc - 1)
	{
		node = malloc(sizeof(t_node));
		// CHECK IF MALLOC FAILS
		node = ft_new_node(ft_atoi(args[i]));
		top->next = node;
	}
	return (stack);
}

char	**get_args(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = malloc(sizeof(char *) * (argc));
		if (!args)
			return (NULL);
		i = 1;
		while (i < argc)
		{
			args[i - 1] = ft_strdup(argv[i]);
			i++;
		}
		args[argc - 1] = NULL;
	}
	return (args);
}

char	**get_moves(void)
{
	char	**moves;
	char	*line;
	int		i;

	moves = malloc(sizeof(char *) * 100);
	if (!moves)
		return (NULL);
	i = 0;
	while ((line = get_next_line(0)))
	{
		moves[i] = ft_strdup(line);
		free(line);
		i++;
	}
	moves[i] = NULL;
	return (moves);
}

int	main(int argc, char **argv)
{
	char	**moves;
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	args = get_args(argc, argv);
	// IF NO ARGS. WE DONT HAVE NUMBERS TO SORT
	if (!args)
	{
		write(2, "Error\n", 6);
		free_matrix(args);
		return (0);
	}
	// INIT STACKS
	stack_a = init_stack(argc, args);
	free_matrix(args);
	moves = get_moves();
	stack_b = malloc(sizeof(t_stack));
	// IF NO MOVES. WE DONT HAVE MOVES TO SORT
	if ((!moves || !moves[0]) || !ft_strncmp(moves[0], "Error", 5))
	{
		write(2, "Error\n", 6);
		free_matrix(moves);
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	// MAKE MOVES
	make_moves(moves, stack_a, stack_b);
	// AFTER MOVES, CHECK IF STACK_A IS SORTED
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_matrix(moves);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
