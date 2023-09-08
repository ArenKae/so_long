/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:25:13 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 17:44:18 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_read *list)
{
	t_read	*tmp;
	int		i;

	i = 0;
	while (list->next)
	{
		if (list->next)
			tmp = list->next;
		if (i > 0)
			free(list);
		list = tmp;
		i++;
	}
	if (list && i > 0)
		free(list);
}

int	destroy_window(t_context *context)
{
	int	i;

	i = 0;
	while (i <= 11)
	{
		mlx_destroy_image(context->game, context->data[i].img_ptr);
		i++;
	}
	mlx_destroy_window(context->game, context->window);
	free(context->map);
	exit(0);
}
