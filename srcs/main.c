/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:02:07 by estrong           #+#    #+#             */
/*   Updated: 2022/10/03 19:20:16 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void    init_var(t_game *game)
{
    game->map->map = ft_spleat("111111\n100001\n101001\n101001\n100001\n100N01");
	game->north = ft_strdup("north.xmp");
	game->south = ft_strdup("south.xmp");
	game->west = ft_strdup("west.xmp");
	game->east = ft_strdup("east.xmp");
	game->C = ft_strdup("225,30,0");
	game->F = ft_strdup("220,100,0");
	game->orient = 'N';
}

void   error(char *err, t_game *game)
{
    if (game)
        game = NULL;
    perror(err);
    exit(1);
}

// void    free(t_game *game)
// {

// }

int main(int ac, char **av)
{
    t_game  game;

    if (ac != 2)
        error("Error\n invalid number of parameters", &game);
    init_var(&game);
    start(&game);

    return (0);
}