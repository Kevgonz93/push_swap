/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:16:09 by kegonzal          #+#    #+#             */
/*   Updated: 2024/11/30 19:16:12 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves/moves.h"

static void	initial_check(char *numbers[])
{
	int	i;
	int	j;

	i = 1;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			if (numbers[i][j] == '-' && j == 0)
				j++;
			if (!ft_isdigit(numbers[i][j]))
			{
				printf("Error: Just numbers please\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	if (is_repeat(numbers))
	{
		printf("Error: There are repeated numbers\n");
		exit(1);
	}
}

t_stack	*initial_set(char *numbers[])
{
	t_stack	*stack;
	t_node	*initial;
	t_node	*new;
	int		i;
	int		index;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	i = 1;
	initial = ft_lstnew(ft_atoi(numbers[i++]));
	if (!initial)
		return (free(stack), NULL);
	stack->top = initial;
	index = 1;
	while (numbers[i])
	{
		new = ft_lstnew(ft_atoi(numbers[i++]));
		new->index = index++;
		if (!new)
			return (free(stack), ft_lstclear(stack, del), NULL);
		ft_lstadd_back(stack, new);
	}
	return (stack);
}

static t_node	*pre_pinter(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		temp = NULL;
	else
		temp = stack->top;
	return (temp);
}

void	printer(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;

	if (ft_lstsize(stack_a) >= ft_lstsize(stack_b))
		i = ft_lstsize(stack_a);
	else
		i = ft_lstsize(stack_b);
	node_a = pre_pinter(stack_a);
	node_b = pre_pinter(stack_b);
	while (i--)
	{
		if (node_a)
		{
			printf("\t%d\t\t\t", node_a->value);
			node_a = node_a->next;
		}
		else
			printf("\t\t\t\t");
		if (node_b)
		{
			printf("\t%d\n", node_b->value);
			node_b = node_b->next;
		}
		else
			printf("\n");
	}
	printf("-----------------\t\t-----------------\n");
	printf("\tA\t\t\t\tB\n\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 0;
	if (argc == 1)
		return (printf("Error: Write the numbers to sort\n"));
	initial_check(argv);
	printf("initial check done\n");
	stack_a = initial_set(argv);
	stack_b = ft_calloc(1, sizeof(t_stack));
	printer(stack_a, stack_b);
	while (!check(stack_a))
	{
		printf("stack is not sorted\n");
		printf("searching for a solution\n");
		i += search_solution(stack_a, stack_b);
	}
	printf("stack is sorted with %d moves.\n", i);
	ft_lstclear(stack_a, del);
	free(stack_b);
	return (0);
}
