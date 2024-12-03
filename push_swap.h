#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "aux/libft.h"
# include "types.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


t_stack	*initial_set(char *numbers[]);
int		initial_check(char *stack, int size);
int		check(char *stack, int size);
void	del(int content);


#endif
