/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:16:09 by kegonzal          #+#    #+#             */
/*   Updated: 2024/11/30 19:16:12 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "aux/libft.h"

t_stack	*initial_set(char *numbers[])
{
	t_stack	*stack;
	t_node	*initial;
	t_node	*new;
	int		i;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = 1;
	initial = ft_lstnew(ft_atoi(numbers[i++]));
	if (!initial)
		return (free(stack), NULL);
	stack->top = initial;
	// printf("top-value = %d\n\n", stack->top->value);
	// printf("node-value = %d\n", initial->value);
	while (numbers[i])
	{
		new = ft_lstnew(ft_atoi(numbers[i++]));
		if (!new)
			return	(free(stack), ft_lstclear(stack, del), NULL);
		ft_lstadd_back(stack, new);
		// printf("node-value = %d\n", new->value);
	}
	return (stack);
}

static void	printer(t_stack *stack)
{
	t_node	*node;
	int		i;

	i = 1;
	node = stack->top;
	if (!node)
		return ;
	printf("stack[%d]\t=\t%d\n", i, node->value);
	i++;
	while (node->next)
	{
		node = node->next;
		printf("stack[%d]\t=\t%d\n", i, node->value);
		i++;
	}
	printf("---------------------------------\t\t--------------------------------\n");
	printf("\t\tA\t\t\t\t\t\tB\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		i;

	// i = 1;
	// while (argv[i])
	// 	printf("numbers: %s\n", argv[i++]);
	if (argc == 1)
		return (printf("Please choise the numbers to start the program\n"));
	stack_a = initial_set(argv);
	printf("numbers = %d\n", argc - 1);
	printer(stack_a);
	ft_lstclear(stack_a, del);
	return (0);
}
