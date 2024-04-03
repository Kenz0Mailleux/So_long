/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:45:45 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/20 16:19:17 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision(t_mlx_data *main_window)
{
	t_map_data	*current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->x_pos == main_window->player.x_pos && \
			current->y_pos == main_window->player.y_pos)
		{
			if (current->case_type == WALL)
				return (1);
			main_window->player.move += 1;
			ft_putnbr_fd(main_window->player.move, 1);
			write(1, "\n", 1);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	check_win(t_mlx_data *main_window)
{
	t_map_data	*current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->x_pos == main_window->player.x_pos \
		&& current->y_pos == main_window->player.y_pos)
		{
			if (current->case_type == 'E' && main_window->endable == 1)
				return (1);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	check_endable(t_mlx_data *main_window)
{
	t_map_data	*current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->case_type == 'C')
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
