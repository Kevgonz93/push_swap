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

int		is_nearly(t_stack *stack);
int		nearly_sort(t_stack *stack_a, int nearly_a);

// SHORT_SORTING.C

int		short_sorting(t_stack *stack_a);

// LARGE_SORT.C

int		large_sorting(t_stack *stack_a);
int		large_sort(t_stack *stack_a, t_stack *stack_b);

#endif