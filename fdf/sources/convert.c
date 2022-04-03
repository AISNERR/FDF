/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:34:00 by aisner            #+#    #+#             */
/*   Updated: 2022/04/02 20:34:03 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_coord_val type, t_map type, terminate() and pop()
** "libft.h" for ssize_t type ("libft.h" includes <string.h>),
** size_t ("libft.h" includes <string.h>) and ft_memalloc()
** "error_message.h" for ERR_CONV_TO_ARR macros
** <stdlib.h> for free()
*/

#include "fdf.h"
#include "libft.h"
#include "error_message.h"
#include <stdlib.h>

/*
** Convert stack with t_coord_val elements (contains z value and color value)
** to array with z values and array with color values.
*/

static	void	smth(t_map *map)
{
	if (!(map->coords_arr))
		terminate(ERR_CONV_TO_ARR);
}

void	stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val	*coord;
	ssize_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	map->coords_arr = (int *)ft_memalloc(arr_size);
	smth(map);
	map->colors_arr = (int *)ft_memalloc(arr_size);
	if (!(map))
		terminate(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	coord = pop(coords_stack);
	while ((coord) && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
		coord = pop(coords_stack);
	}
	map->z_range = map->z_max - map->z_min;
}
