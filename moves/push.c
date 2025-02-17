/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:47 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:57:48 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

static void	push(t_stack *stack_dst, t_stack *stack_src)
{
	t_node	*temp;

	if (!stack_src->top)
		return ;
	temp = stack_src->top;
	stack_src->top = stack_src->top->next;
	if (stack_src->top)
		stack_src->top->prev = NULL;
	temp->prev = NULL;
	if (!stack_dst->top)
	{
		stack_dst->top = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = stack_dst->top;
		temp->next->prev = temp;
		stack_dst->top = temp;
	}
}

// MOVE THE FIRST NODE OF STACK_A TO STACK_B
void	pb(t_stack *stack_a, t_stack *stack_b, bool print)
{
	push(stack_b, stack_a);
	if (print)
		printf("pb\n");
}

// MOVE THE FIRST NODE OF STACK_B TO STACK_A
void	pa(t_stack *stack_a, t_stack *stack_b, bool print)
{
	push(stack_a, stack_b);
	if (print)
		printf("pa\n");
}
