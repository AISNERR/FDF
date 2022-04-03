/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:34:18 by aisner            #+#    #+#             */
/*   Updated: 2022/04/03 00:34:19 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	char	*start;
	char	*end;
	char	c;

	if (s)
	{
		start = s;
		end = s + (ft_strlen(s) - 1);
		while (start < end)
		{
			c = *start;
			*start++ = *end;
			*end-- = c;
		}
	}
	return (s);
}
