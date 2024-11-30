#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

static void	printer(t_stack stack)
{
	t_node	*top;
	t_node	*next;

	top = stack.top;
	next = top->next;
	printf("%d\n", top->value);
	while (top->next != NULL)
	{
		printf("%d\n", next->value);
		next = next->next;
	}
	printf("---------------------\n");
	printf("A\t\tB\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = initial_set(argv);
	printer(*stack_a);
	return (0);
}
