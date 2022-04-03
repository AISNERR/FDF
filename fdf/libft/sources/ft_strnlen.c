/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:32:33 by aisner            #+#    #+#             */
/*   Updated: 2022/04/03 03:30:30 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	char	*ptr;

	ptr = ft_memchr(s, '\0', maxlen);
	if (ptr)
		return ((size_t)(ptr - s));
	return (maxlen);
}
