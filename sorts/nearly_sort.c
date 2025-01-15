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

int	is_nearly(t_stack *stack)
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

int	nearly_sort(t_stack *stack, int nearly)
{
	char	*move_a;
	int		count;

	count = 0;
	move_a = next_nearly(stack, nearly);
	printf("move_a: %s\n", move_a);
	while (!check(stack))
	{
		moving(stack, move_a, 'a');
		count++;
	}
	return (count);
}
