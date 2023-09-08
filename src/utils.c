/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:24:08 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 14:24:34 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648\n", 12);
	else
	{
		if (nb < 0)
		{
			nb = -nb;
			ft_putchar_fd('-', fd);
		}
		if (nb >= 10)
			ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd((nb % 10 + '0'), fd);
	}
}

void	ft_putstr_fd(char const *str, int fd)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
	write(1, "\n", 1);
}
