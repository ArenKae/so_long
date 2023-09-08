/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:10:36 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 14:10:57 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_edges(t_context **context, char **map, int x, int y)
{
	int	height;
	int	width;

	height = (*context)->map_height;
	width = (*context)->map_width;
	if ((*context)->map_height < 3 || (*context)->map_width < 3)
		return (0);
	while (y < height)
	{
		while (x < width)
		{
			if (x == 0 || x == width - 1)
				if (map[y][x] != '1')
					return (0);
			if (y == 0 || y == height - 1)
				if (map[y][x] != '1')
					return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

void	fill_map_data(t_context **context, char **map, int x, int y)
{
	int	height;
	int	width;

	height = (*context)->map_height;
	width = (*context)->map_width;
	while (y < height)
	{
		while (x < width)
		{
			if (map[y][x] == 'P')
				(*context)->player++;
			if (map[y][x] == 'E')
				(*context)->exit++;
			if (map[y][x] == 'C')
				(*context)->collectibles++;
			if (map[y][x] == 'X')
				(*context)->patrol++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	map_data_init(t_context **context)
{
	(*context)->player = 0;
	(*context)->collectibles = 0;
	(*context)->exit = 0;
	(*context)->moves = 0;
	(*context)->patrol = 0;
	(*context)->flag = 0;
}

int	check_map_data(t_context **context)
{
	if ((*context)->player != 1)
		return (0);
	if ((*context)->exit != 1)
		return (0);
	if ((*context)->collectibles == 0)
		return (0);
	return (1);
}

void	get_window_size(t_context **context)
{
	(*context)->window_x = (*context)->map_width * 50;
	(*context)->window_y = (*context)->map_height * 50;
}
