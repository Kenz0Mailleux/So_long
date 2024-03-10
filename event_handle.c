/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:19:12 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/10 01:58:55 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int getNumberLength(int number) {
	int length = 1; // Un nombre a au moins un chiffre

	while (number /= 10)
		length++;
	return length;
}

// Fonction pour convertir un nombre entier en une chaîne de caractères
void intToString(char *buffer, int number) {
    int length = getNumberLength(number);
    buffer += length; // Déplacer le pointeur de la fin de la chaîne
    *buffer = '\0'; // Terminer la chaîne de caractères

    // Convertir chaque chiffre du nombre en un caractère
    do {
        *--buffer = '0' + (number % 10);
        number /= 10;
    } while (number != 0);
}


int	player_move(int input, t_mlx_data *main_window)
{
	if (input == ON_KEYUP || input == 'z')
	{
		main_window->player.y_pos -= 1;
		if (check_collision(main_window))
			main_window->player.y_pos += 1;
	}
	else if (input == ON_KEYDOWN|| input == 's')
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

//tbool
int check_collision(t_mlx_data *main_window)
{
	char buffer[20]; // Tampon pour contenir la représentation en chaîne de caractères du nombre
    int length; // Longueur de la chaîne de caractères

    intToString(buffer, main_window->player.move);
    length = getNumberLength(main_window->player.move);

	t_map_data *current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->x_pos == main_window->player.x_pos && current->y_pos == main_window->player.y_pos)
		{
			if (current->case_type ==  WALL)
				return (1);

			main_window->player.move += 1;
			write(1, buffer, length);
			write(1,"\n", 1);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int check_win(t_mlx_data *main_window)
{
	t_map_data *current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->x_pos == main_window->player.x_pos && current->y_pos == main_window->player.y_pos)
		{
			if (current->case_type == 'E' && main_window->endable == 1)
				return (1);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	take_collectible(t_mlx_data *main_window)
{
	t_map_data *current;
	current = main_window->map;
	while (current != NULL)
	{
		if (current->x_pos == main_window->player.x_pos && current->y_pos == main_window->player.y_pos)
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

int	check_endable(t_mlx_data *main_window)
{
	t_map_data	*current;

	current = main_window->map;
	while (current != NULL)
	{
		if (current->case_type == 'C')
			return (0);
		current = current->next;
	}
	return (1);
}

int handle_input(int input, t_mlx_data *main_window)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 50;
	img_height = 50;
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
	return (0);
}

void	clean_close(t_mlx_data *main_window)
{
	mlx_destroy_window(main_window->mlx_ptr, main_window->mlx_window);
	mlx_destroy_display(main_window->mlx_ptr);
	free(main_window->mlx_ptr);
	exit (1);
}

//void victory_screen(t_mlx_data *main_window)