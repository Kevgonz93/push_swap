/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:55 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:57:58 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

// MOVE THE LAST NODE TO THE BEGINNING OF THE STACK
void	reverse(t_stack *stack)
{
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	last = ft_lstlast(stack);
	last->prev->next = NULL;
	last->next = stack->top;
	last->prev = NULL;
	stack->top = last;
	last->next->prev = last;
}

void	rra(t_stack *stack, bool print)
{
	reverse(stack);
	if (print)
		printf("rra\n");
}

void	rrb(t_stack *stack, bool print)
{
	reverse(stack);
	if (print)
		printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	reverse(stack_a);
	reverse(stack_b);
	if (print)
		printf("rrr\n");
}

void	doble_reverse(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
	while (stack_b->top != cheapest->target && stack_a->top != cheapest)
	{
		rrr(stack_a, stack_b, true);
		update_stack(stack_a, stack_b);
	}
}
