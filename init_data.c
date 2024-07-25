/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:17:46 by kenzo             #+#    #+#             */
/*   Updated: 2024/06/13 14:48:02 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_mlx_data *main_window)
{
	main_window->mlx_ptr = mlx_init();
	if (main_window->mlx_ptr == NULL)
		return (MLX_ERROR);
	main_window->mlx_window = mlx_new_window(main_window->mlx_ptr, \
	main_window->window_width * 50, main_window->window_height * 50, "Jeu");
	if (main_window->mlx_window == NULL)
	{
		free(main_window->mlx_ptr);
		return (MLX_ERROR);
	}
	init_img(main_window);
	main_window->endable = 0;
	return (FALSE);
}

void	init_player_pos(t_mlx_data *main_window)
{
	t_map_data	*current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->case_type == 'P')
		{
			main_window->player.x_pos = current->x_pos;
			main_window->player.y_pos = current->y_pos;
		}
		current = current->next;
	}
}

void	init_player(t_mlx_data *main_window)
{
	init_player_pos(main_window);
	main_window->player.move = 0;
}

void	init_img(t_mlx_data *main_window)
{
	int		img_width;
	int		img_height;

	img_width = 50;
	img_height = 50;
	main_window->player_img = mlx_xpm_file_to_image(main_window->mlx_ptr, \
	"textures/Player.xpm", &img_width, &img_height);
	main_window->sol_img = mlx_xpm_file_to_image(main_window->mlx_ptr, \
	"textures/TilesetField.xpm", &img_width, &img_height);
	main_window->wall_img = mlx_xpm_file_to_image(main_window->mlx_ptr, \
	"textures/TilesetNature.xpm", &img_width, &img_height);
	main_window->collectible_img = mlx_xpm_file_to_image(main_window->mlx_ptr, \
	"textures/Collectible.xpm", &img_width, &img_height);
	main_window->exit_img = mlx_xpm_file_to_image(main_window->mlx_ptr, \
	"textures/TilesetExit.xpm", &img_width, &img_height);
}
