#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

static void	initial_set(int size, char *input[], char *stack1)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		stack1[i] = *input[i + 1];
		i++;
	}
	stack1[i] = '\0';
}

static void	fill_new_stack(char *stack2, int size)
{
	int	i;
	int	n;

	i = size - 1;
	n = 0;
	while (n < i)
		stack2[n++] = ' ';
	stack2[n] = '\0';
}

static void	ft_aux(char *stack1, char *stack2, int size)
{
	int		n;
	int		i;
	char	c;

	i = size - 2;
	n = 0;
	c = ' ';
	while (stack1[n])
	{
		stack2[i--] = stack1[n];
		stack1[n++] = c;
	}
}

static void	printer(char *str1, char *str2)
{
	int	n;

	n = 0;
	while (str1[n] != '\0')
		printf("stack1[%d]='%c'\tstack2[%d]='%c'\n", n, str1[n], n, str2[n++]);
	printf("\n");
}

int	main(int argc, char *argv[])
{
	char	*stack1;
	char	*stack2;

	stack1 = ft_calloc(argc, sizeof(char));
	stack2 = ft_calloc(argc, sizeof(char));
	// initial function: save argvs in stack1
	initial_set(argc, argv, stack1);
	// check initial: check no repeat
	if (initial_check(stack1, argc - 1))
		fill_new_stack(stack2, argc);
	else
		return (printf("Bad numbers selected\n"));
	printf("pre move:\n\n");
	printer(stack1, stack2);
	ft_aux(stack1, stack2, argc);
	printf("post move:\n\n");
	printer(stack1, stack2);
	return (0);
}
