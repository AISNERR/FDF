/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 22:24:13 by sgaladri          #+#    #+#             */
/*   Updated: 2022/04/03 02:42:44 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	res = (t_list *)ft_memalloc(sizeof(t_list));
	if (res)
	{
		if (!content)
		{
			res->content = NULL;
			res->content_size = 0;
		}
		else
		{
			res->content = ft_memalloc(content_size);
			if (!(res->content))
			{
				free(res);
				return (NULL);
			}
			ft_memcpy(res->content, content, content_size);
			res->content_size = content_size;
		}
		res->next = NULL;
	}
	return (res);
}
