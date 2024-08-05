/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:25:45 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 16:27:34 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include "keys.h"
# include "structs.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/time.h>
# include <fcntl.h>

# ifndef BONUS
#  define BONUS 0
# endif

# define PI 3.14159265358979323846
# define WIDTH 1600
# define HEIGHT 900
# define T_SIZE 64
# define P_SIZE 16
# define DIVISOR 4
# define N_RAYS 60
# define MOVE_SPEED 5
# define BORDER_RATIO 0.25
# define MINIMAP_SIZE 10 
# define DOF 1000

/* PARSING */
void	ft_init_map(t_map *map, char *arg);
int		ft_parse_map(char **map, t_map *data);
void	ft_error(char *str);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		ft_parsing(t_map *map);
void	ft_check_syntax(int fd);
int		ft_matlen(char **mat);
void	ft_free_struct(t_map *map);
void	ft_readfile(t_map *map, int fd);

/* INITIALIZATION */
void	ft_load_texture(t_texture *texture, t_mlx *data);
int		ft_find_len(char **map);

/* MOVEMENT */
void	ft_move_player(t_mlx *data);
int		ft_rotate_player(t_mlx *data);
void	ft_move_sideways(t_mlx *data, double move_x, double move_y);
int		ft_check_collision(t_mlx *data, double move_x, double move_y);
void	handle_doors(t_mlx *data);
void	mouse_rotation(t_mlx *data);
int		ft_mouse_hook(int button, int x, int y, t_mlx *data);
void	ft_animation(t_mlx *data);

/* HOOKS */
int		ft_exit_window(t_mlx *data);
int		ft_button_down(int key, t_mlx *data);
int		ft_button_up(int key, t_mlx *data);
int		ft_start_game(t_mlx *data);
void	ft_draw_floor_ceiling(t_mlx *data);

/* DRAWING */
void	ft_pixel_put(t_image *info, int x, int y, int color);
void	ft_minimap(t_mlx *data, char **map);
void	choose_color(char **map, int map_x, int map_y, int *color);
void	ft_draw_walls(t_line *ray, t_image *img, int k, t_mlx *data);
int		ft_is_wall(int x, int y, t_mlx *data);
int		ft_dda(t_line *line, t_mlx *data);
double	ft_deg_to_rad(double angle);
int		ft_fix_ang(int a);

#endif