/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:37:08 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/30 15:59:48 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 400
# define TRUE 1
# define FALSE 0
# define MALLOC_ERROR 1
# define MLX_ERROR 1
# define COLLECTOR C
# define WALL '1'
# define PLAYER P
# define EXIT E
# define SIZE 50
# define VALID_VALUE "01ECP"

typedef struct s_map_data
{
	char				case_type;
	int					x_pos;
	int					y_pos;
	int					is_valid;
	struct s_map_data	*next;
	struct s_map_data	*previous;
	int					is_visited;
}						t_map_data;

typedef struct s_pos
{
	int	max_x;
	int	max_y;
}		t_pos;

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
	int				window_height;
	int				window_width;
	int				max_y;
	int				max_x;
	char			*str_map;
	void			*player_img;
	void			*sol_img;
	void			*wall_img;
	void			*collectible_img;
	void			*exit_img;
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

void		show_map(t_mlx_data main_window);
void		show_player(t_mlx_data *main_window);
int			player_move(int input, t_mlx_data *main_window);
int			handle_input(int input, t_mlx_data *main_window);
int			mouse_use(t_mlx_data *main_window);
void		put_assets(t_mlx_data main_window, const char *texture_name);
int			init_img(t_mlx_data *main_window);

int			init_window(t_mlx_data *main_window);
void		init_player_pos(t_mlx_data *main_window);
void		init_player(t_mlx_data *main_window);
int			create_str_map(t_mlx_data *main_window);

int			check_rectangle(t_map_data *map, int count, int max_x);
int			check_wall_map(t_map_data *map, int max_x, int max_y);
int			check_map(t_mlx_data *main_window);
int			check_collision(t_mlx_data *main_window);
int			check_win(t_mlx_data *main_window);
int			check_endable(t_mlx_data *main_window);
int			check_map_name(char *map_name);
int			check_way_possible(char *str_map, int pos_x, int pos_y, t_pos pos);

void		clean_close(t_mlx_data *main_window);
void		free_list(t_map_data *head);

#endif