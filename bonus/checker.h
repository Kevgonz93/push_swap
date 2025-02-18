#ifndef CHECKER_H
# define CHECKER_H

# include "src/types.h"
# include "moves/moves.h"
# include "aux/aux.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// INITIAL SETTINGS

t_stack	*init_stack(int argc, char **args);
char	**get_args(int argc, char **argv);
char	**get_moves(void);

// UTILS

void	make_moves(char **moves, t_stack *stack_a, t_stack *stack_b);
void	free_matrix(char **matrix);
void	free_stack(t_stack *stack);

// CHECKER.C

int		is_sorted(t_stack *stack);

void	printer(t_stack *stack_a, t_stack *stack_b);

#endif
