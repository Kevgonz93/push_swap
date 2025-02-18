#include "checker.h"

int	main(int argc, char **argv)
{
	char	**moves;
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	args = get_args(argc, argv);
	if (!args)
		return (0);
	stack_a = init_stack(argc, args);
	free_matrix(args);
	moves = get_moves();
	check_moves(moves, stack_a);
	stack_b = malloc(sizeof(t_stack));
	make_moves(moves, stack_a, stack_b);
	if (is_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_matrix(moves);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
