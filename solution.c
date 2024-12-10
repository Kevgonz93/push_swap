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

// static void	merge_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	size;
// 	int	i;

// 	size = ft_lstsize(stack_b);
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("pa\n");
// 		pa(stack_a, stack_b);
// 		printer(stack_a, stack_b);
// 		i++;
// 	}
// }

static int	*pre_solution(t_stack *stack)
{
	t_node	*node;
	int		*solution;
	int		i;

	solution = ft_calloc(ft_lstsize(stack), sizeof(int));
	node = stack->top;
	i = 0;
	while (node)
	{
		solution[i++] = node->value;
		node = node->next;
	}
	return (solution);
}

static void	*stack_sorted(t_stack *stack)
{
	t_node	*node;
	int		*solution;
	int		i;

	solution = pre_solution(stack);
	i = 0;
	while (i < ft_lstsize(stack))
	{
		node = stack->top;
		while (node)
		{
			if (solution[i] == node->value)
				break ;
			node = node->next;
		}
		if (!node)
			return (ft_lstclear(stack, del), free(solution), NULL);
		i++;
	}
	return (solution);
}

static int	position(int value, int *solution)
{
	int	i;

	i = 0;
	while (solution[i] != value)
		i++;
	return (i);
}

static char	*next_move(t_stack *stack)
{
	t_node	*node;
	int		n;
	int		*solution;

	if (!stack->top || !stack->top->next || check(stack))
		return ("nothing");
	solution = ft_calloc(ft_lstsize(stack), sizeof(int));
	solution = stack_sorted(stack);
	node = stack->top;
	n = position(node->value, solution);
	if (node->value > node->next->value)
		return ("swap");
	else if (n <= ft_lstsize(stack) / 2)
		return ("rotate");
	else
		return ("reverse");
}

int	same_move(t_stack *stack_a, t_stack *stack_b, char *move_a)
{
	if (ft_strncmp(move_a, "rotate", 7))
	{
		rr(stack_a, stack_b);
		return (printer(stack_a, stack_b), 1);
	}
	else if (ft_strncmp(move_a, "reverse", 8))
	{
		rrr(stack_a, stack_b);
		return (printer(stack_a, stack_b), 1);
	}
	else
	{
		ss(stack_a, stack_b);
		return (printer(stack_a, stack_b), 1);
	}
}

static int	sorting(t_stack *stack_a, t_stack *stack_b)
{
	int		nearly_a;
	int		nearly_b;
	int		i;
	char	*move_a;
	char	*move_b;

	i = 0;
	while (!check(stack_a) || !check(stack_b))
	{
		nearly_a = nearly_sorted(stack_a);
		nearly_b = nearly_sorted(stack_b);
		while (nearly_a == 0 && nearly_b == 0)
		{
			move_a = next_move(stack_a);
			move_b = next_move(stack_b);
			if (ft_strncmp(move_a, move_b, 7))
				i += same_move(stack_a, stack_b, move_a);
			else
			{
				// must correct this, always goes to the same move 
				// and never stops. 
				// I must add a condition to stop the loop changing the move
				while (!ft_strncmp(move_a, move_b, 7)
					|| !check(stack_a) || ft_strncmp(move_a, "nothing", 8))
				{
					i += move(stack_a, move_a, 'a');
					printer(stack_a, stack_b);
				}
				while (!ft_strncmp(move_a, move_b, 7)
					|| !check(stack_b) || ft_strncmp(move_b, "nothing", 8))
				{
					i += move(stack_b, move_b, 'b');
					printer(stack_a, stack_b);
				}
			}
		}
		if (nearly_a != 0 || nearly_b != 0)
			i += sorting_nearly(stack_a, stack_b, nearly_a, nearly_b);
	}
	return (i);
}

int	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	i += split_stack(stack_a, stack_b);
	while (!check(stack_a) || !check(stack_b))
	{
		i += sorting(stack_a, stack_b);
		// merge_stack(stack_a, stack_b);
	}
	return (i);
}
