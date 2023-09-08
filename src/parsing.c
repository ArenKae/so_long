/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:18:03 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 17:42:48 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_parsing(t_context *context)
{
	const char	*a = "1EC0P123X123";
	int			x;
	int			y;
	int			i;

	y = -1;
	while (++y < (context->map_height))
	{
		x = -1;
		while (++x < (context->map_width))
		{
			i = 0;
			while (a[i] != context->map[y][x])
				i++;
			mlx_put_image_to_window(context->game, context->window,
				context->data[3].img_ptr, x * 50, y * 50);
			mlx_put_image_to_window(context->game, context->window,
				context->data[i].img_ptr, x * 50, y * 50);
		}
	}
}

void	*map_init(t_context *context)
{
	context->window = mlx_new_window(context->game,
			context->window_x, context->window_y, "Game");
	return (context->window);
}

void	resize_img(t_data *tmp, t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = tmp->img_width;
	if (k > tmp->img_height)
		k = tmp->img_height;
	k = k / 50;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			data->addr[i * 50 + j] = tmp->addr[i * tmp->img_width * k + j * k];
			j++;
		}
		i++;
	}
}

char	**img_paths(char **tab)
{
	tab = malloc(sizeof(char *) * 13);
	if (!tab)
		return (NULL);
	tab[0] = "img/1.xpm\0";
	tab[1] = "img/E.xpm\0";
	tab[2] = "img/C.xpm\0";
	tab[3] = "img/0.xpm\0";
	tab[4] = "img/P.xpm\0";
	tab[5] = "img/P1.xpm\0";
	tab[6] = "img/P2.xpm\0";
	tab[7] = "img/P3.xpm\0";
	tab[8] = "img/X.xpm\0";
	tab[9] = "img/X1.xpm\0";
	tab[10] = "img/X2.xpm\0";
	tab[11] = "img/X3.xpm\0";
	tab[12] = NULL;
	return (tab);
}

void	create_elem(t_context *context)
{
	char	**img_path;
	int		i;
	t_data	tmp;

	i = 0;
	img_path = NULL;
	img_path = img_paths(img_path);
	while (i < 12)
	{
		tmp.img_ptr = mlx_xpm_file_to_image(context->game, img_path[i],
				&tmp.img_width, &tmp.img_height);
		tmp.addr = (int *)mlx_get_data_addr(tmp.img_ptr,
				&tmp.bits_per_pixel, &tmp.size_line, &tmp.endian);
		context->data[i].img_ptr = mlx_new_image(context->game, 50, 50);
		context->data[i].addr = (int *)mlx_get_data_addr(
				context->data[i].img_ptr, &context->data[i].bits_per_pixel,
				&context->data[i].size_line, &context->data[i].endian);
		resize_img(&tmp, &context->data[i]);
		i++;
	}
	free(img_path);
}
