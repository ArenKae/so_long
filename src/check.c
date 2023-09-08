/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:09:40 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 14:10:16 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_height(t_context **context, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][0] == '\0' || map[i][0] == '\n')
		{
			j = i;
			break ;
		}
		i++;
		j = i;
	}
	(*context)->map_height = i;
	i = 0;
	while (map[j])
	{
		if (map[j][0] && (map[j][0] != '\0' || map[j][0] != '\n'))
			return (0);
		j++;
	}
	return (1);
}

int	check_map_lenght(t_context **context, char **map)
{
	int	lenght;
	int	i;

	i = 1;
	lenght = ft_strlen(map[0]);
	while (i < (*context)->map_height)
	{
		if (ft_strlen(map[i]) != lenght)
			return (0);
		i++;
	}
	(*context)->map_width = lenght;
	return (1);
}

int	check_map_letters(t_context **context, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (y < (*context)->map_height)
	{
		x = 0;
		while (x < (*context)->map_width)
		{
			if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != 'P' &&
					map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'X')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(t_context **context, char **map)
{
	if (!check_map_height(context, map))
		return (print_error(1));
	if (!check_map_lenght(context, map))
		return (print_error(1));
	if (!check_map_edges(context, map, 0, 0))
		return (print_error(1));
	if (!check_map_letters(context, map))
		return (print_error(1));
	map_data_init(context);
	fill_map_data(context, map, 0, 0);
	if (!check_map_data(context))
		return (print_error(1));
	if (!init_check_valid_path(context, map, -1, -1))
		return (print_error(0));
	get_window_size(context);
	return (1);
}
