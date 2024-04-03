/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:10:03 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/03 15:10:52 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_list(t_map_data *map)
{
	while (map != NULL)
	{
		free(map);
		map = map->next;
	}
}

void	clean_close(t_mlx_data *main_window)
{
	mlx_destroy_window(main_window->mlx_ptr, main_window->mlx_window);
	mlx_destroy_display(main_window->mlx_ptr);
	free_list(main_window->map);
	free(main_window->mlx_ptr);
	exit (TRUE);
}
