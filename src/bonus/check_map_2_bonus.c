/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:08:02 by acosi             #+#    #+#             */
/*   Updated: 2023/10/01 01:18:39 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	Gets the number of lines in the map and stores the value in context->map_height.
	The if() statement inside the first while loop checks if the map is empty, in
	which case it breaks to avoid increasing the map_height.
	Then, the second loop checks if there are some empty lines before reaching the
	end of the map.
*/

int	check_map_height(t_context **context, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0' || map[i][0] == '\n')
			break ;
		i++;
	}
	(*context)->map_height = i;
	while (map[i])
	{
		if (map[i][0] && (map[i][0] != '\0' || map[i][0] != '\n'))
			return (0);
		i++;
	}
	return (1);
}

/*
	Checks that every line of the map has the same lenght.
	At the end of the loop, the lenght of a line is stored
	in context->map_width.
*/

int	check_map_width(t_context **context, char **map)
{
	int	lenght;
	int	i;

	i = 1;
	lenght = ft_strlen(map[0]);
	while (i < (*context)->map_height)
	{
		if (ft_strlen(map[i]) != lenght)
			return (0);
		i++;
	}
	(*context)->map_width = lenght;
	return (1);
}

/*
	First, we check if the dimensions of the map are large enough to allow 
	the player to move (minimum 3 height/width).
	The values of map_width and map_height match the layout of the 2D array,
	meaning they are actually 1 unit smaller than the actual dimensions of the 
	map (in other words : they start at 0 instead of 1).
	Then, we check if the edges of the map are all made of walls (1).
*/

int	check_map_edges(t_context **context, char **map, int x, int y)
{
	int	height;
	int	width;

	height = (*context)->map_height;
	width = (*context)->map_width;
	if ((*context)->map_height < 2 || (*context)->map_width < 2)
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
		if (x > width || y > height)
			break ;
	}
	return (1);
}

/*
	Parses the whole map and checks that every char is either one of the following :
	'1' (wall) ; '0' (empty space) ; 'P' (Player Spawn) ; 'C' (Collectible) ; 
	'E' (Exit) ; 'X' (Patrol). Returns 0 if any other character is found.
*/

int	check_map_letters(t_context **context, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*context)->map_height)
	{
		x = 0;
		while (x < (*context)->map_width)
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P' &&
					map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'X')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
