/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:19:02 by aisner            #+#    #+#             */
/*   Updated: 2022/04/03 03:21:28 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void	ft_runner02(t_list	*head, t_list *elem)
{
	if (!(elem))
	{
		if (head)
			ft_lstdel(&head, &ft_del);
	}
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*prev;
	t_list	*head;

	prev = NULL;
	head = NULL;
	if (f)
	{
		while (lst)
		{
			elem = f(lst);
			ft_runner02(head, elem);
			if (!(elem))
				return (NULL);
			if (prev)
				prev->next = elem;
			else
				head = elem;
			lst = lst->next;
			prev = elem;
		}
	}
	return (head);
}
