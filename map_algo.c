/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:38:34 by kenzo             #+#    #+#             */
/*   Updated: 2024/06/13 16:51:16 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_finishable(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i] != 0)
	{
		if (str_map[i] == 'C')
			return (0);
		i++;
	}
	return (1);
}

int	check_end_found(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i] != 0)
	{
		if (str_map[i] == 'W')
			return (1);
		i++;
	}
	return (0);
}

int	check_way_possible(char *str_map, int pos_x, int pos_y, t_pos pos)
{
	if (pos_x > pos.max_x || pos_y > pos.max_y || \
	str_map[pos_x + (pos_y * (pos.max_x + 1))] == '1' || pos_x < 0 || pos_y < 0)
		return (0);
	if (str_map[pos_x + (pos_y * (pos.max_x + 1))] == 'E')
		str_map[pos_x + (pos_y * (pos.max_x + 1))] = 'W';
	if (str_map[pos_x + (pos_y * (pos.max_x + 1))] == '1' || \
	str_map[pos_x + (pos_y * (pos.max_x + 1))] == 'X')
		return (0);
	if (!(str_map[pos_x + (pos_y * (pos.max_x + 1))] == 'W'))
		str_map[pos_x + (pos_y * (pos.max_x + 1))] = 'X';
	if (check_end_found(str_map) && check_finishable(str_map))
		return (1);
	if (check_way_possible(str_map, pos_x + 1, pos_y, pos) || \
	check_way_possible(str_map, pos_x - 1, pos_y, pos) || \
	check_way_possible(str_map, pos_x, pos_y + 1, pos) || \
	(check_way_possible(str_map, pos_x, pos_y - 1, pos)))
		return (1);
	return (0);
}
