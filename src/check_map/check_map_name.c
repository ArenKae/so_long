/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:31:50 by acosi             #+#    #+#             */
/*   Updated: 2023/09/27 17:04:58 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	Checks that the first argument passed to the program begins 
	with map/.
*/

int	check_map_name_2(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/*
	Checks that the first argument passed to the program is a valid
	.ber file located in the map/ directory.
	s1 = av[1] and s2 = ".ber"
*/

int	check_map_name(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!check_map_name_2(s1, "map/"))
		return (print_error(2));
	while (s1[i])
	{
		while (s1[i] == s2[j])
		{
			j++;
			i++;
			if (s2[j] == '\0' && i == ft_strlen(s1))
				if (ft_strlen(s1) - ft_strlen("/map") > 4)
					return (1);
		}
		i++;
	}
	return (print_error(3));
}
