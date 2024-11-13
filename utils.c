#include "aux/libft.h"
#include "push_swap.h"
#include <stdio.h>

int	initial_check(char *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	check(char *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] >= stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}
