/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:56 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/17 00:03:36 by kenzo            ###   ########.fr       */
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

int	check_map_name(char *map_name)
{
	const char	*extension;
	size_t		filename_len;
	size_t		extension_len;

	extension = ".ber";
	filename_len = strlen(map_name);
	extension_len = strlen(extension);
	if (filename_len < extension_len)
		return (FALSE);
	return (ft_strcmp(map_name + filename_len - extension_len, extension) == 0);
}
#define VISITED 'V'

int has_path(t_map_data *map, int x, int y, char target) {
  // Check for base cases
  if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
    return 0; // Out of map bounds
  }
  if (map[y * SIZE + x].case_type == WALL) {
    return 0; // Hit a wall
  }
  if (map[y * SIZE + x].case_type == VISITED) {
    return 0; // Already visited
  }

  // Mark current node as visited
  map[y * SIZE + x].case_type = VISITED;

  // Check if target is found
  if (map[y * SIZE + x].case_type == target) {
    return 1; // Path found
  }

  // Recursively explore neighbors (up, down, left, right)
  int has_up_path = has_path(map, x, y - 1, target);
  int has_down_path = has_path(map, x, y + 1, target);
  int has_left_path = has_path(map, x - 1, y, target);
  int has_right_path = has_path(map, x + 1, y, target);

  // Reset the visited flag for backtracking
  map[y * SIZE + x].case_type = map[y * SIZE + x].is_valid;

  // Return true if any neighbor has a path
  return has_up_path || has_down_path || has_left_path || has_right_path;
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
	if (main_window.map == NULL || check_map(&main_window) == 0)
		return (FALSE);
	int start_x = main_window.player.x_pos; // Get player's starting position
	int start_y = main_window.player.y_pos;
	if (has_path(main_window.map, start_x, start_y, 'E')) {
		printf("There exists a path to the exit!\n");
	} else {
		printf("No path to the exit found!\n");
}
	init_window(&main_window);
	init_player(&main_window);
	show_map(main_window.map, main_window);
	show_player(&main_window);
	if (argc == 2)
	{
		mlx_key_hook(main_window.mlx_window, game_loop, &main_window);
		mlx_hook(main_window.mlx_window, 17, 0, (void *)exit, 0);
		mlx_loop(main_window.mlx_ptr);
	}
	return (FALSE);
}
