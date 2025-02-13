/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:58:18 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:58:19 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"

void	swap(t_stack *stack)
{
	if (!stack->top || !stack->top->next)
		return ;
	stack->top = stack->top->next;
	stack->top->prev->prev = stack->top;
	stack->top->prev->next = stack->top->next;
	if (stack->top->next)
		stack->top->next->prev = stack->top->prev;
	stack->top->next = stack->top->prev;
	stack->top->prev = NULL;
}

void	sa(t_stack *stack, bool print)
{
	swap(stack);
	if (print)
		printf("sa\n");
}

void	sb(t_stack *stack, bool print)
{
	swap(stack);
	if (print)
		printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b, bool print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		printf("ss\n");
}
