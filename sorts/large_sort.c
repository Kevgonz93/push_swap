/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:06:40 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:06:41 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorts.h"
#include "../push_swap.h"

static int	sorting_cost_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		count;
	int		step;

	count = 0;
	while (!check(stack_a))
	{
		printf("sorting cost a\n");
		printf("while loop\n");
		printer(stack_a, stack_b);
		while (ft_lstsize(stack_a) > 3)
		{
			step = 0;
			printf(">>>>>>>>>>>>>>>>>>>> NEXT MOVE\n");
			update_index(stack_a, stack_b);
			printf("updated index\n");
			update_cost(stack_a, stack_b, 'a');
			printf("updated cost of A\n");
			node = lower_cost(stack_a);
			printf("lower cost : %d \n", node->value);
			printf("%d\n", node->index);
			if (node->index != 0)
			{
				printf("moving to top\n");
				step += move_to_top(stack_a, node->index, 'a');
			}
			printf("steps with move to top: %d\n", step);
			printf("move to top\n");
			step += pb(stack_a, stack_b);
			printf("steps with move to other stack: %d\n", step);
			printf("pb done\n");
			printer(stack_a, stack_b);
			if (!check(stack_b))
				step += sort_stack(stack_a, stack_b, 'b');
			printf("steps with sort_stack: %d\n", step);
			printer(stack_a, stack_b);
			count += step;
		}
		count += short_sorting(stack_a);
		printf("short sorting in sorting cost a done\n");
	}
	return (count);
}

static int	sorting_cost_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		count;

	count = 0;
	printf("sorting cost b\n");
	while (stack_b->top)
	{
		printf("while loop\n");
		if (ft_lstsize(stack_b) > 1)
		{
			update_cost(stack_a, stack_b, 'b');
			printf("updated cost of B\n");
			printer(stack_a, stack_b);
			node = lower_cost(stack_b);
			printf("lower cost\n");
			count += move_to_top(stack_b, node->index, 'b');
			printf("count with move to top: %d\n", count);
			printf("move to top\n");
		}
		count += pa(stack_a, stack_b);
		printf("count with move to other stack: %d\n", count);
		printer(stack_a, stack_b);
		printf("pa done\n");
		count += sort_stack(stack_a, stack_b, 'a');
		printf("count with sort_stack: %d\n", count);
	}
	return (count);
}

static int	first_half(t_stack *stack_a, int index)
{
	int	count;
	int	nearly_sorted;

	count = 0;
	nearly_sorted = is_nearly(stack_a);
	printf("nearly_sorted: %d\n", nearly_sorted);
	printf("first half\n");
	if (index == 1)
	{
		swap(stack_a);
		print_temp(stack_a);
		count++;
	}
	while (!check(stack_a))
	{
		if (nearly_sorted != 0 && stack_a->top->value > ft_lstlast(stack_a)->value)
			count += nearly_sort(stack_a, nearly_sorted);
		else
		{
			reverse(stack_a);
			print_temp(stack_a);
			count++;
		}
		if (check(stack_a))
			break ;
		nearly_sorted = is_nearly(stack_a);
		printf("nearly_sorted: %d\n", nearly_sorted);
		if (nearly_sorted != 0 && stack_a->top->value > ft_lstlast(stack_a)->value)
			count += nearly_sort(stack_a, nearly_sorted);
		else
		{
			swap(stack_a);
			print_temp(stack_a);
			count++;
		}
	}
	return (count);
}

static int	second_half(t_stack *stack_a)
{
	int	count;
	int	nearly_sorted;

	count = 0;
	nearly_sorted = is_nearly(stack_a);
	printf("nearly_sorted: %d\n", nearly_sorted);
	printf("second half\n");
	while (!check(stack_a))
	{
		if (nearly_sorted != 0 && stack_a->top->value > ft_lstlast(stack_a)->value)
			count += nearly_sort(stack_a, nearly_sorted);
		else
		{
			reverse(stack_a);
			print_temp(stack_a);
			count++;
		}
		if (check(stack_a))
			break ;
		nearly_sorted = is_nearly(stack_a);
		printf("nearly_sorted: %d\n", nearly_sorted);
		if (nearly_sorted != 0 && stack_a->top->value > ft_lstlast(stack_a)->value)
			count += nearly_sort(stack_a, nearly_sorted);
		else
		{
			swap(stack_a);
			print_temp(stack_a);
			count++;
		}
	}
	print_temp(stack_a);
	return (count);
}

int	large_sorting(t_stack *stack_a)
{
	int	*solution;
	int	count;
	int	size;
	int	index;
	int	nearly;

	printf("large sorting\n");
	nearly = is_nearly(stack_a);
	printf("nearly: %d\n", nearly);
	if (nearly != 0 && stack_a->top->value > ft_lstlast(stack_a)->value)
	{
		printf("nearly sorting\n");
		return (nearly_sort(stack_a, nearly));
	}
	solution = get_solution(stack_a);
	count = 0;
	size = ft_lstsize(stack_a);
	index = search_index(stack_a->top->value, solution);
	if (index <= size / 2)
	{
		count += first_half(stack_a, index);
		printf("first half done\n");
	}
	else
	{
		count += second_half(stack_a);
		printf("second half done\n");
	}
	return (count);
}

int	large_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	int		nearly_sorted_a;

	count = 0;
	count += moving_to_b(stack_a, stack_b);
	printf("moving to b done\n");
	printf("%d\n", count);
	nearly_sorted_a = is_nearly(stack_a);
	while (!check(stack_a) || stack_b->top)
	{
		if (nearly_sorted_a != 0)
			count += nearly_sort(stack_a, nearly_sorted_a);
		else
		{
			while (ft_lstsize(stack_a) > 3 && nearly_sorted_a == 0)
				count += sorting_cost_a(stack_a, stack_b);
		}
		count += short_sorting(stack_a);
		printf("short sorting in large sorting done\n");
		count += sorting_cost_b(stack_a, stack_b);
		printf("sorting cost b done\n");
	}
	return (count);
}
