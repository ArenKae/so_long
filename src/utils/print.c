/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:32:28 by acosi             #+#    #+#             */
/*   Updated: 2023/10/01 00:02:02 by acosi            ###   ########.fr       */
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

/*
	Prints the total number of moves the player has made in the terminal.
*/

void	print_moves(t_context *context, int moves)
{
	char	*nb;
	char	*str;

	nb = ft_itoa(moves);
	str = ft_strjoin("MOVES : ", nb);
	free(nb);
	ft_putstr_fd(str, 1);
	(void)context;
	free(str);
}

// Prints a message in the terminal when the game is won.

int	win_message(void)
{
	ft_putstr_fd("YOU WIN !", 1);
	return (1);
}
