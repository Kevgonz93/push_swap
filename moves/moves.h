#ifndef MOVES_H
# define MOVES_H

# include "../push_swap.h"
# include "../aux/libft.h"
# include "../types.h"

// SWAP

void	swap(t_stack *stack);
void	sa(t_stack *stack, bool print);
void	sb(t_stack *stack, bool print);
void	ss(t_stack *stack_a, t_stack *stack_b, bool print);

// ROTATE

void	rotate(t_stack *stack);
void	ra(t_stack *stack, bool print);
void	rb(t_stack *stack, bool print);
void	rr(t_stack *stack_a, t_stack *stack_b, bool print);
void	doble_rotate(t_stack *stack_a, t_stack *stack_b, t_node *cheapest);

// REVERSE

void	reverse(t_stack *stack);
void	rra(t_stack *stack, bool print);
void	rrb(t_stack *stack, bool print);
void	rrr(t_stack *stack_a, t_stack *stack_b, bool print);
void	doble_reverse(t_stack *stack_a, t_stack *stack_b, t_node *cheapest);

// PUSH

void	pb(t_stack *stack_a, t_stack *stack_b, bool print);
void	pa(t_stack *stack_a, t_stack *stack_b, bool print);

#endif
