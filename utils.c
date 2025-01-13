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
#include "moves/moves.h"

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

int	same_move(t_stack *stack_a, t_stack *stack_b, char *move_a)
{
	if (!ft_strncmp(move_a, "rotate", 7))
	{
		rr(stack_a, stack_b);
		return (printf("\n"), printer(stack_a, stack_b), 1);
	}
	else if (!ft_strncmp(move_a, "reverse", 8))
	{
		rrr(stack_a, stack_b);
		return (printf("\n"), printer(stack_a, stack_b), 1);
	}
	else
	{
		ss(stack_a, stack_b);
		return (printf("\n"), printer(stack_a, stack_b), 1);
	}
}

int	moving(t_stack *stack, char *move, char s)
{
	if (!ft_strncmp(move, "swap", 5))
	{
		swap(stack);
		if (s == 'a')
		{
			printf("sa\n");
			return (1);
		}
		else if (s == 'b')
		{
			printf("sb\n");
			return (1);
		}
		else
			return (1);
	}
	else if (!ft_strncmp(move, "rotate", 7))
	{
		rotate(stack);
		if (s == 'a')
		{
			printf("ra\n");
			return (1);
		}
		else if (s == 'b')
		{
			printf("rb\n");
			return (1);
		}
		else
			return (1);
	}
	else if (!ft_strncmp(move, "reverse", 8))
	{
		reverse(stack);
		if (s == 'a')
		{
			printf("rra\n");
			return (1);
		}
		else if (s == 'b')
		{
			printf("rrb\n");
			return (1);
		}
		else
			return (1);
	}
	else
		return (0);
}
