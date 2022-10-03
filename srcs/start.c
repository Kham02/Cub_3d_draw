/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:22:06 by estrong           #+#    #+#             */
/*   Updated: 2022/10/03 19:40:52 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void	draw(t_game *game)
{
	game->imgs.img = mlx_new_image(game->mlx, 600, 600);
	game->imgs.addr = mlx_get_data_addr(game->imgs.img, &game->imgs.bits_per_pixel, \
		&game->imgs.line_lenght, &game->imgs.endian);
	draw_floor_celling(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs.img, 0, 0);
	mlx_destroy_image(game->mlx, game->imgs.img);
	
}

void	start(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game.mlx, 600, 600, "Ice Nation");
	draw(game);
	mlx_hook(game->mlx_win, 2, (1L << 1), key, &game);
	mlx_hook(game->mlx_win, 17, (1L << 0), end_game, &game);
	mlx_loop(game->mlx);
}