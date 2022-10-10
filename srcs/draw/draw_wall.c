/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:02:09 by estrong           #+#    #+#             */
/*   Updated: 2022/10/10 22:28:51 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

static void	draw_wall_line(t_game *game, t_ray *q, t_ray *wall, int lineh)
{
	double	pix_start;
	double	pix_step;

	pix_step = 1. * wall->texture.size_y / lineh / 2;
	pix_start = (q->starty - 800 / 2. + lineh) * pix_step;
	while (q->starty < q->endy)
	{
		q->startx = q->savex;
		pix_start += pix_step;
		if (wall->side == 1 || wall->side == 2)
			q->texture = get_pixel(wall->texture, wall->x, pix_start);
		else
			q->texture = get_pixel(wall->texture, wall->y, pix_start);
		q->texture = shade_color(q->texture, wall->dist / 1.1);
		while (q->startx < q->endx)
			my_mlx_pixel_put(&game->imgs, q->startx++, q->starty, q->texture);
		q->starty++;
	}
}

static void	draw_line(t_game *game, int lineh, t_ray wall, int x)
{
	t_ray	q;

	q.rad = 3000;
	q.starty = 400 - lineh;
	q.endy = 400 + lineh;
	q.savex = x * 2;
	q.endx = (x + 1) * 2;
	q.y = -1;
	if (q.starty < 0)
		q.starty = 0;
	if (q.endy > 800)
		q.endy = 800;
	draw_ceil(&q, &game->back, game->vars.ceil_clr);
	draw_wall_line(map, &q, &wall, lineh);
	draw_floor(&q, &game->back, game->vars.floor_clr);
}

static void	wall_inf(t_game *game, t_ray *wall, double start)
{
	double	dist_y;
	double	dist_x;

	dist_y = cast_on_y(game, game->pers->x, game->pers->y, start);
	dist_y = cast_on_x(game, game->pers->x, game->pers->y, start);
	if (y > x)
		ea_we(game, wall, x, start);
	else
		no_so(game, wall, y, start);
	wall->y = fabs(sin(start) * wall->rot);
	wall->x = fabs(sin(start) * wall->rot);
	calc(wall, start, game->pers->x, game->pers->y);
}

void	draw_wall(t_game *game)
{
	t_ray	wall;
	double 	start;
	double 	end;
	double 	delt;
	int		x;
	
	end = game->pers->rot + FOV2;
	if (end > PI * 2)
		end -= PI * 2;
	start = end - 2 * FOV2;
	x = 500;
	while (end > start && x > -1)
	{
		delt = game->pers->rot - start;
		if (delt < 0)
			delt += 2 PI;
		else if (delt > 2 * PI)
			delt -= 2 * PI;
		wall_inf(game, &wall, start);
		wall->rot *= cos(delt);
		draw_line(game, (int)(600 / wall->rot / 2), wall, x);
		start += 0.00158666;
		x--;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs,, 0, 0);
}
