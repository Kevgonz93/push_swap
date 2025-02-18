#ifndef TYPES_H
# define TYPES_H

# include "checker.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_moves
{
	char			*move;
	struct s_moves	*next;
}	t_moves;

#endif
