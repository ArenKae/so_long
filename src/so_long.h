/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:34:17 by keschouf          #+#    #+#             */
/*   Updated: 2023/09/08 15:50:05 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFF_SIZE 512

# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct s_data
{
	int		*addr;
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		img_width;
	int		img_height;	
}		t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_patrol
{
	t_pos			pat_pos;
	struct s_patrol	*next;
}			t_patrol;

typedef struct s_context
{
	void	*window;
	void	*game;
	char	**map;
	char	*str;
	int		window_x;
	int		window_y;
	int		collectibles;
	int		player;
	int		moves;
	int		exit;
	int		flag;
	int		patrol;
	int		map_width;
	int		map_height;
	t_pos	player_pos;
	t_data	data[13];
}		t_context;

typedef struct s_read
{
	int				ret;
	char			buf[BUFF_SIZE];
	struct s_read	*next;
}		t_read;

int		ft_strlen(char *str);
void	free_tab(char **tab);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char const *str, int fd);
int		count_size(int n);
char	*ft_itoa(int nb);
int		get_size(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	print_move(t_context *context, int moves);
int		destroy_window(t_context *context);
void	map_parsing(t_context *context);
void	*map_init(t_context *context);
void	resize_img(t_data *tmp, t_data *data);
char	**img_paths(char **tab);
void	create_elem(t_context *context);
void	player_move(t_context *context, int keycode, int *x, int *y);
int		game_over(int keycode, t_context *context, int x, int y);
int		valid_move(int keycode, t_context *context, int x, int y);
int		is_collectibles(int keycode, char **map, int x, int y);
int		is_exit(char **map, int x, int y);
int		end_game(int keycode, t_context *context, int x, int y);
void	player_move_3(t_context *context, int x, int y);
void	player_move_2(t_context *context, int keycode, int x, int y);
int		on_key(int keycode, t_context *context);
int		fill_map(char **map, t_read *tmp, int j, int k);
int		alloc_map(char ***map, t_read *tmp, int strlen, int tablen);
int		read_file(t_read *tmp, int fd);
int		check_map_height(t_context **context, char **map);
int		check_map_lenght(t_context **context, char **map);
int		check_map_edges(t_context **context, char **map, int x, int y);
void	fill_map_data(t_context **context, char **map, int x, int y);
void	map_data_init(t_context **context);
int		check_map_data(t_context **context);
void	get_window_size(t_context **context);
char	**alloc_cpy_map(t_context **context);
int		try_move_path(char **map, int x, int y, int i);
void	make_move_path(char **map, int x, int y, int i);
int		check_final_path(char **map);
void	chck_vld_path(char **map, int x, int y);
void	assign_pos(t_context **context, int y, int x);
int		init_check_valid_path(t_context **context, char **map, int y, int x);
int		check_map_letters(t_context **context, char **map);
int		check_map(t_context **context, char **map);
void	free_list(t_read *list);
int		init_map(t_context *context, char *filename);
int		check_map_name(char *s1, char *s2);
int		check_map_name_2(char *s1, char *s2);
void	move_patrol_up(t_context *context, int y, int x);
void	move_patrol_right(t_context *context, int y, int x);
void	move_patrol_down(t_context *context, int y, int x);
void	move_patrol_left(t_context *context, int y, int x);
void	move_patrol(t_context *context, int y, int x);
void	sort_map_patrol(t_context *context);
void	patrol(t_context *context);
int		init_patrol(t_context *context);
int		print_error(int i);

#endif
