/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:20 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:56:21 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	update_cost_a(t_stack *stack_init, t_stack *stack_last)
{
	t_node	*node;
	int		size_a;
	int		size_b;

	size_a = stack_init->size;
	size_b = stack_last->size;
	node = stack_init->top;
	while (node)
	{
		node->cost_push = node->index;
		if (node->second_half)
			node->cost_push = size_a - node->index;
		if (!node->target->second_half)
			node->cost_push += node->target->index;
		else
			node->cost_push += size_b - node->target->index;
		node = node->next;
	}
}

void	update_cheapest(t_stack *stack)
{
	long	value;
	t_node	*cheapest;
	t_node	*node;

	if (!stack->top)
		return ;
	value = LONG_MAX;
	node = stack->top;
	while (node)
	{
		if (node->cost_push < value)
		{
			value = node->cost_push;
			cheapest = node;
		}
		node = node->next;
	}
	cheapest->cheapest = true;
}
