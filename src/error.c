/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:52:36 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/12 13:52:38 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(int i)
{
	if (i == 0)
		ft_putstr_fd("No path found !", 1);
	if (i == 1)
		ft_putstr_fd("Invalid map !", 1);
	if (i == 2)
		ft_putstr_fd("Maps should be in the map folder !", 1);
	if (i == 3)
		ft_putstr_fd("Invalid map name !", 1);
	return (0);
}
