/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:20:35 by aisner            #+#    #+#             */
/*   Updated: 2022/04/02 23:20:36 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	sym;
	unsigned char	*d;
	unsigned char	*s;

	sym = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
		if (*(d - 1) == sym)
			return (d);
	}
	return (NULL);
}
