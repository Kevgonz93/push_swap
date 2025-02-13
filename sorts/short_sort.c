/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:39 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:56:41 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "../push_swap.h"

void	sort_three(t_stack *stack)
{
	t_node	*big;

	big = max_value(stack);
	if (big == stack->top)
		ra(stack, true);
	else if (big == stack->top->next)
		rra(stack, true);
	if (stack->top->value > stack->top->next->value)
		sa(stack, true);
}
