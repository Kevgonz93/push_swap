/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:16:28 by kegonzal          #+#    #+#             */
/*   Updated: 2024/09/26 22:16:30 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstiter(t_node *lst, void (*f)(int))
{
	if (!lst || !f)
		return ;
	while (lst != 0)
	{
		f(lst->value);
		lst = lst->next;
	}
}
