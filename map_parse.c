/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:43:00 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/11 02:00:26 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_data	*open_map(int fd)
{
	char		*line;
	int			max_i;
	int			max_j;
	int			i;
	int			j;
	t_map_data	*head; // Tête de la liste
	t_map_data	*current; // Pointeur pour naviguer dans la liste
	t_map_data	*new_node;

	head = NULL;
	current = NULL;
	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		while (line[i] != '\n')
		{
			if (line[i] == '\0')
			{
				return (head);
			}
			new_node = malloc(sizeof(t_map_data));
			if (!new_node)
				return NULL;
			new_node->next = NULL;
			new_node->case_type = line[i];
			new_node->x_pos = i;
			new_node->y_pos = j;
			if (head == NULL)
			{
				// Si la tête de la liste est NULL, c'est le premier élément de la liste
				head = new_node;
				current = head;
			}
			else 
			{
				// Sinon, ajouter le nouveau nœud à la fin de la liste
				current->next = new_node;
				current = new_node;
			}
			i++;
		}
		i = 0;
		j++;
		free(line);
		line = get_next_line(fd);
	}

	return (head);
}

void	*show_map(t_map_data *map, t_mlx_data main_window)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = SIZE;
	img_height = SIZE;
	while (main_window.map)
	{
		if (main_window.map->case_type == '1')
		{
			img = mlx_xpm_file_to_image(main_window.mlx_ptr, \
			"textures/TilesetNature.xpm", &img_width, &img_height);
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, img, main_window.map->x_pos * SIZE, \
			main_window.map->y_pos * SIZE);
		}
		else if (main_window.map->case_type == 'E')
		{
			img = mlx_xpm_file_to_image(main_window.mlx_ptr, \
			"textures/TileseExit.xpm", &img_width, &img_height);
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, img, main_window.map->x_pos * SIZE, \
			main_window.map->y_pos * SIZE);
		}
		else if (main_window.map->case_type == 'C')
		{
			img = mlx_xpm_file_to_image(main_window.mlx_ptr, \
			"textures/Collectible.xpm", &img_width, &img_height);
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, img, main_window.map->x_pos * SIZE, \
			main_window.map->y_pos * SIZE);
		}
		else
		{
			img = mlx_xpm_file_to_image(main_window.mlx_ptr, \
			"textures/TilesetField.xpm", &img_width, &img_height);
			mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, img, main_window.map->x_pos * SIZE, \
			main_window.map->y_pos * SIZE);
		}
		main_window.map = main_window.map->next;
	}
	return (NULL);
}

void	show_player(t_mlx_data *main_window)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 50;
	img_height = 50;
	img = mlx_xpm_file_to_image(main_window->mlx_ptr, \
	"textures/Player.xpm", &img_width, &img_height);
	mlx_put_image_to_window(main_window->mlx_ptr, main_window->mlx_window, \
	img, main_window->player.x_pos * SIZE, main_window->player.y_pos * SIZE);
}
