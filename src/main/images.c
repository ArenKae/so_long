/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 20:03:39 by acosi             #+#    #+#             */
/*   Updated: 2023/09/30 23:59:21 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//	Allocates memory for an array to store 
//	the paths of  all .xpm images used as sprites.

char	**malloc_img_paths(char **tab)
{
	tab = malloc(sizeof(char *) * 16);
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
	tab[9] = "img/a.xpm\0";
	tab[10] = "img/b.xpm\0";
	tab[11] = "img/c.xpm\0";
	tab[12] = "img/B.xpm\0";
	tab[13] = "img/E1.xpm\0";
	tab[14] = "img/E2.xpm\0";
	tab[15] = NULL;
	return (tab);
}

/*
	This function takes the data from the tmp image and converts
	it to a new t_data corresponding to the image resized to 50x50 pixels.
	Each image is treated as an array of contiguous pixels where i corresponds
	to the rows and j to the columns. In case the source image is not
	rectangular, k takes the width and makes it equals to the height. k is then
	divided by 50 to represent the indent between each significant pixels that 
	will be kept in the resized image.
	The final image will be 50x50, so we will keep only 50 rows and 50 columns
	worth of pixels from the source image (thus i < 50 and j < 50).
	data->addr is the adress of the memory area where the image is stored. From
	this adress, the first bits represent the color of the first pixel in the first 
	line of the image. The second group of bits represent the second pixel, etc. 
	That way, data->addr[i * 50] represents the 50th pixel of row i.
	tmp->addr[i * tmp->img_width * k + j * k] is the adress of the byte from 
	the original image, where i and j varies from 0 to 50 to recreate the new image.
*/

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

/*
	Uses the Minilibx to create  and resize every sprites needed by the game.
	malloc_img_paths() allocates memory for an array to store the paths of 
	all .xpm files.
	mlx_xpm_file_to_image(): Converts the .xpm files to MLX image pointers.
	mlx_get_data_addr(): Returns informations about the image created by
	mlx_xpm_file_to_image(), allowing them to be modified later.
	The context structure contains a data[] array that holds a t_data struct
	for every xpm image. mlx_new_image is used to create every image in memory
	using this array.
	The t_data tmp is used to first create the raw images with their native
	dimensions, before resizing to them 50 pixels with resize_img().
*/

void	create_images(t_context *context)
{
	char	**img_path;
	int		i;
	t_data	tmp;

	i = 0;
	img_path = NULL;
	img_path = malloc_img_paths(img_path);
	while (i < 15)
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
		mlx_destroy_image(context->game, tmp.img_ptr);
		i++;
	}
	free(img_path);
}

/*
	This function parses through the whole map and put the sprites
	corresponding to each element in the window.
	The name of each .xpm files are stored in the string *s for easy access.
	Every time the string matches the element at the map's current position 
	(1, E, C, 0 or P), the mlx function puts the corresponding sprite 
	for this element at the correct position of the window.
	A special function handles the borders of the map (1) to add visual variations.
*/

void	put_sprites(t_context *context)
{
	const char	*s = "1EC0P---X";
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
			while (s[i] != context->map[y][x])
				i++;
			mlx_put_image_to_window(context->game, context->window,
				context->data[i].img_ptr, x * 50, y * 50);
		}
	}
}
