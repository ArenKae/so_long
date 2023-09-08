/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:11:07 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 14:11:33 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	chck_vld_path(char **map, int x, int y)
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
			chck_vld_path(map, x, y);
		}
		i++;
	}
	return ;
}

void	assign_pos(t_context **context, int y, int x)
{
	(*context)->player_pos.x = x;
	(*context)->player_pos.y = y;
}

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
				assign_pos(context, y, x);
		}
		cpy[y][x] = '\0';
		x = -1;
	}
	cpy[y] = NULL;
	chck_vld_path(cpy, (*context)->player_pos.x, (*context)->player_pos.y);
	if (!check_final_path(cpy))
	{
		free_tab(cpy);
		return (0);
	}
	free_tab(cpy);
	return (1);
}
