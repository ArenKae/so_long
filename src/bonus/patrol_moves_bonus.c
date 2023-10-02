/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:56 by acosi             #+#    #+#             */
/*   Updated: 2023/09/27 17:04:40 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	x and y are the current coordinates of the patrol and start at 0. If they
	are equals to the player's coordinate, it's game over so we destroy the window.
	If not, the game proceeds and the "old" coordinates are replaced with empty 
	space (0), while a 'Y' marker is put in the new ones. The corresonding sprite 
	is then displayed in the window.
*/

void	move_patrol_up(t_context *context, int y, int x)
{
	char	**map;

	map = context->map;
	if (y - 1 == context->player_pos.y && x == context->player_pos.x)
	{
		write(1, "GAME OVER\n", 11);
		destroy_window(context);
	}
	map[y][x] = '0';
	map[y - 1][x] = 'Y';
	mlx_put_image_to_window(context->game, context->window,
		context->data[3].img_ptr, x * 50, y * 50);
	mlx_put_image_to_window(context->game, context->window,
		context->data[8].img_ptr, x * 50, (y - 1) * 50);
}

void	move_patrol_right(t_context *context, int y, int x)
{
	char	**map;

	map = context->map;
	if (y == context->player_pos.y && x + 1 == context->player_pos.x)
	{
		write(1, "GAME OVER\n", 11);
		destroy_window(context);
	}
	map[y][x] = '0';
	map[y][x + 1] = 'Y';
	mlx_put_image_to_window(context->game, context->window,
		context->data[3].img_ptr, x * 50, y * 50);
	mlx_put_image_to_window(context->game, context->window,
		context->data[8].img_ptr, (x + 1) * 50, y * 50);
}

void	move_patrol_down(t_context *context, int y, int x)
{		
	char	**map;

	map = context->map;
	if (y + 1 == context->player_pos.y && x == context->player_pos.x)
	{
		write(1, "GAME OVER\n", 11);
		destroy_window(context);
	}
	map[y][x] = '0';
	map[y + 1][x] = 'Y';
	mlx_put_image_to_window(context->game, context->window,
		context->data[3].img_ptr, x * 50, y * 50);
	mlx_put_image_to_window(context->game, context->window,
		context->data[8].img_ptr, x * 50, (y + 1) * 50);
}

void	move_patrol_left(t_context *context, int y, int x)
{
	char	**map;

	map = context->map;
	if (y == context->player_pos.y && x - 1 == context->player_pos.x)
	{
		write(1, "GAME OVER\n", 11);
		destroy_window(context);
	}
	map[y][x] = '0';
	map[y][x - 1] = 'Y';
	mlx_put_image_to_window(context->game, context->window,
		context->data[3].img_ptr, x * 50, y * 50);
	mlx_put_image_to_window(context->game, context->window,
		context->data[8].img_ptr, (x - 1) * 50, y * 50);
}
