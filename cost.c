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

#include "push_swap.h"
#include "moves/moves.h"

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

void	update_index(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack_a->top;
	while (node)
	{
		node->index = i++;
		node = node->next;
	}
	i = 0;
	node = stack_b->top;
	while (node)
	{
		node->index = i++;
		node = node->next;
	}
}

static t_stack	*temp_stack(t_stack *stack, int initial)
{
	t_stack	*temp;
	t_node	*node;
	t_node	*new_node;

	if (!stack)
		return (NULL);
	temp = ft_calloc(1, sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->top = ft_lstnew(initial);
	if (!temp->top)
		return (ft_lstclear(temp, del), NULL);
	node = stack->top;
	while (node)
	{
		new_node = ft_lstnew(node->value);
		if (!new_node)
			return (ft_lstclear(temp, del), NULL);
		ft_lstadd_back(temp, new_node);
		node = node->next;
	}
	return (temp);
}

static int	sortin_temp(t_stack *temp)
{
	int		count;

	if (!temp || !temp->top || !temp->top->next)
		return (0);
	count = 0;
	while (!check(temp))
	{
		if (ft_lstsize(temp) == 3)
			count += short_sorting(temp);
		else
			count += large_sorting(temp);
	}
	return (count);
}

static int	moves_to_top(t_stack *stack, int index)
{
	int	size;

	size = ft_lstsize(stack);
	if (index == 0)
		return (0);
	if (index <= size / 2)
		return (index);
	return (size - index);
}

int	get_cost(t_stack *stack_a, t_stack *stack_b, t_node *node, char c)
{
	t_stack	*temp;
	int		cost;

	cost = 0;
	if (!stack_a || !stack_a->top)
		return (0);
	if (c == 'a')
	{
		printf(" >>>>>> getting cost of %d\n", node->value);
		cost += moves_to_top(stack_a, node->index);
		printf("cost for move to top: %d\n", cost);
		cost++;
		printf("cost for move to other stack: %d\n", cost);
		temp = temp_stack(stack_b, node->value);
		printf("temp stack created\n");
		print_temp(temp);
		cost += sortin_temp(temp);
		printf("cost for sort in temp stack: %d\n", cost);
	}
	else
	{
		printf("getting cost of %d\n", node->value);
		cost += moves_to_top(stack_b, node->index);
		printf("cost for move to top: %d\n", cost);
		cost++;
		printf("cost for move to other stack: %d\n", cost);
		temp = temp_stack(stack_a, node->value);
		printf("temp stack created\n");
		print_temp(temp);
		cost += sortin_temp(temp);
		printf("cost for sort in temp stack: %d\n", cost);
	}
	printf(">>>>> the cost of %d: %d\n", node->value, cost);
	return (ft_lstclear(temp, del), free(temp), cost);
}

void	update_cost(t_stack *stack_a, t_stack *stack_b, char c)
{
	t_node	*node;

	printf("------- updating cost -------\n");
	if (c == 'a')
		node = stack_a->top;
	else
		node = stack_b->top;
	while (node)
	{
		update_index(stack_a, stack_b);
		printf("index updated\n");
		node->cost = get_cost(stack_a, stack_b, node, c);
		printf("cost updated\n");
		node = node->next;
	}
	printf("------- cost updated -------\n");
	printer(stack_a, stack_b);
}
