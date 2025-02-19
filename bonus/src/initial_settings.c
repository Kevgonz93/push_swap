#include "../checker.h"

t_stack	*init_stack(int argc, char **args)
{
	int		i;
	t_stack	*stack;
	t_node	*temp;
	t_node	*node;

	stack = ft_calloc(sizeof(t_stack), 1);
	stack->size = argc - 1;
	i = 0;
	temp = ft_lstnew(ft_atoi(args[i]));
	stack->top = temp;
	i++;
	while (args[i])
	{
		node = ft_lstnew(ft_atoi(args[i]));
		if (!node)
		{
			free_stack(stack);
			return (NULL);
		}
		temp->next = node;
		node->prev = temp;
		temp = node;
		i++;
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
		args = ft_calloc(sizeof(char *), (argc));
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

static char	**update_moves(char **moves, int i)
{
	char	**temp;
	int		j;

	temp = ft_calloc(sizeof(char *), (i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	while (j < i)
	{
		temp[j] = moves[j];
		j++;
	}
	temp[j] = NULL;
	free(moves);
	return (temp);
}

char	**get_moves(void)
{
	char	**moves;
	char	*line;
	int		i;

	moves = ft_calloc(sizeof(char *), 50000);
	if (!moves)
		return (NULL);
	i = 0;
	line = get_next_line(0);
	while (line)
	{
		moves[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(0);
	}
	moves = update_moves(moves, i);
	return (moves);
}
