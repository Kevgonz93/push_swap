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

static int	split_stack(t_stack *stack_a, t_stack *stack_b)
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
		printer(stack_a, stack_b);
		i++;
	}
	return (i);
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
	int		nearly;
	int		size;

	size = ft_lstsize(stack);
	nearly = nearly_sorted(stack);
	if (nearly == 0)
	{
		if (!stack->top || !stack->top->next)
			return ("nothing");
		top = stack->top;
		last = ft_lstlast(stack);
		if (top->value > top->next->value)
			return ("swap");
		if (top->value > last->value)
			return ("rotate");
		if (top->value < last->value)
			return ("reverse");
	}
	else
	{
		if (nearly > size / 2)
			return ("reverse");
		else
			return ("rotate");
	}
	return (NULL);
}

static int	same_move(t_stack *stack_a, char *move_a,
				t_stack *stack_b)
{
	if (ft_strncmp(move_a, "rotate", 7))
	{
		rr(stack_a, stack_b);
		printer(stack_a, stack_b);
		return (1);
	}
	else if (ft_strncmp(move_a, "reverse", 8))
	{
		rrr(stack_a, stack_b);
		printer(stack_a, stack_b);
		return (1);
	}
	else
	{
		ss(stack_a, stack_b);
		printer(stack_a, stack_b);
		return (1);
	}
}

static int	sorting(t_stack *stack_a, t_stack *stack_b)
{
	char	*move_a;
	char	*move_b;
	int		i;

	i = 0;
	move_a = next_move(stack_a);
	// printf("next move of a: %s\n", move_a);
	move_b = next_move(stack_b);
	// printf("next move of b: %s\n", move_b);
	if (move_a == move_b)
		i += same_move(stack_a, move_a, stack_b);
	else
	{
		i += move(stack_a, move_a, 'a');
		if (!ft_strncmp(move_a, "nothing", 8))
			printer(stack_a, stack_b);
		move(stack_b, move_b, 'b');
		if (!ft_strncmp(move_b, "nothing", 8))
			printer(stack_a, stack_b);
	}
	return (i);
}

int	search_solution(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	i;

	i = 0;
	if (argc > 50)
		i += split_stack(stack_a, stack_b);
	while (!check(stack_a) || !check(stack_b))
	{
		i += sorting(stack_a, stack_b);
		merge_stack(stack_a, stack_b);
	}
	return (i);
}
