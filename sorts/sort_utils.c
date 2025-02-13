/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:06 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:57:08 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	pre_push(t_stack *stack, t_node *top_target, char c)
{
	while (stack->top != top_target)
	{
		if (c == 'a')
		{
			if (top_target->second_half)
				rra(stack, true);
			else
				ra(stack, true);
		}
		else if (c == 'b')
		{
			if (top_target->second_half)
				rrb(stack, true);
			else
				rb(stack, true);
		}
	}
}

void	update_target_stack(t_stack *stack_a, t_stack *stack_b)
{
	update_targets_a(stack_a, stack_b);
	if (stack_b->top)
		update_targets_b(stack_b, stack_a);
}

void	update_stack(t_stack *stack_a, t_stack *stack_b)
{
	update_index(stack_a);
	if (stack_b->top)
		update_index(stack_b);
	update_size(stack_a, stack_b);
	update_target_stack(stack_a, stack_b);
	update_cost_a(stack_a, stack_b);
	update_cheapest(stack_a);
	if (stack_b->top)
		update_cheapest(stack_b);
}
