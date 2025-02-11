#ifndef TYPES_H
# define TYPES_H

#include "../push_swap.h"
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost_push;
	bool			second_half;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

#endif