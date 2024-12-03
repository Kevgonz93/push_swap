
#include "push_swap.h"

void	del(int content)
{
	if (content)
		(void)content;
	return ;
}

static void	fill_stack(t_stack *stack, char *argv[])
{
	t_node	*item;
	t_node	*next;
	int		i;

	i = 1;
	item = ft_calloc(1, sizeof(t_node));
	if (!item)
		return (free(item));
	item->value = ft_atoi(argv[i]);
	stack->top = item;
	next = ft_calloc(1, sizeof(t_node));
	if (!next)
		return (free(next));
	while (argv[++i] != NULL)
	{
		next->value = ft_atoi(argv[i]);
		item->next = next;
	}
}

// t_stack	*initial_set(char *argv[])
// {
// 	int		i;
// 	t_stack	*stack;

// 	stack = malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (NULL);
// 	stack->top = NULL;
// 	fill_stack(stack, argv);
// 	return (stack);
// }
