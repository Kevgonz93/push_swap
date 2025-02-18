/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:17:56 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/26 21:17:57 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

int	ft_lstsize(t_stack *lst)
{
	t_node	*node;
	int		i;

	node = lst->top;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
