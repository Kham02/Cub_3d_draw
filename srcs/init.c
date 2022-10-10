/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:43:10 by estrong           #+#    #+#             */
/*   Updated: 2022/10/10 21:46:50 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void	init_pers_rot(t_game *game)
{
	if (game->orient == 'N')
		game->pers.rot = 3.14 / 2 + GR;
	else if (game->orient == 'S')
		game->pers.rot = 3 * 3.14 / 2 + GR;
	else if (game->orient == 'W')
		game->pers.rot = 3.14 + GR;
	else if (game->orient == 'E')
		game->pers.rot = 3.14 * 2 + GR;
}