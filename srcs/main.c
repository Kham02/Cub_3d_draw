/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:02:07 by estrong           #+#    #+#             */
/*   Updated: 2022/10/08 19:54:29 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/cub3d.h"

void    init_var(t_game *game)
{
    char    *str;

    str = ft_strdup("111111 100001 101001 101001 100001 100N01 111111");
    game->map = (t_map *)malloc(sizeof(t_map *));
    game->map->map = ft_split(str, ' ');
	game->north = ft_strdup("north.xmp");
	game->south = ft_strdup("south.xmp");
	game->west = ft_strdup("west.xmp");
	game->east = ft_strdup("east.xmp");
	game->C = ft_strdup("225,30,0");
	game->F = ft_strdup("220,100,0");
	game->orient = 'N';
    game->rayc = (t_raycasting *)malloc(sizeof(t_raycasting *));
    game->rayc->rot = 0.0;
    game->rayc->step = -1.0;
    game->pers = (t_pers *)malloc(sizeof(t_pers *));
    game->pers->y = 5.0;
    game->pers->x = 2.0;
}

// void   error(char *err, t_game *game)
// {
//     if (game)
//         game = NULL;
//     perror(err);
//     exit(1);
// }

int main(int ac, char **av)
{
    t_game  game;

    // if (ac != 2)
    //     error("Error\n invalid number of parameters", &game);
    init_var(&game);
    printf("%x\n", ac);
    start(&game);
    printf("%s\n", av[0]);
    return (0);
}