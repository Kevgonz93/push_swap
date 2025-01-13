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

#ifndef SORTS_H
# define SORTS_H

# include "../types.h"
# include "../push_swap.h"

// NEARLY_SORT.C

int		nearly_sorted(t_stack *stack);
int		sorting_nearly(t_stack *stack_a, t_stack *stack_b,
			int nearly_a, int nearly_b);

// SHORT_SORTING.C

int		short_sorting(t_stack *stack_a, t_stack *stack_b);

// LARGE_SORT.C

int		large_sorting(t_stack *stack_a, t_stack *stack_b);

#endif