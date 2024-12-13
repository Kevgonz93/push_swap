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
int		nearly_sorted(t_stack *stack);
char	*move_nearly(t_stack *stack, int nearly);
int		move(t_stack *stack, char *move, char s);
int		sorting_nearly(t_stack *stack_a,
			t_stack *stack_b, int nearly_a, int nearly_b);
char	*next_nearly(t_stack *stack, int nearly);

// SOLUTION.C

int		same_move(t_stack *stack_a, t_stack *stack_b, char *move_a);
int		search_solution(t_stack *stack_a, t_stack *stack_b);

// MOVES

void	swap(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

#endif
