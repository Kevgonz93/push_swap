/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:08:28 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:08:30 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "aux/libft.h"
# include "moves/moves.h"
# include "sorts/sorts.h"
# include "types.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//  MAIN.C

t_stack	*initial_set(char *numbers[]);
void	printer(t_stack *stack_a, t_stack *stack_b);

// UTILS.C

void	del(int content);
void	print_temp(t_stack *temp);
int		moving_to_b(t_stack *stack_a, t_stack *stack_b);
int		same_moving(t_stack *stack_a, t_stack *stack_b, char *move_a);
int		moving(t_stack *stack, char *move, char s);

// CHECKS.C

int		is_repeat(char *nusmbers[]);
int		check(t_stack *stack);

// SOLUTION.C

int		sort_stack(t_stack *stacka, t_stack *stack_b, char c);
int		*get_solution(t_stack *stack);
int		search_index(int node, int *solution);
char	*next_move(t_stack *stack);
int		move_to_top(t_stack *stack_a, int index, char c);
int		search_solution(t_stack *stack_a, t_stack *stack_b);

// COST.C

t_node	*lower_cost(t_stack *stack);
void	update_index(t_stack *stack_a, t_stack *stack_b);
int		get_cost(t_stack *stack_a, t_stack *stack_b, t_node *node, char c);
void	update_cost(t_stack *stack_a, t_stack *stack_b, char c);

#endif
