/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:50:02 by acosi             #+#    #+#             */
/*   Updated: 2023/09/29 16:26:56 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	Frees the t_read linked list for memory management.
	tmp holds the pointer to the next node, while the previous one is freed.
	i is used to keep track of the number of nodes processed in the list.
	If there is only one node, i = 0 and nothing is freed because the first
	node is not malloc'd (it is in stack memory, not heap).
*/

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

//	Frees the map array stored in context->map structure.

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map) != NULL && (*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free((*map));
	*map = NULL;
}

//	Frees the copy of the map array used to perform path checking.

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

/*
	Destroys every images in memory and terminates the main window,
	before freeing the map in the structure.Finally, the mlx pointer
	is freed using the dedicated mlx function mlx_destroy_display().
*/

int	destroy_window(t_context *context)
{
	int	i;

	i = 0;
	while (i <= 14)
	{
		mlx_destroy_image(context->game, context->data[i].img_ptr);
		i++;
	}
	mlx_destroy_window(context->game, context->window);
	free_map(&context->map);
	mlx_destroy_display(context->game);
	free(context->game);
	exit(0);
}

int	free_context(t_context *context)
{
	free_map(&context->map);
	mlx_destroy_display(context->game);
	free(context->game);
	print_error(4);
	return (0);
}
