#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "aux/libft.h"
# include "types.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

t_stack	*initial_set(char *numbers[]);

int		check(t_stack *stack_a, t_stack *stack_b);
void	del(int content);
int		is_repeat(char *numbers[]);

// MOVES
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	move(t_stack *stack_a, t_stack *stack_b, char *move);
void    search_solution(t_stack *stack_a, t_stack *stack_b);

#endif
