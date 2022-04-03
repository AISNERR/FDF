/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 20:41:27 by aisner            #+#    #+#             */
/*   Updated: 2022/04/02 20:41:28 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_coord_val type
** <stdlib.h> for NULL macros
*/

#include "fdf.h"
#include <stdlib.h>

/*
** Add t_coord_val element to stack
*/

void	push(t_coord_val **coords_stack, t_coord_val *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

/*
** Get t_coord_val element from stack
*/

t_coord_val	*pop(t_coord_val **coords_stack)
{
	t_coord_val	*top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}
