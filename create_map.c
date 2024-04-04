/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:18:10 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/04 17:01:38 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map_data	*create_map_node(char c)
{
	t_map_data	*new_node;

	new_node = malloc(sizeof(t_map_data));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	if (!ft_strchr(VALID_VALUE, c))
	{
		free(new_node);
		printf("Wrong character has been used.\n");
		return (NULL);
	}
	new_node->case_type = c;
	return (new_node);
}

static void	add_node_to_end(t_map_data **head, t_map_data *new_node)
{
	t_map_data	*current;

	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

static int	process_line(t_map_data **head, char *line, int y_pos)
{
	int			x_pos;
	t_map_data	*new_node;

	x_pos = 0;
	while (line[x_pos] != '\n' && line[x_pos] != '\0')
	{
		new_node = create_map_node(line[x_pos]);
		if (new_node == NULL)
			return (FALSE);
		new_node->x_pos = x_pos;
		new_node->y_pos = y_pos;
		add_node_to_end(head, new_node);
		x_pos++;
	}
	return (TRUE);
}

t_map_data	*open_map(int fd)
{
	char		*line;
	int			y_pos;
	t_map_data	*head;

	head = NULL;
	y_pos = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_line(&head, line, y_pos))
		{
			free(line);
			return (NULL);
		}
		y_pos++;
		free(line);
		line = get_next_line(fd);
	}
	return (head);
}

void	*create_str_map(t_mlx_data *main_window)
{
	char		*str_map;
	int			i;
	t_map_data	*current;

	i = 0;
	current = main_window->map;
	while (current->next != NULL)
		current = current->next;
	main_window->max_x = current->x_pos;
	main_window->max_y = current->y_pos;
	str_map = malloc((sizeof(char) * (current->x_pos + 1) \
	* (current->y_pos + 1)) + 1);
	current = main_window->map;
	while (current != NULL)
	{
		str_map[i] = current->case_type;
		i++;
		current = current->next;
	}
	str_map[i] = '\0';
	main_window->str_map = str_map;
}
