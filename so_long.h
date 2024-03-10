/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:37:08 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/10 01:42:02 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "mlx/mlx.h"
#include "mlx/mlx_int.h"
#include "gnl/get_next_line.h"
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 1000
#define MALLOC_ERROR 1
#define MLX_ERROR 1
#define COLLECTOR C
#define WALL '1'
#define PLAYER P
#define EXIT E
#define SIZE 50

typedef struct s_map_data
{
	char				case_type;
	int					x_pos;
	int					y_pos;
	struct s_map_data	*next;
	struct s_map_data	*previous;
}						t_map_data;

typedef struct s_player_data
{
	int	x_pos;
	int	y_pos;
	int	move;
}						t_player_data;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*mlx_window;
	int				endable;
	t_map_data		*map;
	t_player_data	player;
}						t_mlx_data;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int			game_loop(int input, t_mlx_data *main_window);
t_map_data	*open_map(int fd);
void		*show_map(t_map_data *map, t_mlx_data main_window);
void		show_player(t_mlx_data *main_window);
int			player_move(int input, t_mlx_data *main_window);
int			handle_input(int input, t_mlx_data *main_window);
int			check_collision(t_mlx_data *main_window);
int			init_window(t_mlx_data *main_window);
void		init_player_pos(t_mlx_data *main_window);
void		init_player(t_mlx_data *main_window);
void		clean_close(t_mlx_data *main_window);