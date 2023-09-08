/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:14:13 by keschouf          #+#    #+#             */
/*   Updated: 2023/09/08 15:27:23 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				map[0][j] = '\0';
				j++;
				map[k] = &map[0][j];
				k++;
				continue ;
			}
			map[0][j] = tmp->buf[i];
			j++;
		}
		tmp = tmp->next;
	}
	map[0][j] = '\0';
	map[k] = NULL;
	return (1);
}



int	alloc_map(char ***map, t_read *tmp, int strlen, int tablen)
{
	int	i;

	while (tmp)
	{
		i = -1;
		while (++i < tmp->ret)
		{
			if (tmp->buf[i] == '\n')
				tablen++;
		}
		strlen += tmp->ret;
		tmp = tmp->next;
	}
	tablen++;
	strlen++;
	*map = malloc(sizeof(char *) * tablen + sizeof(char) * strlen);
	if (!(*map))
		return (0);
	map[0][0] = (char *)&map[0][tablen];
	return (1);
}

int	init_map(t_context *context, char *filename)
{
	int		fd;
	t_read	tmp_first;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(0);
		return (0);
	}
	if (!read_file(&tmp_first, fd))
		return (0);
	close(fd);
	if (!alloc_map(&context->map, &tmp_first, 0, 1))
		return (0);
	fill_map(context->map, &tmp_first, 0, 1);
	free_list(&tmp_first);
	if (!check_map(&context, context->map))
	{
		free(context->map);
		return (0);
	}
	return (1);
}

/*	Reads the map file and stores its content in struct tmp->buf. The map is read
	by chunks of BUFF_SIZE (512 bytes) and the return value is  stored in tmp->ret. 
	read() returns the number of bytes that was read. If that number is equal to 
	BUFF_SIZE, it means the buffer has run out of space to write, and a new node
	of the linked list is created to continue reading until the loop ends. */

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
