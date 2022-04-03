/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:25:53 by aisner            #+#    #+#             */
/*   Updated: 2022/04/02 17:31:57 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystach, const char *needle)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystach);
	while (haystach[i])
	{
		j = 0;
		n = i;
		while (haystach[n] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystach[i]);
			j++;
			n++;
		}
		i++;
	}
	return (0);
}
