/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:30:53 by acosi             #+#    #+#             */
/*   Updated: 2023/09/29 16:21:55 by acosi            ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>

/* STRUCTURES */

// Read .ber file
typedef struct s_read
{
	int				ret;
	char			buf[BUFF_SIZE];
	struct s_read	*next;
}		t_read;

// Minilibx images
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

// Player position
typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

// Main structure
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
	int		loop;
	t_pos	player_pos;
	t_data	data[13];
}		t_context;

/* FUNCTIONS */

// Check map name
int		check_map_name(char *s1, char *s2);
int		check_map_name_2(char *s1, char *s2);

// Map creation
int		init_map(t_context *context, char *filename);
int		read_file(t_read *tmp, int fd);
int		alloc_map(char ***map, t_read *tmp, int tabwidth, int tablen);
int		fill_map(char **map, t_read *tmp, int j, int k);

// Check map 1
void	init_map_data(t_context **context);
void	count_map_data(t_context **context, char **map, int x, int y);
int		check_map_data(t_context **context);
int		get_window_size(t_context *context);
int		check_map(t_context **context, char **map);

// Check map 2
int		check_map_height(t_context **context, char **map);
int		check_map_width(t_context **context, char **map);
int		check_map_edges(t_context **context, char **map, int x, int y);
int		check_map_letters(t_context **context, char **map);

//	Check Path
char	**alloc_cpy_map(t_context **context);
void	assign_player_pos(t_context **context, int y, int x);
int		check_final_path(char **map);
int		init_check_valid_path(t_context **context, char **map, int y, int x);

// Check Path 2
int		try_move_path(char **map, int x, int y, int i);
void	make_move_path(char **map, int x, int y, int i);
void	check_valid_path(char **map, int x, int y);

// Images manipulation
char	**malloc_img_paths(char **tab);
void	resize_img(t_data *tmp, t_data *data);
void	create_images(t_context *context);
void	put_border(t_context *context, int x, int y);
void	put_sprites(t_context *context);

// Game
void	player_move_track(t_context *context, int keycode, int x, int y);
void	player_sprite_update(t_context *context, int keycode, int *x, int *y);
int		valid_move(int keycode, t_context *context, int x, int y);
int		on_key(int keycode, t_context *context);

// Game 2
int		is_exit(char **map, int x, int y);
int		end_game(int keycode, t_context *context, int x, int y);
int		game_over(int keycode, t_context *context, int x, int y);
int		is_collectible(int keycode, char **map, int x, int y);

// Patrol bonus
void	move_patrol(t_context *context, int y, int x);
void	reset_patrol_markers(t_context *context);
void	patrol(t_context *context);
int		init_bonus(t_context *context);

// Patrol moves
void	move_patrol_up(t_context *context, int y, int x);
void	move_patrol_right(t_context *context, int y, int x);
void	move_patrol_down(t_context *context, int y, int x);
void	move_patrol_left(t_context *context, int y, int x);

// Animations
int		find_exit(t_context *context, char **map, int *x, int *y);
int		ship_anim(t_context *context, int x, int y);

// Print
int		print_error(int i);
void	print_collectibles(t_context *context);
void	print_moves(t_context *context, int moves);
int		win_message(void);

// Memory management
void	free_list(t_read *list);
void	free_map(char ***map);
void	free_tab(char **tab);
int		destroy_window(t_context *context);
int		free_context(t_context *context);

// Utils
int		ft_strlen(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *str, int fd);

// Utils 2
int		count_size(int n);
char	*ft_itoa(int nb);
int		get_size(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
