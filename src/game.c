/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:12:15 by keschouf          #+#    #+#             */
/*   Updated: 2023/09/08 15:50:13 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_3(t_context *context, int x, int y)
{
	char	**map;

	map = context->map;
	if (map[y][x] == 'E')
		mlx_put_image_to_window(context->game, context->window,
			context->data[1].img_ptr, x * 50, y * 50);
}

void	player_move_2(t_context *context, int keycode, int x, int y)
{
	if (keycode == 13)
	{
		y--;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
	if (keycode == 1)
	{
		y++;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
	if (keycode == 0)
	{
		x--;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
	if (keycode == 2)
	{
		x++;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
	player_move_3(context, x, y);
}

void	player_move(t_context *context, int keycode, int *x, int *y)
{
	if (keycode == 122)
	{
		context->player_pos.y--;
		mlx_put_image_to_window(context->game, context->window,
			context->data[4].img_ptr, *x * 50, *y * 50);
	}
	if (keycode == 115)
	{
		context->player_pos.y++;
		mlx_put_image_to_window(context->game, context->window,
			context->data[6].img_ptr, *x * 50, *y * 50);
	}
	if (keycode == 113)
	{
		context->player_pos.x--;
		mlx_put_image_to_window(context->game, context->window,
			context->data[5].img_ptr, *x * 50, *y * 50);
	}
	if (keycode == 100)
	{
		context->player_pos.x++;
		mlx_put_image_to_window(context->game, context->window,
			context->data[7].img_ptr, *x * 50, *y * 50);
	}
}

int	valid_move(int keycode, t_context *context, int x, int y)
{
	if (keycode == 27)
		destroy_window(context);
	if (game_over(keycode, context, x, y))
	{
		write(1, "Game Over!\n", 12);
		destroy_window(context);
	}
	if (keycode == 122 && context->map[y - 1][x] != '1')
		return (1);
	if (keycode == 115 && context->map[y + 1][x] != '1')
		return (1);
	if (keycode == 113 && context->map[y][x - 1] != '1')
		return (1);
	if (keycode == 100 && context->map[y][x + 1] != '1')
		return (1);
	return (0);
}

int	on_key(int keycode, t_context *context)
{
	int	*x;
	int	*y;

	x = &context->player_pos.x;
	y = &context->player_pos.y;
	if (keycode || !keycode)
	{
		if (valid_move(keycode, context, *x, *y))
		{
			context->moves++;
			if (is_collectibles(keycode, context->map, *x, *y))
				context->collectibles--;
			mlx_put_image_to_window(context->game, context->window,
				context->data[3].img_ptr, *x * 50, *y * 50);
			player_move_2(context, keycode, *x, *y);
			if (is_exit(context->map, *x, *y))
				mlx_put_image_to_window(context->game, context->window,
					context->data[1].img_ptr, *x * 50, *y * 50);
			if (end_game(keycode, context, *x, *y))
				destroy_window(context);
			player_move(context, keycode, x, y);
			print_move(context, context->moves);
		}
	}
	return (1);
}
