/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:56:54 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:56:56 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "../aux/libft.h"
# include "../moves/moves.h"
# include "../src/types.h"
# include "../push_swap.h"

// SHORT SORT.C

void	sort_three(t_stack *stack);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);

// LARGE SORT.C

void	init_b(t_stack *stack_a, t_stack *stack_b);
void	move_to_top(t_stack *stack);
void	moving_to_a(t_stack *stack_a, t_stack *stack_b);
void	moving_to_b(t_stack *stack_a, t_stack *stack_b);

// SORT_UTILS.C

void	pre_push(t_stack *stack, t_node *top_target, char c);
void	update_target_stack(t_stack *stack_a, t_stack *stack_b);
void	update_stack(t_stack *stack_a, t_stack *stack_b);

// UPDATE.C

void	update_index(t_stack *stack);
void	update_size(t_stack *stack_a, t_stack *stack_b);

// COST.C

void	update_cost_a(t_stack *stack_init, t_stack *stack_last);
void	update_cheapest(t_stack *stack_a);

// TARGET.C

void	update_targets_a(t_stack *stack_ini, t_stack *stack_last);
void	update_targets_b(t_stack *stack_ini, t_stack *stack_last);

#endif
