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

// UTILS.C

int		is_repeat(char *nusmbers[]);
void	del(int content);
int		check(t_stack *stack);
void	move(t_stack *stack, char *move, char s);

// SOLUTION.C

void	search_solution(t_stack *stack_a, t_stack *stack_b);

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
