/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:43:00 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/14 00:24:50 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_map_data *create_map_node(char c)
// {
//   t_map_data *new_node = malloc(sizeof(t_map_data));
//   if (!new_node) {
//     return NULL;
//   }
//   new_node->next = NULL;
//   if (!ft_strchr(VALID_VALUE, c)) {
//     free(new_node);
//     return NULL;
//   }
//   new_node->case_type = c;
//   return new_node;
// }

// void add_node_to_end(t_map_data **head, t_map_data *new_node) {
//   if (*head == NULL) {
//     *head = new_node;
//     return;
//   }
//   t_map_data *current = *head;
//   while (current->next != NULL) {
//     current = current->next;
//   }
//   current->next = new_node;
// }
// int process_line(t_map_data **head, char *line, int y_pos) {
//   int x_pos = 0;
//   while (line[x_pos] != '\n' && line[x_pos] != '\0') {
//     t_map_data *new_node = create_map_node(line[x_pos]);
//     if (new_node == NULL) {
//       return (0);
//     }
//     new_node->x_pos = x_pos;
//     new_node->y_pos = y_pos;
//     add_node_to_end(head, new_node);
//     x_pos++;
//   }
//   return (1);
// }

// t_map_data *open_map(int fd) {
//   char *line;
//   int y_pos = 0;
//   t_map_data *head;

//   head = NULL;
//   while ((line = get_next_line(fd)) != NULL) {
//     if (!process_line(&head, line, y_pos)) {
//       free(line);
//       return (NULL);
//     }
//     y_pos++;
//     free(line);
//   }
//   return (head);
// }

// t_map_data	*open_map(int fd)
// {
// 	char		*line;
// 	int			i;
// 	int			j;
// 	t_map_data	*head; // Tête de la liste
// 	t_map_data	*current; // Pointeur pour naviguer dans la liste
// 	t_map_data	*new_node;

// 	head = NULL;
// 	current = NULL;
// 	i = 0;
// 	j = 0;
// 	line = get_next_line(fd);
// 	while (line != NULL)
// 	{
// 		while (line[i] != '\n')
// 		{
// 			if (line[i] == '\0')
// 				return (head);
// 			new_node = malloc(sizeof(t_map_data));
// 			if (!new_node)
// 				return NULL;
// 			new_node->next = NULL;
// 			if (!(ft_strchr(VALID_VALUE, line[i])))
// 				return (NULL);
// 			new_node->case_type = line[i];
// 			new_node->x_pos = i;
// 			new_node->y_pos = j;
// 			if (head == NULL)
// 			{
// 				head = new_node;
// 				current = head;
// 			}
// 			else 
// 			{
// 				current->next = new_node;
// 				current = new_node;
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		j++;
// 		line = get_next_line(fd);
// 	}
// 	return (head);
// }

void	put_assets(t_mlx_data main_window, const char *texture_name)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = SIZE;
	img_height = SIZE;
	img = mlx_xpm_file_to_image(main_window.mlx_ptr, \
			(char *)texture_name, &img_width, &img_height);
	mlx_put_image_to_window(main_window.mlx_ptr, \
			main_window.mlx_window, img, main_window.map->x_pos * SIZE, \
			main_window.map->y_pos * SIZE);
}

void	*show_map(t_map_data *map, t_mlx_data main_window)
{
	while (main_window.map)
	{
		if (main_window.map->case_type == '1')
			put_assets(main_window, "textures/TilesetNature.xpm");
		else if (main_window.map->case_type == 'E')
			put_assets(main_window, "textures/TileseExit.xpm");
		else if (main_window.map->case_type == 'C')
			put_assets(main_window, "textures/Collectible.xpm");
		else
			put_assets(main_window, "textures/TilesetField.xpm");
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
