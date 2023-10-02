/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:33:03 by acosi             #+#    #+#             */
/*   Updated: 2023/09/27 17:04:43 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	This function is responsible for the movements of the patrols, which are
	determined by a random integer, each values resulting in a move toward
	a different direction. For every if(), the function checks if there is an
	empty space (0) or a player (P) at the destination for the patrol to move.
*/

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

/*
	When a patrol is moved, a 'Y' marker is placed by the move_patrol() function to 
	the determined coodinates. This function replaces every 'Y' by an 'X' marker
	(the default patrol marker) to reset their positions for the next loop.
*/

void	reset_patrol_markers(t_context *context)
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

//	Moves the patrols markers (X) on the map and reset
//	the markers responsible for the previous patrols move.

void	patrol(t_context *context)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map = context->map;
	reset_patrol_markers(context);
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

/*
	Handles the behavior of bonus animations for the player ship and the patrols.
	The patrol() function is responsible for their movements. It is called only 
	when 'i' is a multiple of 2, meaning the patrols will move every 2 seconds 
	(time returns the current elapsed time in seconds). 
	The flag ensure that the patrols only move once every 2 seconds, and stay 
	in place when they have already been moved.
	ship_anim() makes the rocket booster of the player ship (i.e. th exit) animated.
*/

int	init_bonus(t_context *context)
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
	ship_anim(context, 0, 0);
	return (1);
}
