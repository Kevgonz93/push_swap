/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:06:40 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:06:41 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorts.h"

int	nearly_sorted(t_stack *stack)
{
	t_node	*node;
	int		block;
	int		break_point;
	int		i;

	break_point = 0;
	block = 1;
	i = 1;
	node = stack->top;
	if (!node || !node->next)
		return (0);
	while (node->next)
	{
		if (node->value > node->next->value)
		{
			block++;
			break_point = i;
		}
		node = node->next;
		i++;
	}
	if (block == 2)
		return (break_point);
	else
		return (0);
}

static char	*next_nearly(t_stack *stack, int nearly)
{
	if (nearly == 0)
		return ("nothing");
	else if (nearly >= ft_lstsize(stack) / 2)
		return ("reverse");
	else
		return ("rotate");
}

int	sorting_nearly(t_stack *stack_a, t_stack *stack_b,
	int nearly_a, int nearly_b)
{
	char	*move_a;
	char	*move_b;
	int		count;

	count = 0;
	move_a = next_nearly(stack_a, nearly_a);
	printf("move_a: %s\n", move_a);
	move_b = next_nearly(stack_b, nearly_b);
	printf("move_b: %s\n", move_b);
	while (!check(stack_a) || !check(stack_b))
	{
		move_a = next_nearly(stack_a, nearly_a);
		move_b = next_nearly(stack_b, nearly_b);
		if (move_a && move_b && !ft_strncmp(move_a, move_b, 7))
		{
			if (same_moving(stack_a, stack_b, move_a))
				count++;
		}
		else
		{
			if (moving(stack_a, move_a, 'a'))
			{
				printer(stack_a, stack_b);
				count++;
			}
			if (moving(stack_b, move_b, 'b'))
			{
				printer(stack_a, stack_b);
				count++;
			}
		}
	}
	return (count);
}
