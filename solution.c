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

static int	position(int value, int *solution, int size)
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
	t_node	*node;
	int		n;
	int		*solution;
	int		size;

	if (!stack->top || !stack->top->next || check(stack) == 1)
		return ("nothing");
	solution = stack_sorted(stack);
	if (!solution)
		return (NULL);
	size = ft_lstsize(stack);
	node = stack->top;
	n = position(node->value, solution, size);
	free(solution);
	if (n == -1)
		return (NULL);
	if (node->value > node->next->value)
	{
		return ("swap");
	}
	else if (n <= size / 2)
		return ("rotate");
	else
		return ("reverse");
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
		while (!check(stack_a) || !check(stack_b))
		{
			printf(">>>>>>>> initiating sorting <<<<<<<<\n");
			move_a = next_move(stack_a);
			printf("move_a: %s\n", move_a);
			move_b = next_move(stack_b);
			printf("move_b: %s\n", move_b);
			if (!ft_strncmp(move_a, move_b, 7))
			{
				printf("move_a is equal to move_b\n");
				i += same_move(stack_a, stack_b, move_a);
			}
			else
			{
				while (ft_strncmp(move_a, move_b, 7) && !check(stack_a))
				{
					printf("check result: %d\n", check(stack_a));
					printf("------------ A move's init ----------------\n");
					printf("move_a was: %s\n", move_a);
					printf("move_b was: %s\n", move_b);
					i += move(stack_a, move_a, 'a');
					nearly_a = nearly_sorted(stack_a);
					printf("new nearly_a: %d\n", nearly_a);
					printer(stack_a, stack_b);
					printf("----------- A move's finish ----------------\n");
					printf("--------- next move_a search initied ---------\n");
					if (nearly_a == 0)
						move_a = next_move(stack_a);
					else
						move_a = next_nearly(stack_a, nearly_a);
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
		// while (nearly_a != 0 && nearly_b != 0)
		// {
		// 	printf("initating sorting_nearly\n");
		// 	printf("nearly_a: %d\n", nearly_a);
		// 	move_a = next_nearly(stack_a, nearly_a);
		// 	printf("move_a: %s\n", move_a);
		// 	printf("nearly_b: %d\n", nearly_b);
		// 	move_b = next_nearly(stack_b, nearly_b);
		// 	printf("move_b: %s\n", move_b);
		// 	while (i < nearly_a && i < nearly_b)
		// 	{
		// 		printf("i: %d\n", i);
		// 		if (ft_strncmp(move_a, move_b, 7))
		// 		{
		// 			printf("move_a: %s\n", move_a);
		// 			i += move(stack_a, move_a, 'a');
		// 			printf("move_b: %s\n", move_b);
		// 			i += move(stack_b, move_b, 'b');
		// 		}
		// 		else
		// 		{
		// 			printf("move_a: %s\n", move_a);
		// 			i += same_move(stack_a, stack_b, move_a);
		// 		}
		// 	}
		// 	if (i < nearly_a)
		// 	{
		// 		while (i < nearly_a)
		// 		{
		// 			printf("move_a: %s\n", move_a);
		// 			i += move(stack_a, move_a, 'a');
		// 		}
		// 	}
		// 	else if (i < nearly_b)
		// 	{
		// 		while (i < nearly_b)
		// 		{
		// 			printf("move_b: %s\n", move_b);
		// 			i += move(stack_b, move_b, 'b');
		// 		}
		// 	}
		// 	return (i);
		// }
	}
	return (i);
}

int	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	i += split_stack(stack_a, stack_b);
	printf("stack splitted\n");
	while (!check(stack_a) || !check(stack_b))
	{
		printf("initiating sorting\n");
		i += sorting(stack_a, stack_b);
		// merge_stack(stack_a, stack_b);
	}
	return (i);
}
