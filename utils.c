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
		// return (printf("blocks: %d\n", block), printf("the break point is: %d\n", break_point) ,break_point);
	else
		return (0);
}

char	*next_nearly(t_stack *stack, int nearly)
{
	if (nearly == 0)
		return ("nothing");
	else if (nearly >= ft_lstsize(stack) / 2)
		return ("reverse");
	else
		return ("rotate");
}

int	sorting_nearly(t_stack *stack_a, t_stack *stack_b, int nearly_a, int nearly_b)
{
	char	*move_a;
	char	*move_b;
	int		i;

	i = 0;
	while (nearly_a != 0 || nearly_b != 0)
	{
		move_a = next_nearly(stack_a, nearly_a);
		printf("move_a: %s\n", move_a);
		move_b = next_nearly(stack_b, nearly_b);
		printf("move_b: %s\n", move_b);
		while (i < nearly_a && i < nearly_b)
		{
			printf("i: %d\n", i);
			if (ft_strncmp(move_a, move_b, 7))
				i += same_move(stack_a, stack_b, move_a);
			else
			{
				i += move(stack_a, move_a, 'a');
				i += move(stack_b, move_b, 'b');
			}
		}
		if (i < nearly_a)
		{
			while (i < nearly_a)
				i += move(stack_a, move_a, 'a');
		}
		else if (i < nearly_b)
		{
			while (i < nearly_b)
				i += move(stack_b, move_b, 'b');
		}
		return (i);
	}
	return (0);
}

int	same_move(t_stack *stack_a, t_stack *stack_b, char *move_a)
{
	if (!ft_strncmp(move_a, "rotate", 7))
	{
		rr(stack_a, stack_b);
		return (printer(stack_a, stack_b), 1);
	}
	else if (!ft_strncmp(move_a, "reverse", 8))
	{
		rrr(stack_a, stack_b);
		return (printer(stack_a, stack_b), 1);
	}
	else
	{
		ss(stack_a, stack_b);
		return (printer(stack_a, stack_b), 1);
	}
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
