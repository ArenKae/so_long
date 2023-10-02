/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:15:35 by acosi             #+#    #+#             */
/*   Updated: 2023/09/27 17:04:29 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//	Parses through the map array to find the coordinates of the exit.

int	find_exit(t_context *context, char **map, int *x1, int *y1)
{
	int	x;
	int	y;

	x = *x1;
	y = *y1;
	while (y < context->map_height)
	{
		x = 0;
		while (x < context->map_width)
		{
			if (map[y][x] == 'E')
			{
				*x1 = x;
				*y1 = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
	Animates the sprites for the player ship (i.e. the exit).
	find_exit() parses the map to find the position of the exit.
	'i' returns the current elapsed time in seconds. Every 3 seconds, a 
	different image is displayed at the coordinates of the exit, creating 
	an animation that cycles between 3 sprites.
*/

int	ship_anim(t_context *context, int x, int y)
{
	int	i;

	i = 0;
	i = time(NULL) % 10;
	find_exit(context, context->map, &x, &y);
	if (i % 3 == 0 && context->loop == 0)
	{
		mlx_put_image_to_window(context->game, context->window,
			context->data[1].img_ptr, x * 50, y * 50);
		context->loop = 1;
	}
	if (i % 3 == 1 && context->loop == 1)
	{
		mlx_put_image_to_window(context->game, context->window,
			context->data[13].img_ptr, x * 50, y * 50);
		context->loop = 2;
	}
	if (i % 3 == 2 && context->loop == 2)
	{
		mlx_put_image_to_window(context->game, context->window,
			context->data[14].img_ptr, x * 50, y * 50);
		context->loop = 0;
	}
	return (1);
}
