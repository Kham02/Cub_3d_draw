/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:02:05 by estrong           #+#    #+#             */
/*   Updated: 2022/10/08 20:21:58 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void	raycasting(t_game *game)
{
	// t_map	*map;
	double	y;
	double	x;

	y = game->pers->y;
	x = 3.0;
	// &game->map = &map;
	printf("%e\n", x);
		printf("%c\n", game->map->map[(int)y][(int)x]);
	while (game->map->map && game->map->map[(int)y][(int)x] != '1')
	{
		printf("%s\n", "naxren");
		y = y + (-1.0);
	}
	game->rayc->dist = game->pers->y - y;
	printf("%e\n", game->rayc->dist);
}
//  * game->rayc->rot

void math(t_game *game)
{
	double height_wall;

	height_wall = 0.0;
	
}