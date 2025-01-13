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
#include "moves/moves.h"

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
	if (!solution)
		return (NULL);
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
			return (free(solution), NULL);
		i++;
	}
	return (solution);
}

int	position(int value, int *solution, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (solution[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static char	*next_move(t_stack *stack)
{
	int		*solution;
	int		size;
	int		swap;
	int		rotate;
	int		reverse;

	if (!stack->top || !stack->top->next || check(stack) == 1)
		return ("nothing");
	solution = stack_sorted(stack);
	if (!solution)
		return (NULL);
	size = ft_lstsize(stack);
	swap = is_swap(stack, solution, size);
	rotate = is_rotate(stack, solution, size);
	reverse = is_reverse(stack, solution, size);
	printf("swap: %d\t rotate: %d\t reverse: %d\n", swap, rotate, reverse);
	if (swap >= rotate && swap >= reverse)
		return ("swap");
	else if (rotate >= swap && rotate >= reverse)
		return ("rotate");
	else
		return ("reverse");
	return (free(solution), "nothing");
}

static int	large_sorting(t_stack *stack_a, t_stack *stack_b)
{
	static int		nearly_a;
	static int		nearly_b;
	static char		*move_a;
	static char		*move_b;
	int				i;

	i = 0;
	nearly_a = nearly_sorted(stack_a);
	nearly_b = nearly_sorted(stack_b);
	while (!check(stack_a) || !check(stack_b))
	{
		printf("<<<<<<<<<<<<<<<<<<-- sorting -->>>>>>>>>>>>>>>>>>\n");
		if (nearly_a == 0)
			nearly_a = nearly_sorted(stack_a);
		printf("nearly_a: %d\n", nearly_a);
		if (nearly_b == 0)
			nearly_b = nearly_sorted(stack_b);
		printf("nearly_b: %d\n", nearly_b);
		if (nearly_a == 0)
			move_a = next_move(stack_a);
		printf("move_a: %s\n", move_a);
		if (nearly_b == 0)
			move_b = next_move(stack_b);
		printf("move_b: %s\n", move_b);
		if (!ft_strncmp(move_a, move_b, 7))
		{
			printf("------------ same move initiated ------------\n");
			printf("the move is: \t\t\t\t");
			i += same_move(stack_a, stack_b, move_a);
			if (nearly_a != 0)
				nearly_a--;
			else
				nearly_a = nearly_sorted(stack_a);
			if (nearly_b != 0)
				nearly_b--;
			else
				nearly_b = nearly_sorted(stack_b);
			printf("new nearly_a: %d\n", nearly_a);
			printf("new nearly_b: %d\n", nearly_b);
			printf("------------ same move finished ------------\n");
			printf("--------- next moves search initied ---------\n");
			if (nearly_a == 0)
			{
				printf("nearly_a is 0\n");
				move_a = next_move(stack_a);
			}
			if (nearly_b == 0)
			{
				printf("nearly_b is 0\n");
				move_b = next_move(stack_b);
			}
			printf("new move_a: %s\n", move_a);
			printf("new move_b: %s\n", move_b);
			printf("--------- next moves search finished ---------\n");
		}
		else
		{
			while (ft_strncmp(move_a, move_b, 7) && !check(stack_a))
			{
				printf("check result: %d\n", check(stack_a));
				printf("-------------- A move's init ------------------\n");
				printf("move_a was: %s\n", move_a);
				printf("move_b was: %s\n", move_b);
				printf("the move is: \t\t\t\t");
				i += move(stack_a, move_a, 'a');
				if (nearly_a != 0)
					nearly_a--;
				printf("new nearly_a: %d\n", nearly_a);
				printer(stack_a, stack_b);
				printf("------------- A move's finish ------------------\n");
				printf("--------- next move_a search initied ---------\n");
				printf("stack_a:\n");
				printf("top: %d\n", stack_a->top->value);
				printf("next: %d\n", stack_a->top->next->value);
				printf("bottom: %d\n", ft_lstlast(stack_a)->value);
				printf("near_a: %d\n", nearly_a);
				printf("new move_a: %s\n", move_a);
				if (!ft_strncmp(move_a, move_b, 7))
					printf("move_a is equal to move_b\n");
				printf("--------- next move_a search finished ---------\n");
			}
			while (ft_strncmp(move_a, move_b, 7) && !check(stack_b))
			{
				printf("check result: %d\n", check(stack_a));
				printf("------------- B move's init ----------------\n");
				printf("move_a was: %s\n", move_a);
				printf("move_b was: %s\n", move_b);
				printf("the move is: \t\t\t\t");
				i += move(stack_b, move_b, 'b');
				nearly_b = nearly_sorted(stack_b);
				printf("new nearly_b: %d\n", nearly_b);
				printer(stack_a, stack_b);
				printf("------------- B move's finish ----------------\n");
				printf("--------- next move_b search initied ---------\n");
				if (nearly_a == 0)
					move_b = next_move(stack_b);
				else
					move_b = next_nearly(stack_b, nearly_b);
				printf("stack_b:\n");
				printf("top: %d\n", stack_b->top->value);
				printf("next: %d\n", stack_b->top->next->value);
				printf("bottom: %d\n", ft_lstlast(stack_b)->value);
				printf("near_b: %d\n", nearly_b);
				printf("new move_b: %s\n", move_b);
				if (!ft_strncmp(move_a, move_b, 7))
					printf("move_a is equal to move_b\n");
				printf("--------- next move_b search finished ---------\n");
			}
		}
	}
	return (i);
}

int	short_sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_node *top;
	t_node *bottom;
	t_node *mid;

	top = stack_a->top;
	mid = top->next;
	bottom = ft_lstlast(stack_a);
	if (top->value > mid->value && mid->value < bottom->value && top->value > bottom->value)
	{
		printf("ra\n");
		rotate(stack_a);
		printer(stack_a, stack_b);
		return (1);
	}
	else if (top->value > bottom->value && top->value > mid->value && mid->value > bottom->value)
	{
		printf("ra\n");
		rotate(stack_a);
		printer(stack_a, stack_b);
		printf("sa\n");
		swap(stack_a);
		printer(stack_a, stack_b);
		return (2);
	}
	else if (top->value < mid->value && top->value > bottom->value && mid->value > bottom->value)
	{
		printf("rra\n");
		reverse(stack_a);
		printer(stack_a, stack_b);
		return (1);
	}
	else if (top->value < mid->value && top->value < bottom->value && mid->value > bottom->value)
	{
		printf("sa\n");
		swap(stack_a);
		printer(stack_a, stack_b);
		printf("ra\n");
		rotate(stack_a);
		printer(stack_a, stack_b);
		return (2);
	}
	else if (top->value > mid->value && mid->value < bottom->value)
	{
		printf("sa\n");
		swap(stack_a);
		printer(stack_a, stack_b);
		return (1);
	}
	else
		return (0);
}

int	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(stack_a);

	if (size == 3)
	{
		printf("short sorting\n");
		i += short_sorting(stack_a, stack_b);
		return (i);
	}
	else
	{
		i += split_stack(stack_a, stack_b);
		printf("stack splitted\n");
		// get_cost(stack_a, stack_b);
		// printf("cost calculated\n");
		while (!check(stack_a) || !check(stack_b))
		{
			printf("initiating sorting\n");
			i += large_sorting(stack_a, stack_b);
			// merge_stack(stack_a, stack_b);
		}
	}
	return (i);
}
