/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:45 by estrong           #+#    #+#             */
/*   Updated: 2022/10/04 20:12:07 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ############## inc ##############

#include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx_opengl/mlx.h"

# include "../Libft/libft.h"
// # include "../srcs/get_next_line.h"



// ############## struct ##############

typedef struct	s_map
{
	char	**map;
	size_t	x;
	size_t	y;
}t_map;

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size_x;
	int		size_y;
}t_img;

typedef struct	s_game
{
	t_img	*imgs;
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		fd;
	char	*F;
	char	*C;
	char	orient;
}t_game;

// ############## fun ##############

void    init_var(t_game *game);
void	start(t_game *game);
void	draw(t_game *game);
int		create_trgb(int t, int r, int g, int b);
void	draw_floor_celling(t_game *game);

// ############## fun ##############

// void	error(char *err, t_game *game);
// void	parse(char **av, t_game *game);
// void	check_texture(t_game *game, char **map, int i);
// char	*get_texture(char **s);
// void	write_texture(t_game *game, char **texture, char **map);
// void	name_texture(t_game *game, char *str);
// int		ft_strcmp(char *s1, char *s2);
// int		len_str(char *str, int n);
// void	check_color(t_game *game, char **map);
// char	**get_color(char *str);
// int		*valid_color(char **color, int *int_col, t_game *game);
// int		cub_atoi(char *str, t_game *game);
// int		check_int(char *str);
// void	get_map(t_game *game, char **map);
// void    valid(t_game *game, char **s);

// ############## utils ##############

// void    print_arr(char **arr);

#endif