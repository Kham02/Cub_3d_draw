/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:06:10 by estrong           #+#    #+#             */
/*   Updated: 2022/10/10 22:18:54 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void	ea_we(t_game *game, t_ray *wall, double rot, double start)
{
	if ((start < 1.5 * PI && start > PI2) || (start < 3.5 * PI && start > 2.5 * PI))
	{
		wall->texture = game->west;
		wall->s = 3;
	}
	else
	{
		wall->texture = game->east;
		wall->s = 4;
	}
	wall->dist = rot;
}

void	no_so(t_game *game, t_ray *wall, double rot, double start)
{
	if ((start < PI && start > 0) || (start < 3 * PI && start > 2 * PI))
	{
		wall->texture = game->north;
		wall->s = 3;
	}
	else
	{
		wall->texture = game->south;
		wall->s = 4;
	}
	wall->dist = rot;
}

void	calc(t_ray *data, double dir, double persx, double persy)
{
	if (dir < PI && dir > 0)
		data->y = -data->y;
	if (dir > PI2 && dir < PI2 * 3)
		data->x = -data->x;
	data->x += persx;
	data->y += persy;
	if ((dir < PI && dir > 0) || (dir < 3 * PI && dir > 2 * PI))
		data->x -= floor(data->x);
	else
		data->x = ceil(data->x) - data->x;
	if ((dir < 1.5 * PI && dir > PI2) || (dir < 3.5 * PI && dir > 2.5 * PI))
		data->y = ceil(data->y) - data->y;
	else
		data->y -= floor(data->y);
	data->x *= data->wall_img.size_x;
	data->y *= data->wall_img.size_x;
}