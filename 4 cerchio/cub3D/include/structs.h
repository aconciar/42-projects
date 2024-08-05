/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:42:59 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 15:40:21 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_wall
{
	double	wall_height;
	double	wall_x;
	int		pixel_y;
	int		tex_x;
	int		tex_y;
	int		color;
}				t_wall;

typedef struct s_dda
{
	int		side;
	int		steps;
	int		dx;
	int		dy;
	double	x_inc;
	double	y_inc;
	double	x;
	double	y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
}				t_dda;

typedef struct s_line
{
	int		x_0;
	int		y_0;
	int		x_1;
	int		y_1;
	double	angle;
	double	distance;
	double	dir_x;
	double	dir_y;
	double	perp_wall_dist;
	double	wall_x;
	int		hit;
	int		side;
}				t_line;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
	int		color;
}				t_rgb;

typedef struct s_texture
{
	char	*path;
	void	*img_ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}			t_texture;

typedef struct s_map
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	t_texture	door;
	int			p_x;
	int			p_y;
	t_rgb		floor;
	t_rgb		ceiling;
	char		**map;
}				t_map;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_player
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		turn_left;
	int		turn_right;
	int		mouse_x;
	int		mouse_y;
	double	x;
	double	y;
	double	angle;
	t_image	player_img;
}				t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_image		main_img;
	t_player	*player;
	t_map		map;
	t_texture	sprite1;
	t_texture	sprite2;
	t_texture	*curr_sprite;
	int			anim_frame;
	int			win_width;
	int			win_height;
}				t_mlx;

#endif