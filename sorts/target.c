/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:15 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:57:16 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	aux_update_targets_a(t_node *node, t_node *current,
	long *best, t_node **target)
{
	if (current->value < node->value && current->value > *best)
	{
		*best = current->value;
		*target = current;
	}
}

void	update_targets_a(t_stack *stack_ini, t_stack *stack_last)
{
	t_node	*node;
	t_node	*current;
	t_node	*target;
	long	best;

	if (!stack_last->top)
		return ;
	node = stack_ini->top;
	while (node)
	{
		best = LONG_MIN;
		current = stack_last->top;
		while (current)
		{
			aux_update_targets_a(node, current, &best, &target);
			current = current->next;
		}
		if (best == LONG_MIN)
			node->target = max_value(stack_last);
		else
			node->target = target;
		node = node->next;
	}
}

void	update_targets_b(t_stack *stack_ini, t_stack *stack_last)
{
	t_node	*node;
	t_node	*current;
	t_node	*target;
	long	best;

	node = stack_ini->top;
	while (node)
	{
		best = LONG_MAX;
		current = stack_last->top;
		while (current)
		{
			if (current->value > node->value && current->value < best)
			{
				best = current->value;
				target = current;
			}
			current = current->next;
		}
		if (best == LONG_MAX)
			node->target = min_value(stack_last);
		else
			node->target = target;
		node = node->next;
	}
}
