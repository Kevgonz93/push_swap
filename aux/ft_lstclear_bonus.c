/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:14:42 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/26 21:14:44 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstclear(t_stack *lst, void (*del)(int))
{
	t_node	*current;
	t_node	*obj;

	if (!lst || !lst->top || !del)
		return ;
	current = lst->top;
	while (current)
	{
		obj = current->next;
		ft_lstdelone(current, del);
		current = obj;
	}
	lst->top = NULL;
}
