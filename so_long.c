/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migenc <migenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:23:32 by migenc            #+#    #+#             */
/*   Updated: 2024/04/21 15:03:09 by migenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/so_long.h"

static void	ft_window(t_game *game)
{
	mlx_key_hook(game->win, ft_key_hook, game);
	mlx_hook(game->win, BTN_EXIT, 0, ft_exit_game, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		return (ft_printf("Check to parameters!\n"), ERROR);
	if (map(av[1], &game) != SUCCESS)
		return (ERROR);
	if (game->map_height > 20 || game->map_width > 40)
	{
		ft_printf("The map size is so big!");
		free_map(game);
	}
	render_map(game);
	ft_window(game);
	free_map(game);
	free(game);
	return (0);
}
