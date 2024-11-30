#include "push_swap.h"

static void	fill_stack(t_stack *stack, char *argv[])
{
	t_node	*item;
	t_node	*next;
	int		i;

	i = 1;
	item = malloc(sizeof(t_node));
	item->value = ft_atoi(argv[i]);
	stack->top = item;
	next = malloc(sizeof(t_node));
	while (argv[++i] != NULL)
	{
		next->value = argv[i];
		item->next = next;
	}
}

t_stack	*initial_set(char *argv[])
{
	int		i;
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	fill_stack(stack, argv);
	return (stack);
}
