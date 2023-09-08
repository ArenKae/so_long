/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:08:07 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/12 15:08:09 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
