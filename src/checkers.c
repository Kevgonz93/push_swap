#include "../push_swap.h"

int	check_data(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		if (str[i] == '-' || str[i] == '+')
		{
			if (!ft_isdigit(str[i + 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack)
{
	t_node	*obj;
	t_node	*tmp;

	obj = stack->top;
	while (obj)
	{
		tmp = obj->next;
		while (tmp)
		{
			if (obj->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		obj = obj->next;
	}
	return (1);
}

int	check_sorted(t_stack *stack, char c)
{
	t_node	*obj;

	obj = stack->top;
	if (c == 'a')
	{
		while (obj)
		{
			if (obj->next && obj->value > obj->next->value)
				return (0);
			obj = obj->next;
		}
	}
	else
	{
		while (obj)
		{
			if (obj->next && obj->value < obj->next->value)
				return (0);
			obj = obj->next;
		}
	}
	return (1);
}
