/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:18:12 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/26 21:18:12 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*ft_lstlast(t_stack *lst)
{
	t_node	*last;

	last = lst->top;
	if (!lst)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}
