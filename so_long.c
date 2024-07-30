/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:56 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/30 15:55:53 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_loop(t_mlx_data main_window)
{
	show_map(main_window);
	show_player(&main_window);
	mlx_key_hook(main_window.mlx_window, game_loop, &main_window);
	mlx_hook(main_window.mlx_window, 17, 0, &mouse_use, &main_window);
	mlx_loop(main_window.mlx_ptr);
}

int	game_loop(int input, t_mlx_data *main_window)
{
	handle_input(input, main_window);
	show_map(*main_window);
	show_player(main_window);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx_data	main_window;
	t_pos		pos;
	int			fd;
	char		*map;

	map = argv[1];
	fd = open(map, O_RDONLY);
	if (fd == -1 || argc != 2 || !check_map_name(map))
		return (perror("cd"), EXIT_FAILURE);
	main_window.map = open_map(fd);
	if (main_window.map == NULL || !check_map(&main_window) || \
		!create_str_map(&main_window))
		return (EXIT_FAILURE);
	init_player(&main_window);
	pos.max_x = main_window.max_x;
	pos.max_y = main_window.max_y;
	if (main_window.max_x > 50 || main_window.max_y > 24)
		return (ft_printf("Map is too big"), EXIT_FAILURE);
	if (!(check_way_possible(main_window.str_map, main_window.player.x_pos, \
	main_window.player.y_pos, pos)))
		return (ft_printf("The map is not finishable"), 0);
	if (init_window(&main_window) == -1)
		return (free(main_window.str_map), clean_close(&main_window), 1);
	launch_loop(main_window);
	return (free(main_window.str_map), clean_close(&main_window), EXIT_SUCCESS);
}
