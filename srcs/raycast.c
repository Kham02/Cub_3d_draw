/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:02:05 by estrong           #+#    #+#             */
/*   Updated: 2022/10/07 23:47:40 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void	raycasting(t_game *game)
{
	// t_map	*map;
	double	y;
	double	x;

	y = game->pers->y;
	x = game->pers->x;
	// &game->map = &map;
		printf("%s\n", "naxren");
	while (game->map->map && game->map->map[(int)y][(int)x] != '1')
	{
		// printf("%c\n", map.map[(int)y][(int)x]);
		y = (y + 0.1);
	}
	printf("%e\n", y);
}
//  * game->rayc->rot