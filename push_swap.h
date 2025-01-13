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
# include "types.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//  MAIN.C

t_stack	*initial_set(char *numbers[]);
void	printer(t_stack *stack_a, t_stack *stack_b);

// UTILS.C

int		is_repeat(char *nusmbers[]);
void	del(int content);
int		check(t_stack *stack);
int		moving(t_stack *stack, char *move, char s);

// SOLUTION.C

int		same_move(t_stack *stack_a, t_stack *stack_b, char *move_a);
int		search_solution(t_stack *stack_a, t_stack *stack_b);
int		*get_solution(t_stack *stack);
int		position(int value, int *solution, int size);
int		move_to_top(t_stack *stack, int index, t_stack *stack_b);
char	*next_move(t_stack *stack);

// COST.C

void	update_index(t_stack *stack_a, t_stack *stack_b);
int		get_cost(t_stack *stack_a, t_stack *stack_b);
void	update_cost(t_stack *stack_a, t_stack *stack_b);

// SHORT_SORTING.C

int		short_sorting(t_stack *stack_a, t_stack *stack_b);

// NEARLY_SORT.C

int		nearly_sorted(t_stack *stack);
int		sorting_nearly(t_stack *stack_a, t_stack *stack_b, int nearly_a, int nearly_b);

#endif
