#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "aux/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

t_stack	*initial_set(char *argv[]);
int	initial_check(char *stack, int size);
int	check(char *stack, int size);


#endif
