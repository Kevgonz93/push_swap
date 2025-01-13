/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:06:49 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:06:50 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (!stack_b->top)
		return (0);
	node = stack_b->top;
	stack_b->top = node->next;
	node->next = stack_a->top;
	stack_a->top = node;
	return (printf("pa\n"));
}

int	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	if (!stack_a->top)
		return (0);
	node = stack_a->top;
	stack_a->top = node->next;
	node->next = stack_b->top;
	stack_b->top = node;
	return (printf("pb\n"));
}
