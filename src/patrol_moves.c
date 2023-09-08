/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:23:29 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 17:45:04 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_patrol_up(t_context *context, int y, int x)
{
	char	**map;

	map = context->map;
	if (y - 1 == context->player_pos.y && x == context->player_pos.x)
	{
		write(1, "Game over!\n", 12);
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
		write(1, "Game over!\n", 12);
		destroy_window(context);
	}
	map[y][x] = '0';
	map[y][x + 1] = 'Y';
	mlx_put_image_to_window(context->game, context->window,
		context->data[3].img_ptr, x * 50, y * 50);
	mlx_put_image_to_window(context->game, context->window,
		context->data[9].img_ptr, (x + 1) * 50, y * 50);
}

void	move_patrol_down(t_context *context, int y, int x)
{		
	char	**map;

	map = context->map;
	if (y + 1 == context->player_pos.y && x == context->player_pos.x)
	{
		write(1, "Game over!\n", 12);
		destroy_window(context);
	}
	map[y][x] = '0';
	map[y + 1][x] = 'Y';
	mlx_put_image_to_window(context->game, context->window,
		context->data[3].img_ptr, x * 50, y * 50);
	mlx_put_image_to_window(context->game, context->window,
		context->data[10].img_ptr, x * 50, (y + 1) * 50);
}

void	move_patrol_left(t_context *context, int y, int x)
{
	char	**map;

	map = context->map;
	if (y == context->player_pos.y && x - 1 == context->player_pos.x)
	{
		write(1, "Game over!\n", 12);
		destroy_window(context);
	}
	map[y][x] = '0';
	map[y][x - 1] = 'Y';
	mlx_put_image_to_window(context->game, context->window,
		context->data[3].img_ptr, x * 50, y * 50);
	mlx_put_image_to_window(context->game, context->window,
		context->data[11].img_ptr, (x - 1) * 50, y * 50);
}
