/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:35:36 by acosi             #+#    #+#             */
/*   Updated: 2023/09/29 20:54:16 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	Updates the (x.y) coordinates of the player after a valid move
	is performed, to keep track of the player's position. After the player
	moved, the mlx_put_image_to_window() function is used to display
	empty space again behind the player.
*/

void	player_move_track(t_context *context, int keycode, int x, int y)
{
	if (keycode == 122 || keycode == 119)
	{
		y--;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
	if (keycode == 115)
	{
		y++;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
	if (keycode == 113 || keycode == 97)
	{
		x--;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
	if (keycode == 110)
	{
		x++;
		mlx_put_image_to_window(context->game, context->window,
			context->data[3].img_ptr, x * 50, y * 50);
	}
}

//	Update the player sprite with an astronaut facing the direction
//	in which the player is going.

void	player_sprite_update(t_context *context, int keycode, int *x, int *y)
{
	if (keycode == 122 || keycode == 119)
	{
		context->player_pos.y--;
		mlx_put_image_to_window(context->game, context->window,
			context->data[6].img_ptr, *x * 50, *y * 50);
	}
	if (keycode == 115)
	{
		context->player_pos.y++;
		mlx_put_image_to_window(context->game, context->window,
			context->data[4].img_ptr, *x * 50, *y * 50);
	}
	if (keycode == 113 || keycode == 97)
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

/*
	Checks for a destroy_window event (such as pressing ESC or a GAME OVER),
	and checks if any of the player is attempting to make a valid move (i.e. 
	moving in one of the 4 directions using ZQSD or WASD).
*/

int	valid_move(int keycode, t_context *context, int x, int y)
{
	if (keycode == 27 || keycode == 65307)
	{
		write(1, "So long !\n", 10);
		destroy_window(context);
	}
	if ((keycode == 122 || keycode == 119) && context->map[y - 1][x] != '1')
		return (1);
	if (keycode == 115 && context->map[y + 1][x] != '1')
		return (1);
	if ((keycode == 113 || keycode == 97) && context->map[y][x - 1] != '1')
		return (1);
	if (keycode == 100 && context->map[y][x + 1] != '1')
		return (1);
	return (0);
}

/*
	If a keyboard event is detected (keycode >= 0), checks if it
	corresponds a valid move. If so, the counter for the number of moves
	is increased. 
	If a collectible is encountered, the dedicated counter decreases and an 
	empty space sprite is added in its place.
	player_move_track() updates the player's (x.y) coordinates to keep track
	of their position.
	If the player reaches the exit before the game is ended (all collectibles 
	found), the sprite corresponding to the exit is displayed again.
	Finally, if the player reaches the exit and all collectible have been found,
	the window is destroyed and the structure is freed to end the game.
	Every time the player makes a valid move, their sprite is updated to face the 
	right direction, and the total number of moves is printed.
*/

int	on_key(int keycode, t_context *context)
{
	int	*x;
	int	*y;

	x = &context->player_pos.x;
	y = &context->player_pos.y;
	if (keycode >= 0)
	{
		if (valid_move(keycode, context, *x, *y))
		{
			context->moves++;
			if (is_collectible(keycode, context->map, *x, *y))
				context->collectibles--;
			mlx_put_image_to_window(context->game, context->window,
				context->data[3].img_ptr, *x * 50, *y * 50);
			player_move_track(context, keycode, *x, *y);
			if (is_exit(context->map, *x, *y))
				mlx_put_image_to_window(context->game, context->window,
					context->data[1].img_ptr, *x * 50, *y * 50);
			if (end_game(keycode, context, *x, *y))
				destroy_window(context);
			player_sprite_update(context, keycode, x, y);
			print_moves(context, context->moves);
		}
	}
	return (1);
}
