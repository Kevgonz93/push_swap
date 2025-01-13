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
#include "sorts/sorts.h"

int	moving_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(stack_a);
	while (i < 2 && size != 3)
	{
		pb(stack_a, stack_b);
		printer(stack_a, stack_b);
		i++;
		size = ft_lstsize(stack_a);
	}
	return (i);
}

void	del(int content)
{
	if (content)
		(void)content;
	return ;
}

int	same_moving(t_stack *stack_a, t_stack *stack_b, char *move_a)
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

static void	aux_moving(char *move, char c)
{
	if (c == 'a')
	{
		if (!ft_strncmp(move, "swap", 5))
			printf("sa\n");
		else if (!ft_strncmp(move, "rotate", 7))
			printf("ra\n");
		else
			printf("rra\n");
	}
	else
	{
		if (!ft_strncmp(move, "swap", 5))
			printf("sb\n");
		else if (!ft_strncmp(move, "rotate", 7))
			printf("rb\n");
		else
			printf("rrb\n");
	}
}

int	moving(t_stack *stack, char *move, char s)
{
	if (!ft_strncmp(move, "swap", 5))
		swap(stack);
	else if (!ft_strncmp(move, "rotate", 7))
		rotate(stack);
	else if (!ft_strncmp(move, "reverse", 8))
		reverse(stack);
	else if (!ft_strncmp(move, "nothing", 5))
		return (0);
	aux_moving(move, s);
	return (1);
}
