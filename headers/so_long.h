/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migenc <migenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:22:41 by migenc            #+#    #+#             */
/*   Updated: 2024/04/21 14:38:46 by migenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lib/ft_printf/ft_printf.h"
# include "../headers/get_next_line.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"

# define BTN_EXIT 17
# define WALL '1'
# define PLAYER 'P'
# define FLOOR '0'
# define ITEM 'C'
# define EXIT 'E'
# define SUCCESS 0
# define ERROR 1
# define MAP 0
# define MAP_COPY 1

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_R 15
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define DIR_LEFT 	4
# define DIR_RIGHT 	6
# define DIR_UP 	8
# define DIR_DOWN 	2

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

typedef struct s_imgs
{
	void	*c;
	void	*e;
	void	*f;
	void	*p;
	void	*w;
}	t_imgs;

typedef struct s_game
{
	char		**map;
	char		**map_copy;
	int			map_height;
	int			map_width;
	int			moves;
	int			item;
	int			img_height;
	int			img_width;
	t_exit		exit;
	t_imgs		imgs;
	t_player	player;
	void		*mlx;
	void		*win;
}	t_game;

typedef struct s_count
{
	int	exit;
	int	i;
	int	j;
	int	player;
}	t_count;

int			character_checker(t_game *game);
int			check_character_count(t_game *game);
int			check_game(t_game *game);
int			check_map_extensions(char *file);
int			check_map_wall(t_game *game);
int			ft_exit_game(t_game *game);
int			ft_init_images(t_game *game);
int			ft_key_hook(int key, t_game *game);
int			get_map(char *file, t_game *game);
int			map(char *file, t_game **game);
int			player_location(t_game *game, t_count character);

void		free_map(t_game *game);
void		ft_fill_flood(int x, int y, t_game *game);
void		ft_put_images(t_game *game);
void		ft_write_score(t_game *game);
void		init_game(t_game *game);
void		render_map(t_game *game);

#endif
