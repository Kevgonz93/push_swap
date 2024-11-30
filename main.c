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

t_stack	*initial_set(char *numbers[])
{
	t_stack	*stack_a;
	t_node	*initial;

	stack_a = ft_calloc(1, sizeof(t_stack));
	initial = ft_lstnew(numbers[1]);
}

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
