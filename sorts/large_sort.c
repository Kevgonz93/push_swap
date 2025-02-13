/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:28 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:56:29 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	moving_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	cheapest = min_cost(stack_a);
	if (!cheapest->second_half && !cheapest->target->second_half)
		doble_rotate(stack_a, stack_b, cheapest);
	else if (cheapest->second_half && cheapest->target->second_half)
		doble_reverse(stack_a, stack_b, cheapest);
	pre_push(stack_a, cheapest, 'a');
	pre_push(stack_b, cheapest->target, 'b');
	pb(stack_a, stack_b, true);
}

void	moving_to_a(t_stack *stack_a, t_stack *stack_b)
{
	pre_push(stack_a, stack_b->top->target, 'a');
	pa(stack_a, stack_b, true);
}

void	move_to_top(t_stack *stack)
{
	t_node	*node;

	node = min_value(stack);
	while (stack->top != node)
	{
		if (node->second_half)
			rra(stack, true);
		else
			ra(stack, true);
	}
}

void	init_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_a->size > 3 && i < 2 && !check_sorted(stack_a, 'a'))
	{
		pb(stack_a, stack_b, true);
		stack_a->size--;
		i++;
	}
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	init_b(stack_a, stack_b);
	while (stack_a->size > 3 && !check_sorted(stack_a, 'a'))
	{
		update_stack(stack_a, stack_b);
		moving_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->top)
	{
		update_stack(stack_a, stack_b);
		moving_to_a(stack_a, stack_b);
	}
	update_stack(stack_a, stack_b);
	move_to_top(stack_a);
}
