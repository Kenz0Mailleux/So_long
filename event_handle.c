/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:19:12 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/14 00:56:07 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(int input, t_mlx_data *main_window)
{
	if (input == ON_KEYUP || input == 'z')
	{
		main_window->player.y_pos -= 1;
		if (check_collision(main_window))
			main_window->player.y_pos += 1;
	}
	else if (input == ON_KEYDOWN || input == 's')
	{
		main_window->player.y_pos += 1;
		if (check_collision(main_window))
			main_window->player.y_pos -= 1;
	}
	else if (input == 'd')
	{
		main_window->player.x_pos += 1;
		if (check_collision(main_window))
			main_window->player.x_pos -= 1;
	}
	else if (input == 'q')
	{
		main_window->player.x_pos -= 1;
		if (check_collision(main_window))
			main_window->player.x_pos += 1;
	}
	return (0);
}

int	take_collectible(t_mlx_data *main_window)
{
	t_map_data	*current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->x_pos == main_window->player.x_pos && \
		current->y_pos == main_window->player.y_pos)
		{
			if (current->case_type == 'C')
			{
				current->case_type = '0';
				return (0);
			}
		}
		current = current->next;
	}
	return (0);
}

int	handle_input(int input, t_mlx_data *main_window)
{
	if (input == XK_Escape)
		clean_close(main_window);
	else
	{
		player_move(input, main_window);
		take_collectible(main_window);
		if (check_endable(main_window))
			main_window->endable = 1;
		if (check_win(main_window))
			clean_close(main_window);
	}
	return (FALSE);
}

int	mouse_use(int input, t_mlx_data *main_window)
{
	clean_close(main_window);
	return (0);
}

void	clean_close(t_mlx_data *main_window)
{
	mlx_destroy_window(main_window->mlx_ptr, main_window->mlx_window);
	mlx_destroy_display(main_window->mlx_ptr);
	free_list(main_window->map);
	free(main_window->mlx_ptr);
	exit (TRUE);
}

//void victory_screen(t_mlx_data *main_window)