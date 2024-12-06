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
		pb(stack_a, stack_b);
		printf("pb\n");
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

static char	*next_move(t_stack *stack)
{
	t_node	*top;
	t_node	*last;

	if (!stack->top || !stack->top->next)
		return ("nothing");
	top = stack->top;
	last = ft_lstlast(stack);
	if (top->value > last->value)
		return ("rotate");
	else if (top->value < last->value)
		return ("reverse");
	else if (top->value > top->next->value)
		return ("swap");
	return (NULL);
}

static void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	char	*move_a;
	char	*move_b;

	move_a = next_move(stack_a);
	move_b = next_move(stack_b);
	while (!check(stack_a) && !check(stack_b))
	{
		if (move_a && move_b)
		{
			if (ft_strncmp(move_a, "rotate", 7) && ft_strncmp(move_b, "rotate", 7))
				rr(stack_a, stack_b);
			else if (ft_strncmp(move_a, "reverse", 8) && ft_strncmp(move_b, "reverse", 8))
				rrr(stack_a, stack_b);
			else
				ss(stack_a, stack_b);
		}
		if (!ft_strncmp(move_a, "nothing", 8))
			move_a = next_move(stack_a);
		if (!ft_strncmp(move_b, "nothing", 8))
			move_b = next_move(stack_b);
	}
	return ;
	// if (move_a == move_b)
	// {
	// 	if (ft_strncmp(move_a, "rotate", 7))
	// 		rr(stack_a, stack_b);
	// 	else if (ft_strncmp(move_a, "reverse", 8))
	// 		rrr(stack_a, stack_b);
	// 	else
	// 		ss(stack_a, stack_ˆb);
	// }
	// move(stack_a, move_a, 'a');
	// move(stack_b, move_b, 'b');
	// return ;
}

void	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	split_stack(stack_a, stack_b);
	while (!check(stack_a) && stack_b->top)
		sorting(stack_a, stack_b);
	merge_stack(stack_a, stack_b);
	// check
	return ;
}
