/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:06:27 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:06:29 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	half;
	int	i;

	size = ft_lstsize(stack_a);
	half = size / 2;
	i = 0;
	while (i < half)
	{
		printf("pb\n");
		pb(stack_a, stack_b);
		i++;
	}
}

static void	merge_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	i;

	size = ft_lstsize(stack_b);
	i = 0;
	while (i < size)
	{
		printf("pa\n");
		pa(stack_a, stack_b);
		i++;
	}
}

static void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	char	*move_a;
	char	*move_b;

	move_a = next_move(stack_a);
	move_b = next_move(stack_b);

	if (move_a == move_b)
	{
		if (move_a == "rotate")
			return (rr(stack_a, stack_b), printf("rr\n"));
		else if (move_a == "reverse")
			return (rrr(stack_a, stack_b), printf("rrr\n"));
		else
			return (ss(stack_a, stack_b), printf("ss\n"));
	}
	move(stack_a, move_a);
	move(stack_b, move_b);
	return ;
}

static char	*next_move(t_stack *stack)
{
	t_node	*top;
	t_node	*last;

	top = stack->top;
	last = ft_lstlast(stack);
	if (top->value > last->value)
		return ("rotate");
	else if (top->value < last->value)
		return ("reverse");
	else if (top->value > top->next->value)
		return ("swap");
}

void	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	split_stack(stack_a, stack_b);
	while (!check(stack_a, stack_b))
	{
		sorting(stack_a, stack_b);
		merge_stack(stack_a, stack_b);
	}
	return ;
}
