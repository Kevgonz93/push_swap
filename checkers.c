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
			if (ft_strlen(numbers[i]) == ft_strlen(numbers[j])
				&& !ft_strncmp(numbers[i], numbers[j], ft_strlen(numbers[i])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (!node || !node->next)
		return (1);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}
