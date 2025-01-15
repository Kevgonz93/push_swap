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

static char	**mid_low_high(void)
{
	char	**move;

	move = ft_calloc(3, sizeof(char *));
	move[0] = ft_strdup("swap");
	move[1] = NULL;
	move[2] = NULL;
	return (move);
}

static char	**mid_high_low(void)
{
	char	**move;

	move = ft_calloc(3, sizeof(char *));
	move[0] = ft_strdup("reverse");
	move[1] = NULL;
	move[2] = NULL;
	return (move);
}

static char	**high_low_mid(void)
{
	char	**move;

	move = ft_calloc(3, sizeof(char *));
	move[0] = ft_strdup("rotate");
	move[1] = NULL;
	move[2] = NULL;
	return (move);
}

static char	**next_shorting(t_stack *stack_a)
{
	int		top;
	int		mid;
	int		bottom;
	char	**move;

	top = stack_a->top->value;
	mid = stack_a->top->next->value;
	bottom = ft_lstlast(stack_a)->value;
	if (top > mid && mid < bottom && top > bottom)
		move = high_low_mid();
	else if (top > bottom && top > mid && mid > bottom)
	{
		move = high_low_mid();
		move[1] = ft_strdup("swap");
	}
	else if (top < mid && top > bottom && mid > bottom)
		move = mid_high_low();
	else if (top < mid && top < bottom && mid > bottom)
	{
		move = mid_low_high();
		move[1] = ft_strdup("rotate");
	}
	else
		move = mid_low_high();
	return (move);
}

int	short_sorting(t_stack *stack_a)
{
	char	**move_a;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!check(stack_a))
		move_a = next_shorting(stack_a);
	else
		return (0);
	while (move_a[i] != NULL)
	{
		count += moving(stack_a, move_a[i], 'a');
		i++;
	}
	return (count);
}
