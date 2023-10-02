/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:01 by acosi             #+#    #+#             */
/*   Updated: 2023/09/27 17:05:00 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	Parses through the map in every 4 directions starting from the player
	position, to see if there is a valid position to move. '1' is a wall
	and 'X' is a patrol, so the player can't move there. 'A' is a marker added
	on the map copy by a later function. It represents a valid position where 
	the player can move. This condition is checked in this function to know
	which positions have already been processed and avoid an infinite loop.
*/

int	try_move_path(char **map, int x, int y, int i)
{
	if (i == 1)
		if (map[y][x + 1] != '1' && map[y][x + 1] != 'A'
			&& map[y][x + 1] != 'X')
			return (i);
	if (i == 2)
		if (map[y][x - 1] != '1' && map[y][x - 1] != 'A'
			&& map[y][x - 1] != 'X')
			return (i);
	if (i == 3)
		if (map[y + 1][x] != '1' && map[y + 1][x] != 'A'
			&& map[y + 1][x] != 'X')
			return (i);
	if (i == 4)
		if (map[y - 1][x] != '1' && map[y - 1][x] != 'A'
			&& map[y - 1][x] != 'X')
			return (i);
	return (0);
}

/*
	If a position has been found valid by the try_move_path() function,
	this function will place a marker 'A' in the map copy at this
	particular position, to mark it as valid.
	Each i equals a direction in which the player can go :
	1 = right ; 2 = left ; 3 = top ; 4 = bottom
*/

void	make_move_path(char **map, int x, int y, int i)
{
	if (i == 1)
		(map[y][x + 1] = 'A');
	if (i == 2)
		(map[y][x - 1] = 'A');
	if (i == 3)
		(map[y + 1][x] = 'A');
	if (i == 4)
		(map[y - 1][x] = 'A');
}

/*
	Checks every valid paths from the player starting position and marks
	them in the map copy.
	First, we try to look in every direction to see if there is one where
	the player can move. The 4 directions are coded as follow :
	1 = right ; 2 = left ; 3 = top ; 4 = bottom
	If a valid position has been found by the try_move_path() function, 
	make_move_path() will place a marker in there to indicate that this
	position is valid. The coordinates are then updated accordingly, and
	the function recursively reckeck the map from this new valid position.
	By the end of the process, every valid positions in the map copy is marked
	by an 'A'.
*/

void	check_valid_path(char **map, int x, int y)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (try_move_path(map, x, y, i) > 0)
		{
			make_move_path(map, x, y, i);
			if (i == 1)
				x = x + 1;
			if (i == 2)
				x = x - 1;
			if (i == 3)
				y = y + 1;
			if (i == 4)
				y = y - 1;
			check_valid_path(map, x, y);
		}
		i++;
	}
	return ;
}
