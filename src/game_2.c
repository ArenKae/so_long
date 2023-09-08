/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:13:25 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 14:13:47 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_exit(char **map, int x, int y)
{
	if (map[y][x] == 'E')
		return (1);
	return (0);
}

int	end_game(int keycode, t_context *context, int x, int y)
{
	char	**map;

	map = context->map;
	if (keycode == 13 && map[y - 1][x] == 'E' && context->collectibles == 0)
		return (1);
	if (keycode == 1 && map[y + 1][x] == 'E' && context->collectibles == 0)
		return (1);
	if (keycode == 0 && map[y][x - 1] == 'E' && context->collectibles == 0)
		return (1);
	if (keycode == 2 && map[y][x + 1] == 'E' && context->collectibles == 0)
		return (1);
	return (0);
}

int	game_over(int keycode, t_context *context, int x, int y)
{
	if (keycode == 13 && (context->map[y - 1][x] == 'X'
		|| context->map[y - 1][x] == 'Y'))
		return (1);
	if (keycode == 1 && (context->map[y + 1][x] == 'X'
		|| context->map[y + 1][x] == 'Y'))
		return (1);
	if (keycode == 0 && (context->map[y][x - 1] == 'X'
		|| context->map[y][x - 1] == 'Y'))
		return (1);
	if (keycode == 2 && (context->map[y][x + 1] == 'X'
		|| context->map[y][x + 1] == 'Y'))
		return (1);
	return (0);
}

int	is_collectibles(int keycode, char **map, int x, int y)
{
	if (keycode == 13 && map[y - 1][x] == 'C')
	{
		map[y - 1][x] = '0';
		return (1);
	}
	if (keycode == 1 && map[y + 1][x] == 'C')
	{
		map[y + 1][x] = '0';
		return (1);
	}
	if (keycode == 0 && map[y][x - 1] == 'C')
	{
		map[y][x - 1] = '0';
		return (1);
	}
	if (keycode == 2 && map[y][x + 1] == 'C')
	{
		map[y][x + 1] = '0';
		return (1);
	}
	return (0);
}
