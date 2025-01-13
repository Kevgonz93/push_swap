/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kegonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:08:06 by kegonzal          #+#    #+#             */
/*   Updated: 2024/12/05 15:08:07 by kegonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
	int				cost;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

#endif
