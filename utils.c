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
			if (ft_strlen(numbers[i]) == ft_strlen(numbers[j]) &&
			    !ft_strncmp(numbers[i], numbers[j], ft_strlen(numbers[i])))
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

int	nearly_sorted(t_stack *stack)
{
	t_node	*node;
	int		block;
	int		break_point;
	int		i;

	break_point = 0;
	block = 1;
	i = 1;
	node = stack->top;
	if (!node || !node->next)
		return (0);
	while (node->next)
	{
		if (node->value > node->next->value)
		{
			block++;
			break_point = i;
		}
		node = node->next;
		i++;
	}
	if (block == 2)
		return (break_point);
	else
		return (0);
}

int	move(t_stack *stack, char *move, char s)
{
	if (!ft_strncmp(move, "swap", 5))
	{
		swap(stack);
		if (s == 'a')
			return (printf("sa\n"));
		else
			return (printf("sb\n"));
	}
	else if (!ft_strncmp(move, "rotate", 7))
	{
		rotate(stack);
		if (s == 'a')
			return (printf("ra\n"));
		else
			return (printf("rb\n"));
	}
	else if (!ft_strncmp(move, "reverse", 8))
	{
		reverse(stack);
		if (s == 'a')
			return (printf("rra\n"));
		else
			return (printf("rrb\n"));
	}
	return (0);
}
