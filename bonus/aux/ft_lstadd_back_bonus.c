/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:13:46 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/26 17:13:48 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	ft_lstadd_back(t_stack *lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!lst)
	{
		lst->top = new;
		return ;
	}
	else
	{
		last = ft_lstlast(lst);
		last->next = new;
	}
}
