/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:24:42 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 17:44:04 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_size(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = 1;
	if (nb < 0)
	{
		nb = -nb;
		count++;
	}
	while (nb > 9)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	nbr = nb;
	str = (char *)malloc(sizeof(char) * count_size(nb) + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
		str[0] = '-';
	if (nbr < 0)
		nbr = -nbr;
	str[count_size(nb) - i++] = '\0';
	while (nbr > 9)
	{
		str[count_size(nb) - i++] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	str[count_size(nb) - i++] = (nbr % 10) + '0';
	return (str);
}

int	get_size(char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
		i++;
	j = i;
	i = 0;
	while (s2[i])
		i++;
	j = j + i;
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	str = malloc(sizeof(char) * (get_size(s1, s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	j = i;
	i = -1;
	while (s2[++i])
	{
		str[j] = s2[i];
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	print_move(t_context *context, int moves)
{
	char	*nb;
	char	*str;
	int		i;

	i = -1;
	nb = ft_itoa(moves);
	str = ft_strjoin("MOVES : ", nb);
	free(nb);
	while (++i < 3)
	{
		mlx_put_image_to_window(context->game, context->window,
			context->data[0].img_ptr, i * 50, 0);
	}
	mlx_string_put(context->game, context->window, 5, 5, 0xFF005D, str);
	ft_putstr_fd(str, 1);
	free(str);
}
