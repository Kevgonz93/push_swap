/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:35 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:36 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = stack->top->next;
	stack->top->next = first;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	printf("ss\n");
	swap(stack_a);
	swap(stack_b);
}

int	is_swap(t_stack *stack, int *solution, int size)
{
	(void)size;
	int	i;

	move(stack, "swap", 'a');

	i = 0;
	if (stack->top->value > stack->top->next->value)
		i++;
	if (stack->top->value < ft_lstlast(stack)->value)
		i++;
	if (stack->top->next->value == solution[0])
		i++;
	if (stack->top->value == solution[1])
		i++;
	if (i > 2)
	{
		printf("is_swap: %d\n", i);
		return (1);
	}
	else
		return (0);
}
