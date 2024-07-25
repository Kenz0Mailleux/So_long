/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:43:00 by kenzo             #+#    #+#             */
/*   Updated: 2024/06/13 16:08:09 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_map(t_mlx_data main_window)
{
	while (main_window.map)
	{
		if (main_window.map->case_type == '1')
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, main_window.wall_img, \
			main_window.map->x_pos * SIZE, main_window.map->y_pos * SIZE);
		else if (main_window.map->case_type == 'E')
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, main_window.exit_img, \
			main_window.map->x_pos * SIZE, main_window.map->y_pos * SIZE);
		else if (main_window.map->case_type == 'C')
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, main_window.collectible_img, \
			main_window.map->x_pos * SIZE, main_window.map->y_pos * SIZE);
		else
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, main_window.sol_img, \
			main_window.map->x_pos * SIZE, main_window.map->y_pos * SIZE);
		main_window.map = main_window.map->next;
	}
}

void	show_player(t_mlx_data *main_window)
{
	mlx_put_image_to_window(main_window->mlx_ptr, main_window->mlx_window, \
	main_window->player_img, main_window->player.x_pos * SIZE, \
	main_window->player.y_pos * SIZE);
}
