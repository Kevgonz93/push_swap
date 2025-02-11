#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		stack_a = stack_init(argv);
	}
	else
		stack_a = stack_init(argv + 1);
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!check_sorted(stack_a, 'a'))
	{
		if (stack_a->size == 2)
			sa(stack_a, true);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else
			sort_stacks(stack_a, stack_b);
	}
	ft_lstclear(stack_a);
	free(stack_b);
}
