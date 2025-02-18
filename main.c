/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:51:51 by kegonzal          #+#    #+#             */
/*   Updated: 2025/02/13 19:51:52 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initiating(int argc, char *argv[], t_stack **stack_a)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		*stack_a = stack_init(argv);
		ft_free_matrix((void **)argv);
	}
	else
		*stack_a = stack_init(argv + 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	initiating(argc, argv, &stack_a);
	if (!stack_a)
	{
		ft_lstclear(stack_a);
		exit(1);
	}
	stack_b = ft_calloc(1, sizeof(t_stack));
	if (!check_sorted(stack_a, 'a'))
	{
		if (stack_a->size == 2)
			sa(stack_a, true);
		else if (stack_a->size == 3)
			sort_three(stack_a);
		else
			sort_stacks(stack_a, stack_b);
	}
	ft_lstclear(stack_a);
	free(stack_b);
}
