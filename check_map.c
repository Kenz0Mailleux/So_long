/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:13:05 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/25 16:11:14 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_map_data *map, int count, int max_x)
{
	t_map_data	*current;

	current = map;
	while (current != NULL)
	{
		while (current->next != NULL && current->y_pos == current->next->y_pos)
		{
			count++;
			current = current->next;
		}
		if (count != max_x)
			return (ft_printf("The map is not rectangular.\n"), FALSE);
		count = 1;
		current = current->next;
	}
	return (TRUE);
}

int	check_wall_map(t_map_data *map, int max_x, int max_y)
{
	t_map_data	*current;

	current = map;
	while (current != NULL)
	{
		if (current->x_pos == 0 && current->case_type != WALL)
			return (ft_printf("The map is not closed with wall.\n"), FALSE);
		if (current->y_pos == 0 && current->case_type != WALL)
			return (ft_printf("The map is not closed with wall.\n"), FALSE);
		if (current->x_pos == max_x - 1 && current->case_type != WALL)
			return (ft_printf("The map is not closed with wall.\n"), FALSE);
		if (current->y_pos == max_y - 1 && current->case_type != WALL)
			return (ft_printf("The map is not closed with wall.\n"), FALSE);
		current = current->next;
	}
	return (TRUE);
}

int	check_double(t_map_data *map, int count_c)
{
	t_map_data	*current;
	int			count_e;
	int			count_p;

	count_e = 0;
	count_p = 0;
	current = map;
	while (current != NULL)
	{
		if (current->case_type == 'E')
			count_e++;
		if (current->case_type == 'P')
			count_p++;
		if (current->case_type == 'C')
			count_c++;
		if (count_e >= 2)
			return (ft_printf("The map has more than 1 End.\n"), FALSE);
		if (count_p >= 2)
			return (ft_printf("The map has more than 1 Player.\n"), FALSE);
		current = current->next;
	}
	if (count_c == 0)
		return (ft_printf("The map has no coin.\n"), FALSE);
	return (TRUE);
}

int	check_map(t_mlx_data *main_window)
{
	t_map_data	*current;
	int			max_x;
	int			max_y;
	int			count;

	max_x = 0;
	max_y = 0;
	count = 1;
	current = main_window->map;
	while (current != NULL)
	{
		if (current->y_pos == 0)
			max_x++;
		if (current->x_pos == 0)
			max_y++;
		current = current->next;
	}
	main_window->window_height = max_y;
	main_window->window_width = max_x;
	if (!check_rectangle(main_window->map, count, max_x) || \
		!check_wall_map(main_window->map, max_x, max_y) || \
		!check_double(main_window->map, 0))
		return (FALSE);
	return (TRUE);
}

int	check_map_name(char *map_name)
{
	const char	*extension;
	size_t		filename_len;
	size_t		extension_len;

	extension = ".ber";
	filename_len = ft_strlen(map_name);
	extension_len = ft_strlen(extension);
	if (filename_len < extension_len)
	{
		ft_printf("The map has not the good type of file.\n");
		return (FALSE);
	}
	if (ft_strcmp(map_name + filename_len - extension_len, extension))
	{
		ft_printf("The map has not the good type of file.\n");
		return (FALSE);
	}
	return (ft_strcmp(map_name + filename_len - extension_len, extension) == 0);
}
