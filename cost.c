#include "push_swap.h"
#include "moves/moves.h"

void	update_index(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack_a->top;
	while (node)
	{
		node->index = i++;
		node = node->next;
	}
	i = 0;
	node = stack_b->top;
	while (node)
	{
		node->index = i++;
		node = node->next;
	}
}

t_stack	*temp_stack(t_stack *stack, int initial)
{
	t_stack	*temp;
	t_node	*node;
	t_node	*new_node;

	if (!stack)
		return (NULL);
	temp = ft_calloc(1, sizeof(t_stack));
	if (!temp)
		return (NULL);
	temp->top = ft_lstnew(initial);
	if (!temp->top)
		return(ft_lstclear(temp, del), NULL);
	node = stack->top;
	while (node)
	{
		new_node = ft_lstnew(node->value);
		if (!new_node)
			return (ft_lstclear(temp, del), NULL);
		ft_lstadd_back(temp, new_node);
		node = node->next;
	}
	return (temp);
}

int	sortin_temp(t_stack *temp)
{
	t_node	*node;
	t_node	*initial_top;
	t_node	*initial_bottom;
	int		i;

	if (!temp || !temp->top || !temp->top->next)
		return (0);
	node = temp->top;
	initial_top = node->next;
	initial_bottom = ft_lstlast(temp);
	i = 0;
	if (node->value > initial_top->value)
		i += moving(temp, "swap", 'q');
	else if (node->value > initial_bottom->value)
		i += moving(temp, "rotate", 'q');
	while (!check(temp))
	{
		i += moving(temp, "rotate", 'q');
		i += moving(temp, "swap", 'q');
		i += moving(temp, "reverse", 'q');
	}
	return (i);
}

int	moves_to_top(t_stack *stack_a, int index)
{
	if (index <= stack_a->size / 2)
		return (index);
	return (stack_a->size - index);
}

int	get_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	t_stack	*temp;
	int		cost;

	if (!stack_a || !stack_a->top)
		return (0);
	node = stack_a->top;
	cost = move_to_top(stack_a, node->index, stack_b);
	printf("cost to move to top: %d\n", cost);
	cost++;
	printf("cost to move to the other stack: %d\n", cost);
	temp = temp_stack(stack_b, node->value);
	printf("temp stack created\n");
	cost += sortin_temp(temp);
	printf("cost to sort the other stack: %d\n", cost);
	ft_lstclear(temp, del);
	free(temp);
	return (cost);
}

void	update_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_a->top;
	while (node)
	{
		node->cost = get_cost(stack_a, stack_b);
		node = node->next;
	}
}
