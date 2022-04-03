/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisner <aisner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 18:31:29 by aisner            #+#    #+#             */
/*   Updated: 2022/04/03 03:49:15 by aisner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fdf.h" for t_map type, terminate(), t_fdf type, WIDTH macros, HEIGHT macros,
**  MENU_WIDTH macros and t_camera type
** "libft.h" for ft_memalloc(), NULL macros ("libft.h" includes <string.h>),
**  FT_INT_MAX macros, FT_INT_MIN macros and FT_MIN macros
** "mlx.h" for mlx_init(), mlx_new_window(), mlx_new_image()
**  and mlx_get_data_addr()
** "error_message.h" for ERR_MAP_INIT macros, ERR_FDF_INIT macros
**  and ERR_CAMERA_INIT macros
*/

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include "error_message.h"

/*
** Initialize t_map element
*/

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!(map))
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->coords_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = (int)((unsigned)(~0L) >> 1);
	map->z_max = (int)(~(int)(unsigned)(~0L) >> 1);
	map->z_range = 0;
	return (map);
}

/*
** Initialize t_fdf element
*/

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	if (!(fdf))
		terminate(ERR_FDF_INIT);
	fdf->mlx = mlx_init();
	if (!(fdf))
		terminate(ERR_FDF_INIT);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	if (!(fdf->win))
		terminate(ERR_FDF_INIT);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!(fdf->img))
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse));
	if (!(fdf->mouse))
		terminate(ERR_FDF_INIT);
	return (fdf);
}

/*
** Initialize t_camera element
*/

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)ft_memalloc(sizeof(t_camera));
	if (!(camera))
		terminate(ERR_CAMERA_INIT);
	if (((WIDTH - MENU_WIDTH) / fdf->map->width / 2) < (HEIGHT
			/ fdf->map->height / 2))
		camera->zoom = (WIDTH - MENU_WIDTH) / fdf->map->width / 2;
	else
		camera->zoom = HEIGHT / fdf->map->height / 2;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
