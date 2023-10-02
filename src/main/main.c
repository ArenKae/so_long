/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:31:23 by acosi             #+#    #+#             */
/*   Updated: 2023/09/29 20:37:52 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../minilibx/mlx_int.h"

// Creates a new window instance with the right dimensions.

void	*window_init(t_context *context)
{
	context->window = mlx_new_window(context->game,
			context->window_x, context->window_y, "So Long");
	return (context->window);
}

/*
	The program first check that its first argument is a valid
	.ber map located in the map/ directory. Then, the init_map()
	function reads the data from the .ber file, stores it in a 2D array, 
	parses through the map array to fill the context structure with data 
	related to the game, and checks if the map is valid.
	mlx_init() initialises the MLX library by creating a structure to hold
	all the data required for the MLX to function. It is accessed via a void ptr
	'context.game'.
	get_window_size() checks that the window cand fit the screen and exit the 
	program with an error message if not.
	create_images() fetches the paths to all .xpm files and uses the MLX to create
	and resize the sprites in memory.
	window_init() creates the main window, before put_sprites() parses the map and
	put the sprites corresponding to each elements of the game inside the window.
	mlx_hook() allows the program to listen for X11 events such as keyboard and 
	mouse interactions. This particular mlx_hook() call allows the "X" button
	to terminate the window by calling destroy_window() when the mouse clicks &
	releases it. The aliases come from the X11 header and stands for coded values
	telling the X server to destroy the window when the key is released.
	mlx_key_hook() will call the on_key() function every time a keyboard event
	occurs in the main window.
	Finally, mlx_loop() loops over the MLX pointer, triggering each hook in order 
	of registration.
*/

int	main(int ac, char **av)
{
	t_context	context;

	if (ac == 2)
	{
		if (!check_map_name(av[1], ".ber"))
			return (0);
		if (!(init_map(&context, av[1])))
			return (0);
		context.game = mlx_init();
		if (!context.game)
			return (1);
		if (!get_window_size(&context))
			return (free_context(&context));
		create_images(&context);
		window_init(&context);
		put_sprites(&context);
		print_moves(&context, context.moves);
		mlx_hook(context.window, DestroyNotify, KeyReleaseMask,
			destroy_window, &context);
		mlx_key_hook(context.window, on_key, &context);
		mlx_loop(context.game);
	}
	return (0);
}
