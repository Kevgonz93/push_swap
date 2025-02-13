/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:59:52 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:59:53 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "aux/libft.h"
# include "moves/moves.h"
# include "sorts/sort.h"
# include "src/types.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

// INITIAL_SETTINGS.C
t_stack	*stack_init(char **nbrs);

// UTILS.C
t_node	*min_value(t_stack *stack);
t_node	*max_value(t_stack *stack);
t_node	*min_cost(t_stack *stack);

// CHECKERS.C
int		check_data(char *str);
int		check_duplicates(t_stack *stack);
int		check_sorted(t_stack *stack, char c);

// PRINTERS

void	print_node_values(t_node *node);
void	print_stack_values(t_stack *stack);
void	printer(t_stack *stack_a, t_stack *stack_b);

#endif
