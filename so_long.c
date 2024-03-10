/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:56 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/10 01:42:23 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(int input, t_mlx_data *main_window)
{
	handle_input(input, main_window);
	show_map(main_window->map, *main_window);
	show_player(main_window);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx_data	main_window;
	int			fd;
	char		*map;

	map = argv[1];
	fd = open(map, O_RDONLY);
	main_window.map = open_map(fd);
	init_window(&main_window);
	init_player(&main_window);
	show_map(main_window.map, main_window);
	show_player(&main_window);
	if (argc == 2)
	{
		mlx_key_hook(main_window.mlx_window, game_loop, &main_window);
		mlx_loop(main_window.mlx_ptr);
	}
	return (0);
}
