/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keschouf <keschouf@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:31:36 by keschouf          #+#    #+#             */
/*   Updated: 2023/06/11 17:41:18 by keschouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_context	context;

	if (ac == 2)
	{
		if (!check_map_name(av[1], ".ber"))
			return (0);
		if (!(init_map(&context, av[1])))
			return (0);
		context.game = mlx_init();
		create_elem(&context);
		map_init(&context);
		map_parsing(&context);
		mlx_hook(context.window, 17, 1L << 2, destroy_window, &context);
		mlx_key_hook(context.window, on_key, &context);
		mlx_loop_hook(context.game, init_patrol, &context);
		mlx_loop(context.game);
	}
	return (0);
}
