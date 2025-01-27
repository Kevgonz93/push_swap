#include "sort.h"

void	pre_push(t_stack *stack, t_node *top_target, char c)
{
	while (stack->top != top_target)
	{
		if (c == 'a')
		{
			if (top_target->second_half)
				rra(stack, true);
			else
				ra(stack, true);
		}
		else if (c == 'b')
		{
			if (top_target->second_half)
				rrb(stack, true);
			else
				rb(stack, true);
		}
	}
}

int	count_to_top(t_stack *stack, t_node *node)
{
	int		count;

	if (node->index > stack->size / 2)
		count = stack->size - node->index;
	else
		count = node->index;
	return (count);
}

void	update_cost_a(t_stack *stack_init, t_stack *stack_last)
{
	t_node	*node;
	int		size_a;
	int		size_b;

	size_a = stack_init->size;
	size_b = stack_last->size;
	node = stack_init->top;
	while (node)
	{
		node->cost_push = node->index;
		if (node->second_half)
			node->cost_push = size_a - node->index;
		if (!node->target->second_half)
			node->cost_push += node->target->index;
		else
			node->cost_push += size_b - node->target->index;
		node = node->next;
	}
}

void	update_index(t_stack *stack)
{
	t_node	*node;
	int		i;
	int		mid;

	i = 0;
	mid = ft_lstsize(stack) / 2;
	node = stack->top;
	while (node)
	{
		node->index = i;
		if (i <= mid)
			node->second_half = false;
		else
			node->second_half = true;
		node = node->next;
		i++;
	}
}

void	update_size(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	t_node	*node_b;

	node_a = stack_a->top;
	node_b = stack_b->top;
	stack_a->size = 0;
	stack_b->size = 0;
	while (node_a)
	{
		stack_a->size++;
		node_a = node_a->next;
	}
	while (node_b)
	{
		stack_b->size++;
		node_b = node_b->next;
	}
}

void	update_targets_a(t_stack *stack_ini, t_stack *stack_last)
{
	t_node	*node;
	t_node	*current;
	t_node	*target;
	long	best;

	if (!stack_last->top)
		return ;
	node = stack_ini->top;
	while (node)
	{
		best = LONG_MIN;
		current = stack_last->top;
		while (current)
		{
			if (current->value < node->value && current->value > best)
			{
				best = current->value;
				target = current;
			}
			current = current->next;
		}
		if (best == LONG_MIN)
			node->target = max_value(stack_last);
		else
			node->target = target;
		node = node->next;
	}
}

void	update_targets_b(t_stack *stack_ini, t_stack *stack_last)
{
	t_node	*node;
	t_node	*current;
	t_node	*target;
	long	best;

	node = stack_ini->top;
	while (node)
	{
		best = LONG_MAX;
		current = stack_last->top;
		while (current)
		{
			if (current->value > node->value && current->value < best)
			{
				best = current->value;
				target = current;
			}
			current = current->next;
		}
		if (best == LONG_MAX)
			node->target = min_value(stack_last);
		else
			node->target = target;
		node = node->next;
	}
}

void	update_cheapest(t_stack *stack)
{
	long	value;
	t_node	*cheapest;
	t_node	*node;

	if (!stack->top)
		return ;
	value = LONG_MAX;
	node = stack->top;
	while (node)
	{
		if (node->cost_push < value)
		{
			value = node->cost_push;
			cheapest = node;
		}
		node = node->next;
	}
	cheapest->cheapest = true;
}

void	update_target_stack(t_stack *stack_a, t_stack *stack_b)
{
	update_targets_a(stack_a, stack_b);
	if (stack_b->top)
		update_targets_b(stack_b, stack_a);
}

void	update_stack(t_stack *stack_a, t_stack *stack_b)
{
	update_index(stack_a);
	if (stack_b->top)
	{
		update_index(stack_b);
	}
	update_size(stack_a, stack_b);
	update_target_stack(stack_a, stack_b);
	update_cost_a(stack_a, stack_b);
	update_cheapest(stack_a);
	if (stack_b->top)
	{
		update_cheapest(stack_b);
	}
}
