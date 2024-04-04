/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:38:34 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/04 17:05:08 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_finishable(char *str_map)
{
	int	i;

	i = 0;
	printf("%s\n", str_map);
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

int	check_way_possible(char *str_map, int pos_x, int pos_y, int max_x, int max_y)
{
	if (pos_x > max_x || pos_y > max_y || \
	str_map[pos_x + (pos_y * (max_x + 1))] == '1' || pos_x < 0 || pos_y < 0)
		return (0);
	if (str_map[pos_x + (pos_y * (max_x + 1))] == 'E')
		str_map[pos_x + (pos_y * (max_x + 1))] = 'W';
	if (str_map[pos_x + (pos_y * (max_x + 1))] == '1' || \
	str_map[pos_x + (pos_y * (max_x + 1))] == 'X')
		return (0);
	if (!(str_map[pos_x + (pos_y * (max_x + 1))] == 'W'))
		str_map[pos_x + (pos_y * (max_x + 1))] = 'X';
	if (check_end_found(str_map) && check_finishable(str_map))
		return (1);
	if (check_way_possible(str_map, pos_x + 1, pos_y, max_x, max_y) || \
	check_way_possible(str_map, pos_x - 1, pos_y, max_x, max_y) || \
	check_way_possible(str_map, pos_x, pos_y + 1, max_x, max_y) || \
	(check_way_possible(str_map, pos_x, pos_y - 1, max_x, max_y)))
		return (1);
	return (0);
}
