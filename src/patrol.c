/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:21:24 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 14:23:14 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_patrol(t_context *context, int y, int x)
{
	int		r;
	char	**map;

	map = context->map;
	r = rand() % 4;
	if (r == 0 && (map[y - 1][x] == '0' || map[y - 1][x] == 'P'))
		move_patrol_up(context, y, x);
	if (r == 1 && (map[y][x + 1] == '0' || map[y - 1][x] == 'P'))
		move_patrol_right(context, y, x);
	if (r == 2 && (map[y + 1][x] == '0' || map[y - 1][x] == 'P'))
		move_patrol_down(context, y, x);
	if (r == 3 && (map[y][x - 1] == '0' || map[y - 1][x] == 'P'))
		move_patrol_left(context, y, x);
}

void	sort_map_patrol(t_context *context)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	map = context->map;
	while (y < context->map_height)
	{
		while (x < context->map_width)
		{
			if (map[y][x] == 'Y')
				map[y][x] = 'X';
			x++;
		}
		x = 0;
		y++;
	}
}

void	patrol(t_context *context)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map = context->map;
	sort_map_patrol(context);
	while (y < context->map_height)
	{
		while (x < context->map_width)
		{
			if (map[y][x] == 'X')
				move_patrol(context, y, x);
			x++;
		}
		x = 0;
		y++;
	}
}

int	init_patrol(t_context *context)
{
	int	i;

	i = time(NULL) % 10;
	if (i % 2 == 0 && context->flag == 0)
	{
		patrol(context);
		context->flag = 1;
	}
	if (i % 2 == 1)
		context->flag = 0;
	return (1);
}
