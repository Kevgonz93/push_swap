#include "sort.h"

void	moving_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	cheapest = min_cost(stack_a);
<<<<<<< HEAD
	if (!cheapest->second_half && !cheapest->target->second_half)
		doble_rotate(stack_a, stack_b, cheapest);
	else if (cheapest->second_half && cheapest->target->second_half)
=======
	if (cheapest->index == cheapest->target->index)
	{
		if (!cheapest->second_half)
			doble_rotate(stack_a, stack_b, cheapest);
		else
			doble_reverse(stack_a, stack_b, cheapest);
	}
	else if (cheapest->second_half && cheapest->target->second_half)
		doble_rotate(stack_a, stack_b, cheapest);
	else if (!(cheapest->second_half))
>>>>>>> refs/remotes/origin/main
		doble_reverse(stack_a, stack_b, cheapest);
	pre_push(stack_a, cheapest, 'a');
	pre_push(stack_b, cheapest->target, 'b');
	pb(stack_a, stack_b, true);
<<<<<<< HEAD
=======
	printer(stack_a, stack_b);
>>>>>>> refs/remotes/origin/main
}

void	moving_to_a(t_stack *stack_a, t_stack *stack_b)
{
	pre_push(stack_a, stack_b->top->target, 'a');
	pa(stack_a, stack_b, true);
}

void	move_to_top(t_stack *stack)
{
	t_node	*node;

	node = min_value(stack);
	while (stack->top != node)
	{
		if (node->second_half)
			rra(stack, true);
		else
			ra(stack, true);
	}
}

void	init_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_a->size > 3 && i < 2 && !check_sorted(stack_a, 'a'))
	{
		pb(stack_a, stack_b, true);
		stack_a->size--;
		i++;
<<<<<<< HEAD
=======
		printer(stack_a, stack_b);
>>>>>>> refs/remotes/origin/main
	}
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
<<<<<<< HEAD
=======
	update_index(stack_a);
	update_size(stack_a, stack_b);
>>>>>>> refs/remotes/origin/main
	init_b(stack_a, stack_b);
	while (stack_a->size > 3 && !check_sorted(stack_a, 'a'))
	{
		update_stack(stack_a, stack_b);
		moving_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->top)
	{
		update_stack(stack_a, stack_b);
		moving_to_a(stack_a, stack_b);
	}
<<<<<<< HEAD
	update_stack(stack_a, stack_b);
=======
	update_index(stack_a);
>>>>>>> refs/remotes/origin/main
	move_to_top(stack_a);
}
