/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:22:06 by estrong           #+#    #+#             */
/*   Updated: 2022/10/05 19:31:39 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void	draw_floor_celling(t_game *game)
{
	unsigned int	*p;
	unsigned int	i;

	p = (unsigned int *) game->imgs->addr;
	i = 1000 * 600 / 2 + 1;
	while (--i > 0)
		*p++ = create_trgb(0, 240, 128, 128);
	i = 1000 * 600 / 2 + 1;
	while (--i > 0)
		*p++ = create_trgb(0, 0, 255, 255);
}

void	draw(t_game *game)
{
	game->imgs = (t_img *)malloc(sizeof(t_img *));
	game->imgs->img = mlx_new_image(game->mlx, 1000, 600);
	game->imgs->addr = mlx_get_data_addr(game->imgs->img, &game->imgs->bits_per_pixel, \
		&game->imgs->line_length, &game->imgs->endian);
	draw_floor_celling(game);
	printf("%s\n", "naxren");
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->imgs->img, 0, 0);
	mlx_destroy_image(game->mlx, game->imgs->img);
	
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	start(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1000, 600, "Ice Nation");
	draw(game);
	// mlx_hook(game->mlx_win, 2, (1L << 1), key, &game);
	// mlx_hook(game->mlx_win, 17, (1L << 0), end_game, &game);
	mlx_loop(game->mlx);
}