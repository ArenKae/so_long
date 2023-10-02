/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:08 by acosi             #+#    #+#             */
/*   Updated: 2023/09/28 22:53:33 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//	Allocates memory for a copy of the map array to perform 
//	operations on it without altering the original map.

char	**alloc_cpy_map(t_context **context)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * ((*context)->map_height + 1));
	while (i < (*context)->map_height)
	{
		cpy[i] = malloc(sizeof(char) * ((*context)->map_width + 1));
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

//	Assign the coordinates of the 'P' character in the map to
//	the player_pos variables inside the context structure.

void	assign_player_pos(t_context **context, int y, int x)
{
	(*context)->player_pos.x = x;
	(*context)->player_pos.y = y;
}

/*
	After every possible valid positions has been replaced by an 'A' marker,
	there should no longer be any collectibles 'C' or exit 'E' remaining on the
	map. This function parses through the whole map and checks if there are any 
	'C' or 'E' left. If so, it means theses characters are not placed in a valid
	path that the player can reach. Therefore, the map is invalid and the function
	returns 0.
*/

int	check_final_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

/*
	Checks if the map is valid by exploring every path from the player starting
	position, and see if they can reach the collectibles and exit from there.
	First, a copy of the map is allocated to peform operations without altering the
	original. Then, we parse through the map to find the 'P' that corresponds to the
	player starting position, and store it in the context structure. x and y start 
	at a value of -1 and represent the coordinates of the map copy.
	The check_valid_path() function will try to go to every directions starting from
	the player_pos, and mark every valid position found with an 'A' marker.
	Finally, the check_final_path() function verifies that after processing, no 
	unreachable exit or collectibles remain in the map copy, before freeing it.
*/

int	init_check_valid_path(t_context **context, char **map, int y, int x)
{
	char	**cpy;

	cpy = alloc_cpy_map(context);
	while (++y < (*context)->map_height)
	{
		while (++x < (*context)->map_width)
		{
			cpy[y][x] = map[y][x];
			if (map[y][x] == 'P')
				assign_player_pos(context, y, x);
		}
		cpy[y][x] = '\0';
		x = -1;
	}
	cpy[y] = NULL;
	check_valid_path(cpy, (*context)->player_pos.x, (*context)->player_pos.y);
	if (!check_final_path(cpy))
	{
		free_tab(cpy);
		return (0);
	}
	free_tab(cpy);
	return (1);
}
