/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:32:56 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/11 02:05:04 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(int input, t_mlx_data *main_window)
{
	//mlx_clear_window(main_window->mlx_ptr, main_window->mlx_window);
	handle_input(input, main_window);
	show_map(main_window->map, *main_window);
	show_player(main_window);
	return (0);
}

int	check_map(char *map_name)
{
	const char *extension = ".ber";
    size_t filename_len = strlen(map_name);
    size_t extension_len = strlen(extension);
    
    if (filename_len < extension_len) {
        return 0; // Le nom de fichier est plus court que l'extension, donc ce n'est pas un fichier .ber
    }
    
    return ft_strcmp(map_name + filename_len - extension_len, extension) == 0;
	
	
}


int	main(int argc, char *argv[])
{
	t_mlx_data	main_window;
	int			fd;
	char		*map;

	if (argc != 2)
		return (0);
	map = argv[1];
	if (!check_map(map))
		return (0);
	fd = open(map, O_RDONLY);
	main_window.map = open_map(fd);
	init_window(&main_window);
	init_player(&main_window);
	show_map(main_window.map, main_window);
	show_player(&main_window);
	if (argc == 2)
	{
		mlx_key_hook(main_window.mlx_window, game_loop, &main_window);
		mlx_hook(main_window.mlx_window, 17, 0, (void *)exit, 0);
		mlx_loop(main_window.mlx_ptr);
	}
	return (0);
}
