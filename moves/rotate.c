/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:58:10 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:58:12 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

// MOVE THE FIRST NODE TO THE END OF THE STACK
void	rotate(t_stack *stack)
{
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ;
	last = ft_lstlast(stack);
	last->next = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack *stack, bool print)
{
	rotate(stack);
	if (print)
		printf("ra\n");
}

void	rb(t_stack *stack, bool print)
{
	rotate(stack);
	if (print)
		printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
		printf("rr\n");
}

void	doble_rotate(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
	while (stack_b->top != cheapest->target && stack_a->top != cheapest)
		rr(stack_a, stack_b, true);
	update_index(stack_a);
	update_index(stack_b);
}
