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

int	search_index(int node, int *solution)
{
	int		i;

	i = 0;
	while (node)
	{
		if (node == solution[i])
			return (i);
		i++;
	}
	return (0);
}

int	sort_stack(t_stack *stack_a, t_stack *stack_b, char c)
{
	int	count;

	count = 0;
	update_index(stack_a, stack_b);
	if (c == 'a')
	{
		printf("sorting a\n");
		if (ft_lstsize(stack_a) == 3)
			count += short_sorting(stack_a);
		else
			count += large_sorting(stack_a);
	}
	else
	{
		printf("sorting b\n");
		if (ft_lstsize(stack_b) == 3)
			count += short_sorting(stack_b);
		else
			count += large_sorting(stack_b);
	}
	return (count);
}

char	*next_move(t_stack *stack)
{
	int		node;
	int		bottom;
	int		*solution;
	int		index;
	int		size;

	node = stack->top->value;
	solution = get_solution(stack);
	index = search_index(node, solution);
	size = ft_lstsize(stack);
	printf("index: %d\n", index);
	printf("size of stack: %d\n", size);
	bottom = ft_lstlast(stack)->value;
	if (!stack->top || !stack->top->next || check(stack) == 1)
		return (free(solution), "nothing");
	if (node > bottom || index > size / 2)
		return (free(solution), "rotate");
	else if (index <= size / 2 && node > stack->top->next->value)
		return (free(solution), "swap");
	return (free(solution), "reverse");
}

int	move_to_top(t_stack *stack, int index, char c)
{
	int	count;
	int	size;

	count = 0;
	size = ft_lstsize(stack);
	printf("moving to top\n");
	printf("index: %d\n", index);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			if (c == 'a')
				printf("ra\n");
			else
				printf("rb\n");
			rotate(stack);
			count++;
			index--;
		}
	}
	else
	{
		while (index < size)
		{
			if (c == 'a')
				printf("rra\n");
			else
				printf("rrb\n");
			reverse(stack);
			count++;
			index++;
		}
	}
	return (count);
}

int	search_solution(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	size;
	int	nearly_sorted_a;

	count = 0;
	size = ft_lstsize(stack_a);
	nearly_sorted_a = is_nearly(stack_a);
	if (size == 3)
	{
		printf("short sorting\n");
		count += short_sorting(stack_a);
	}
	else if (nearly_sorted_a != 0)
	{
		printf("nearly sorted\n");
		count += nearly_sort(stack_a, nearly_sorted_a);
	}
	else
	{
		printf("large sorting\n");
		count += large_sort(stack_a, stack_b);
	}
	return (count);
}
