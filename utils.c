/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:09:46 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:09:47 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_repeat(char *numbers[])
{
	int	i;
	int	j;

	i = 1;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (!ft_strncmp(numbers[i], numbers[j], ft_strlen(numbers[i])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	del(int content)
{
	if (content)
		(void)content;
	return ;
}

int	check(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_a->top;
	if (!node)
		return (0);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	if (stack_b->top)
		return (0);
	return (1);
}

void	move(t_stack *stack, char *move)
{
	if (!ft_strncmp(move, "swap", 5))
		swap(stack);
	else if (!ft_strncmp(move, "rotate", 7))
		rotate(stack);
	else
		reverse(stack);
}
