/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:31:16 by acosi             #+#    #+#             */
/*   Updated: 2023/10/01 01:47:55 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
	Reads the map file and stores its content in struct tmp->buf. The map is read
	by chunks of BUFF_SIZE (512 bytes) and the return value is stored in tmp->ret. 
	read() returns the number of bytes that were read. If that number is equal to 
	BUFF_SIZE, it means the buffer has run out of space to write, and a new node
	of the linked list is created to continue reading until the loop ends.
*/

int	read_file(t_read *tmp, int fd)
{
	tmp->ret = read(fd, tmp->buf, BUFF_SIZE);
	while (tmp->ret == BUFF_SIZE)
	{
		tmp->next = malloc(sizeof(*tmp->next));
		if (!tmp->next)
			return (0);
		tmp = tmp->next;
		tmp->ret = read(fd, tmp->buf, BUFF_SIZE);
	}
	tmp->next = NULL;
	return (1);
}

/*
	Calculates and allocates memory for the context->map structure to store data 
	from the map in a 2D array of char *. 'tablen' is the nbr of rows, and 
	'tabwidth' is the nbr of char for each row. 
	'tabwidth' starts at 1 to account for the null-terminator of the row, and 
	'tablen' starts at 2 for the first row and the null-terminator of the array. 
	First, we browses through the buffer from read() functionto increment 
	'tabwidth' until a '\n' character is encountered. 
	Then, 'tablen' is incremented every time a newline is found. 
	Finally, we allocate memory, first for an array of pointers, that represent
	the rows of the map array. Then, for the number of char needed for each
	row of the map.
*/

int	alloc_map(char ***map, t_read *tmp, int tabwidth, int tablen)
{
	int	i;

	while (tabwidth++ < tmp->ret)
		if (tmp->buf[tabwidth - 1] == '\n')
			break ;
	while (tmp)
	{
		i = -1;
		while (++i < tmp->ret)
			if (tmp->buf[i] == '\n')
				tablen++;
		tmp = tmp->next;
	}
	*map = malloc(sizeof(char *) * tablen);
	if (!(*map))
		return (0);
	i = -1;
	while (i < tablen - 2)
		(*map)[++i] = malloc(sizeof(char) * tabwidth);
	return (1);
}

/*
	Copy the data from the read() buffer tmp->buff to the 2D array 
	created with alloc_map().
	j and k are initialized at 0 and sent via the prototype for the norm.
*/

int	fill_map(char **map, t_read *tmp, int j, int k)
{
	int	i;

	while (tmp)
	{
		i = -1;
		while (++i < tmp->ret)
		{
			if (tmp->buf[i] == '\n')
			{
				map[k][j] = '\0';
				j = 0;
				k++;
			}
			else
			{
				map[k][j] = tmp->buf[i];
				j++;
			}
		}
		tmp = tmp->next;
	}
	map[k][j] = '\0';
	map[k + 1] = NULL;
	return (1);
}

/*
	Creates the map of the game and performs basic checks on it. 
	First, the map is read from the .ber file and its content is stored in a buffer 
	from the t_read structure. Then, a 2D array is allocated to hold all the 
	data from the map in memory. The map array is filled with the content of 
	the read() buffer, before freeing the t_read linked list. Finally, we check 
	the 2D array to verify that the map is correct and valid before going further.
	context->game is initialized here for the get_window_size() function called in
	check_map(), to prevent a segfault when cheking screen size and mlx is not
	yet initialized.
*/

int	init_map(t_context *context, char *filename)
{
	int		fd;
	t_read	tmp_first;

	context->game = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(0);
		return (0);
	}
	if (!read_file(&tmp_first, fd))
		return (0);
	close(fd);
	if (!alloc_map(&context->map, &tmp_first, 1, 2))
		return (0);
	fill_map(context->map, &tmp_first, 0, 0);
	free_list(&tmp_first);
	if (!check_map(&context, context->map))
	{
		free_map(&context->map);
		return (0);
	}
	return (1);
}
