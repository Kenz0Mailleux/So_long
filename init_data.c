/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:17:46 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/10 01:51:38 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_mlx_data *main_window)
{
	main_window->mlx_ptr = mlx_init();
	if (main_window->mlx_ptr == NULL)
		return (MLX_ERROR);
	main_window->mlx_window = mlx_new_window(main_window->mlx_ptr, \
							WINDOW_HEIGHT, WINDOW_WIDTH, "Jeu");
	if (main_window->mlx_window == NULL)
	{
		mlx_destroy_display(main_window->mlx_ptr);
		free(main_window->mlx_ptr);
		return (MLX_ERROR);
	}
	main_window->endable = 0;
	return (0);
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
	main_window->player.move = 1;
}
