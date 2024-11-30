#include "push_swap.h"

void	swap(char *stack)
{
	char	aux;

	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
}

void	sa(char *stack)
{
	swap(stack);
}
