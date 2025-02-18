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

#include "aux.h"

void	ft_lstclear(t_stack *lst)
{
	t_node	*obj;
	t_node	*tmp;

	if (!lst || !lst->top)
		return ;
	obj = lst->top;
	while (obj)
	{
		tmp = obj->next;
		free(obj);
		obj = tmp;
	}
	free(lst);
}
