/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migenc <migenc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:23:11 by migenc            #+#    #+#             */
/*   Updated: 2024/04/21 15:05:46 by migenc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < (game->map_height))
		free(game->map_copy[i++]);
	free(game->map_copy);
	i = 0;
	while (i < (game->map_height))
		free(game->map[i++]);
	free(game->map);
	exit(0);
}

static void	create_map(char *add, t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (add[j])
		j++;
	while (add[i])
	{
		if (add[0] == '\n' || (add[i] == '\n' && add[i + 1] == '\n')
			|| add[j - 1] == '\n')
		{
			ft_printf("The map is not rectengular!");
			free(add);
			exit(0);
		}
		i++;
	}
	game->map = ft_split(add, '\n');
	game->map_copy = ft_split(add, '\n');
	free(add);
	game->map_width = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i++] != NULL)
		game->map_height++;
}

int	get_map(char *file, t_game *game)
{
	char	*tmp;
	char	*add;
	int		fd;

	add = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Check to map path!"), ERROR);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		add = ft_gnl_strjoin(add, tmp);
		free(tmp);
	}
	create_map(add, game);
	return (close(fd), SUCCESS);
}

int	map(char *file, t_game **game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_map_extensions(file) != SUCCESS)
		return (ERROR);
	*game = malloc(sizeof(t_game));
	if (!(*game))
		return (ft_printf("game cannot be allocated"), ERROR);
	init_game(*game);
	if (get_map(file, *game) != SUCCESS || check_map_wall(*game) != SUCCESS
		|| character_checker(*game) != SUCCESS
		|| check_character_count(*game) != SUCCESS
		|| check_game(*game) != SUCCESS)
		return (ERROR);
	return (SUCCESS);
}
