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

#ifndef MOVES_H
# define MOVES_H

# include "../types.h"
# include "../push_swap.h"

// SWAP

void	swap(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);

// ROTATE

void	rotate(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);

// REVERSE

void	reverse(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// PUSH

int		pa(t_stack *stack_a, t_stack *stack_b);
int		pb(t_stack *stack_a, t_stack *stack_b);

#endif