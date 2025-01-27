#ifndef SORT_H
# define SORT_H

# include "../aux/libft.h"
# include "../moves/moves.h"
# include "../types.h"
# include "../push_swap.h"

// SHORT SORT

void	sort_three(t_stack *stack);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);

// LARGE SORT

void	init_b(t_stack *stack_a, t_stack *stack_b);
void	move_to_top(t_stack *stack);
void	moving_to_a(t_stack *stack_a, t_stack *stack_b);
void	moving_to_b(t_stack *stack_a, t_stack *stack_b);

// UTILS


void	pre_push(t_stack *stack, t_node *top_target, char c);
void	update_stack(t_stack *stack_a, t_stack *stack_b);
void	update_index(t_stack *stack_a);
void	update_size(t_stack *stack_a, t_stack *stack_b);
void	update_cost(t_stack *stack_init, t_stack *stack_last);
void	update_target_node(t_stack *stack_a, t_stack *stack_b);
void	update_target_stack(t_stack *stack_a, t_stack *stack_b);

#endif
