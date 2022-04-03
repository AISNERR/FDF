/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:51:05 by aisner            #+#    #+#             */
/*   Updated: 2022/04/03 03:51:39 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "color.h"

int	helper01(t_point f, t_point s)
{
	if (f.x < s.x)
		return (1);
	else
		return (-1);
}

int	helper02(t_point f, t_point s)
{
	if (f.y < s.y)
		return (1);
	else
		return (-1);
}

int	helper03(t_point f, t_point s)
{
	if ((s.x - f.x) < 0)
		return ((s.x - f.x) * -1);
	else
		return (s.x - f.x);
}

int	helper04(t_point f, t_point s)
{
	if ((s.y - f.y) < 0)
		return ((s.y - f.y) * -1);
	else
		return (s.y - f.y);
}

int	error_checker(int *error, t_point delta)
{
	if (error[1] > -delta.y)
		error[0] -= delta.y;
	if (error[1] < delta.x)
		error[0] += delta.x;
	return (error[0]);
}
