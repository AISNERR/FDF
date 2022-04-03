/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:37:24 by aisner            #+#    #+#             */
/*   Updated: 2022/04/03 03:27:29 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubchr(const char *s, char c)
{
	char	*ptr;

	ptr = ft_strchrs(s, c);
	if (!(ptr))
		return (NULL);
	return (ft_strsub(s, 0, ptr - s));
}
