/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:18:26 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/26 21:18:27 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

t_node	*ft_lstnew(int content)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
