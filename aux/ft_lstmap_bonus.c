/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:59:57 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/27 15:59:58 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack	*ft_lstmap(t_node **lst, int(*f)(int), void (*del)(int))
{
	t_node	*temp;
	t_stack	*list;
	t_node	*node;
	int		content;

	if (!lst || !f || !del)
		return (0);
	list = NULL;
	temp = *lst;
	while (temp)
	{
		content = f(temp->value);
		node = ft_lstnew(content);
		if (!node)
		{
			ft_lstclear(list, del);
			return (0);
		}
		ft_lstadd_back(list, node);
		temp = temp->next;
	}
	return (list);
}
