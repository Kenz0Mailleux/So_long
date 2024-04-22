/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:43:00 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/22 17:24:17 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	put_assets(t_mlx_data main_window, const char *texture_name)
// {
// 	void	*img;
// 	int		img_width;
// 	int		img_height;

// 	img_width = SIZE;
// 	img_height = SIZE;
// 	img = mlx_xpm_file_to_image(main_window.mlx_ptr, \
// 			(char *)texture_name, &img_width, &img_height);
// 	mlx_put_image_to_window(main_window.mlx_ptr, \
// 			main_window.mlx_window, img, main_window.map->x_pos * SIZE, \
// 			main_window.map->y_pos * SIZE);
// }

// void	show_map(t_map_data *map, t_mlx_data main_window)
// {
// 	while (main_window.map)
// 	{
// 		if (main_window.map->case_type == '1')
// 			put_assets(main_window, "textures/TilesetNature.xpm");
// 		else if (main_window.map->case_type == 'E')
// 			put_assets(main_window, "textures/TileseExit.xpm");
// 		else if (main_window.map->case_type == 'C')
// 			put_assets(main_window, "textures/Collectible.xpm");
// 		else
// 			put_assets(main_window, "textures/TilesetField.xpm");
// 		main_window.map = main_window.map->next;
// 	}
// }


void	show_map(t_map_data *map, t_mlx_data main_window)
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
	main_window->player_img, main_window->player.x_pos * SIZE, main_window->player.y_pos * SIZE);
}
