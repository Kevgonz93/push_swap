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
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;
	t_list	*node;
	void	*content;

	if (!lst || !f || !del)
		return (0);
	list = NULL;
	temp = lst;
	while (temp)
	{
		content = f(temp->content);
		node = ft_lstnew(content);
		if (!node)
		{
			free(content);
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, node);
		temp = temp->next;
	}
	return (list);
}
