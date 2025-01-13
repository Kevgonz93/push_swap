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

int	large_sorting(t_stack *stack_a, t_stack *stack_b)
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

