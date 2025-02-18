#ifndef CHECKER_H
# define CHECKER_H

# include "types.h"
# include "moves/moves.h"
# include "aux/aux.h"
# include "gnl/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// MAIN.C

t_stack	*init_stack(int argc, char **args);
char	**get_args(int argc, char **argv);
char	**get_moves(void);

// UTILS

t_node	*ft_new_node(int data);
t_stack	*ft_new_stack(void);
void	free_matrix(char **matrix);
void	free_stack(t_stack *stack);

// CHECKER.C

int		is_sorted(t_stack *stack);

#endif
