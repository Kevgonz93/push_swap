/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:07:01 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:07:02 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = ft_lstlast(stack);
	while (first->next != last)
		first = first->next;
	first->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	printf("rrr\n");
	reverse(stack_a);
	reverse(stack_b);
}

int	is_reverse(t_stack *stack, int *solution, int size)
{
	(void)solution;
	(void)size;
	int	i;

	i = 0;
	if (stack->top->value > ft_lstlast(stack)->value)
		i++;
	if (stack->top->value < stack->top->next->value)
		i++;
	if (i > 1)
	{
		printf("is_reverse: %d\n", i);
		return (1);
	}
	return (0);
}
