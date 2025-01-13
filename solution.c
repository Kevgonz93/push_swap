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

static int	moving_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(stack_a);
	while (i < 2 && size != 3)
	{
		pb(stack_a, stack_b);
		printer(stack_a, stack_b);
		i++;
		size = ft_lstsize(stack_a);
	}
	return (i);
}

static void	sort_solution(int *solution, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (solution[i] > solution[j])
			{
				temp = solution[i];
				solution[i] = solution[j];
				solution[j] = temp;
			}
			j++;
		}
		i++;
	}
}

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

int	*get_solution(t_stack *stack)
{
	int		*solution;
	int		size;

	solution = pre_solution(stack);
	if (!solution)
		return (NULL);
	size = ft_lstsize(stack);
	sort_solution(solution, size);
	return (solution);
}

int search_index(t_stack *stack, int *solution)
{
	t_node	*node;
	int		i;

	node = stack->top;
	i = 0;
	while (node)
	{
		if (node->value == solution[i])
			return (i);
		i++;
	}
	return (0);
}

int sort_stack(t_stack *stack)
{
	// t_node	*node;
	char	*move;
	int		count;

	// node = stack->top;
	count = 0;
	move = next_move(stack);
	while (!check(stack))
	{
		count += moving(stack, move, 'a');
		move = next_move(stack);
	}
	return (count);
}

char	*next_move(t_stack *stack)
{
	t_node	*node;
	t_node	*initial_bottom;
	int		*solution;
	// int		i;
	int		index;

	node = stack->top;
	solution = get_solution(stack);
	index = search_index(stack, solution);
	initial_bottom = ft_lstlast(stack);
	if (!stack->top || !stack->top->next || check(stack) == 1)
		return (free(solution), "nothing");
	if (node->value > initial_bottom->value)
		return (free(solution), "rotate");
	else if (index <= stack->size / 2)
		return (free(solution), "swap");
	return (free(solution), "nothing");
}

t_node	*lower_cost(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;
	int		cost;

	node = stack->top;
	temp = node;
	cost = node->cost;
	while (node)
	{
		if (node->cost < cost)
		{
			cost = node->cost;
			temp = node;
		}
		node = node->next;
	}
	return (temp);
}

int	move_to_top(t_stack *stack_a, int index, t_stack *stack_b)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (i < index)
	{
		if (i <= stack_a->size / 2)
		{
			printf("ra\n");
			rotate(stack_a);
			printer(stack_a, stack_b);
			count++;
		}
		else
		{
			printf("rra\n");
			reverse(stack_a);
			count++;
		}
		i++;
	}
	return (count);
}

static int	large_sorting(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		i;
	int		count;

	count = 0;
	count += moving_to_b(stack_a, stack_b);
	printf("moving to b done\n");
	printf("%d\n", count);

	if (ft_lstsize(stack_a) == 3)
	{
		count += short_sorting(stack_a, stack_b);
		printf("short sorting done\n");
		printf("%d\n", count);
		while (!check(stack_a))
		{
			count += sort_stack(stack_a);
		}
	}
// 		while (!check(stack_a) || stack_b->top)
// 		{
// 			size = ft_lstsize(stack_a);
// 			update_index(stack_a, stack_b);
// 			printf("index updated\n");
// 			get_cost(stack_a, stack_b);
// 			printf("cost calculated\n");
// 			if (size == 3)
// 			{
// 				i += pa(stack_a, stack_b);
// 				printer(stack_a, stack_b);
// 				while (!check(stack_a))
// 				{
// 					i += large_sorting(stack_a, stack_b);
// 				}
// 			}

// 			size = ft_lstsize(stack_a);
// 			while (!check(stack_a) || size != 2)
// 			{
// 				printf("searching for a solution with large sorting\n");
// 				i += large_sorting(stack_a, stack_b);
// 			}

	node = lower_cost(stack_a);
	i = node->index;
	count = move_to_top(stack_a, i, stack_b);
	count += pb(stack_a, stack_b);
	update_index(stack_a, stack_b);
	printer(stack_a, stack_b);
	while (!check(stack_b))
	{
		node = stack_b->top;

	}
	return (count);
}

int	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;
	int	nearly_sorted_a;

	i = 0;
	size = ft_lstsize(stack_a);
	if (size == 3)
	{
		i += short_sorting(stack_a, stack_b);
		printf("short sorting\n");
		printf ("%d\n", i);
		return (i);
	}
	nearly_sorted_a = nearly_sorted(stack_a);
	if (nearly_sorted_a != 0)
	{
		printf("nearly sorted\n");
		i += sorting_nearly(stack_a, stack_b,
				nearly_sorted_a, nearly_sorted(stack_b));
	}
	else
	{
		i += large_sorting(stack_a, stack_b);
		printf("large sorting\n");
		return (i);
	}
	return (i);
}
