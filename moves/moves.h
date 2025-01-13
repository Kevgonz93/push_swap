#ifndef MOVES_H
# define MOVES_H

# include "../types.h"
# include "../push_swap.h"
# include "../aux/libft.h"

// MOVES

void	swap(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
int		is_swap(t_stack *stack, int *solution, int size);
void	rotate(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
int		is_rotate(t_stack *stack, int *solution, int size);
void	reverse(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
int		is_reverse(t_stack *stack, int *solution, int size);
int     pa(t_stack *stack_a, t_stack *stack_b);
int     pb(t_stack *stack_a, t_stack *stack_b);

#endif