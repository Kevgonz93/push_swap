/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:35 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:36 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;

	if (!stack->top || !stack->top->next)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = stack->top->next;
	stack->top->next = first;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	printf("ss\n");
	swap(stack_a);
	swap(stack_b);
}
