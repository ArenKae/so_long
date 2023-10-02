/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:28 by acosi             #+#    #+#             */
/*   Updated: 2023/10/01 00:03:30 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Prints a matching error message if something goes wrong during map checking.

int	print_error(int i)
{
	if (i == 0)
		ft_putstr_fd("Error\nNo path found !", 1);
	else if (i == 1)
		ft_putstr_fd("Error\nInvalid map !", 1);
	else if (i == 2)
		ft_putstr_fd("Error\nMaps should be in the map folder !", 1);
	else if (i == 3)
		ft_putstr_fd("Error\nInvalid map name !", 1);
	else if (i == 4)
		ft_putstr_fd("Error\nMap too big to fit screen !", 1);
	return (0);
}

//	Prints the collectibles counter as a string to the main window.

void	print_collectibles(t_context *context)
{
	char	*str1;
	char	*str2;
	char	*nb;

	if (context->collectibles == 0)
	{
		str1 = "All cells collected.";
		str2 = "Go back to your ship !";
		mlx_string_put(context->game, context->window, context->window_x
			/ 2 - 10, (context->window_y - 17), 0xFF005D, str1);
		mlx_string_put(context->game, context->window, context->window_x
			/ 2 - 10, (context->window_y - 5), 0xFF005D, str2);
		return ;
	}
	nb = ft_itoa(context->collectibles);
	str1 = ft_strjoin("You need ", nb);
	free(nb);
	if (context->collectibles == 1)
		str2 = ft_strjoin(str1, " more energy cell.");
	else
		str2 = ft_strjoin(str1, " more energy cells.");
	free(str1);
	mlx_string_put(context->game, context->window, context->window_x / 2 - 10,
		(context->window_y - 10), 0xFF005D, str2);
	free(str2);
}

/*
	Prints the total number of moves the player has made in the terminal
	and at the bottom of the main window. Also prints the number 
	of remaining collectibles.
	To display some messages in the window, a black sprite is printed
	first to prevent overlap with the previous messages.
*/

void	print_moves(t_context *context, int moves)
{
	char	*nb;
	char	*str;
	int		i;

	i = -1;
	nb = ft_itoa(moves);
	str = ft_strjoin("MOVES : ", nb);
	free(nb);
	while ((++i * 50) <= context->window_x)
	{
		mlx_put_image_to_window(context->game, context->window,
			context->data[12].img_ptr, i * 50, context->window_y - 30);
	}
	mlx_string_put(context->game, context->window, 20,
		(context->window_y - 10), 0xFF005D, str);
	ft_putstr_fd(str, 1);
	print_collectibles(context);
	free(str);
}

// Prints a message in the terminal when the game is won.

int	win_message(void)
{
	ft_putstr_fd("YOU WIN !", 1);
	return (1);
}
