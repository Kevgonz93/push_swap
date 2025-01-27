#include "push_swap.h"

void	print_node_values(t_node *node)
{
	printf("--------------------\n");
	printf("node:\n");
	printf("value: %d\n", node->value);
	printf("index: %d\n", node->index);
	printf("cost_push: %d\n", node->cost_push);
	printf("second_half: %d\n", node->second_half);
	printf("cheapest: %d\n", node->cheapest);
	if (node->target)
		printf("target: %d\n", node->target->value);
	if (node->next)
		printf("next: %d\n", node->next->value);
	if (node->prev)
		printf("prev: %d\n", node->prev->value);
	printf("--------------------\n");
}

void	print_stack_values(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node)
	{
		print_node_values(node);
		node = node->next;
	}
}

static t_node	*pre_pinter(t_stack *stack)
{
	t_node	*temp;

	if (!stack)
		temp = NULL;
	else
		temp = stack->top;
	return (temp);
}

void	printer(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;

	if (ft_lstsize(stack_a) >= ft_lstsize(stack_b))
		i = ft_lstsize(stack_a);
	else
		i = ft_lstsize(stack_b);
	node_a = pre_pinter(stack_a);
	node_b = pre_pinter(stack_b);
	update_index(stack_a);
	update_index(stack_b);
	while (i--)
	{
		if (node_a)
		{
			printf("\t[%d]%d", node_a->index,
				node_a->value);
			if (node_a->target)
				printf("(%d)", node_a->target->value);
			else
				printf("(0)\t\t\t\t");
			if (node_a->cost_push)
				printf("(%d)\t\t\t", node_a->cost_push);
			else
				printf("(0)\t\t\t");
			node_a = node_a->next;
		}
		else
			printf("\t\t\t\t");
		if (node_b)
		{
			printf("\t[%d]%d",
				node_b->index, node_b->value);
			if (node_b->target)
				printf("(%d)", node_b->target->value);
			else
				printf("(0)");
			if (node_b->cost_push)
				printf("(%d)\n", node_b->cost_push);
			else
				printf("(0)\n");
			node_b = node_b->next;
		}
		else
			printf("\n");
	}
	printf("-----------------\t\t\t-----------------\n");
	printf("\tA (%d)\t\t\t\tB (%d)\n\n", stack_a->size, stack_b->size);
}
