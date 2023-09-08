/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:11:43 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 14:12:05 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**alloc_cpy_map(t_context **context)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * (*context)->map_height + 1);
	while (i < (*context)->map_height)
	{
		cpy[i] = malloc(sizeof(char) * (*context)->map_width + 1);
		i++;
	}
	return (cpy);
}

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
