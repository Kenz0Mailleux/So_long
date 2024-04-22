/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:56 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/22 14:35:15 by kenzo            ###   ########.fr       */
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

	if (argc != 2)
		return (FALSE);
	map = argv[1];
	if (!check_map_name(map))
		return (FALSE);
	fd = open(map, O_RDONLY);
	main_window.map = open_map(fd);
	create_str_map(&main_window);
	if (main_window.map == NULL || check_map(&main_window) == 0)
		return (free_list(main_window.map), FALSE);
	init_player(&main_window);
	if (!(check_way_possible(main_window.str_map, main_window.player.x_pos, \
	main_window.player.y_pos, main_window.max_x, main_window.max_y)))
		return (printf("The map is not finishable"), 0);
	init_window(&main_window);
	free(main_window.str_map);
	show_map(main_window.map, main_window);
	show_player(&main_window);
	if (argc == 2)
	{
		mlx_key_hook(main_window.mlx_window, game_loop, &main_window);
		mlx_hook(main_window.mlx_window, 17, 0, (void *)exit, 0);
		mlx_loop(main_window.mlx_ptr);
	}
	clean_close(&main_window);
	return (FALSE);
}
