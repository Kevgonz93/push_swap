/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:55:34 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:55:36 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*min_value(t_stack *stack)
{
	long	min;
	t_node	*min_node;
	t_node	*node;

	if (!stack->top)
		return (NULL);
	min = LONG_MAX;
	node = stack->top;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

t_node	*max_value(t_stack *stack)
{
	long	max;
	t_node	*max_node;
	t_node	*node;

	if (!stack->top)
		return (NULL);
	max = LONG_MIN;
	node = stack->top;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

t_node	*min_cost(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}
