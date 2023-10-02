/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:36 by acosi             #+#    #+#             */
/*   Updated: 2023/09/29 20:53:00 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Sends a signal when a 'E' marker is found on 

int	is_exit(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (1);
	return (0);
}

//	Checks if the player reaches the exit while all collectibles have
//	been found, and sends a signal to end the game.

int	end_game(int keycode, t_context *context, int x, int y)
{
	char	**map;

	map = context->map;
	if ((keycode == 122 || keycode == 119)
		&& map[y - 1][x] == 'E' && context->collectibles == 0)
		return (win_message());
	if (keycode == 115 && map[y + 1][x] == 'E' && context->collectibles == 0)
		return (win_message());
	if ((keycode == 113 || keycode == 97)
		&& map[y][x - 1] == 'E' && context->collectibles == 0)
		return (win_message());
	if (keycode == 100 && map[y][x + 1] == 'E' && context->collectibles == 0)
		return (win_message());
	return (0);
}

//	If a collectible is encountered, replaces the 'C' marker with 
//	empty space and sends a signal to decrease the collectible counter.

int	is_collectible(int keycode, char **map, int x, int y)
{
	if ((keycode == 122 || keycode == 119) && map[y - 1][x] == 'C')
	{
		map[y - 1][x] = '0';
		return (1);
	}
	if (keycode == 115 && map[y + 1][x] == 'C')
	{
		map[y + 1][x] = '0';
		return (1);
	}
	if ((keycode == 113 || keycode == 97) && map[y][x - 1] == 'C')
	{
		map[y][x - 1] = '0';
		return (1);
	}
	if (keycode == 100 && map[y][x + 1] == 'C')
	{
		map[y][x + 1] = '0';
		return (1);
	}
	return (0);
}
