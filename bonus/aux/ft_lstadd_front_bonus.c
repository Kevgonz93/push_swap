/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:13:58 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/26 17:14:01 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aux.h"

void	ft_lstadd_front(t_stack *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->next = lst->top;
	lst->top = new;
}
