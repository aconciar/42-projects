/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:23:51 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/05 16:26:46 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_player_init(t_mlx *data)
{
	data->player = ft_calloc(1, sizeof(t_player));
	if (data->player == NULL)
		return (1);
	data->player->x = (data->map.p_x * T_SIZE) + (T_SIZE / 2) - (P_SIZE / 2);
	data->player->y = (data->map.p_y * T_SIZE) + (T_SIZE / 2) - (P_SIZE / 2);
	if (data->map.map[data->map.p_y][data->map.p_x] == 'N')
		data->player->angle = 3 * PI / 2;
	else if (data->map.map[data->map.p_y][data->map.p_x] == 'E')
		data->player->angle = 0;
	else if (data->map.map[data->map.p_y][data->map.p_x] == 'S')
		data->player->angle = PI / 2;
	else if (data->map.map[data->map.p_y][data->map.p_x] == 'W')
		data->player->angle = PI;
	return (0);
}

static int	ft_rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	load_all_textures(t_mlx *data)
{
	ft_load_texture(&data->map.no, data);
	ft_load_texture(&data->map.so, data);
	ft_load_texture(&data->map.ea, data);
	ft_load_texture(&data->map.we, data);
	ft_load_texture(&data->map.door, data);
	ft_load_texture(&data->sprite1, data);
	ft_load_texture(&data->sprite2, data);
}

static int	ft_img_init(t_mlx *data)
{
	data->sprite1.path = ft_strdup("textures/sprite_1.xpm");
	data->sprite2.path = ft_strdup("textures/sprite_2.xpm");
	data->win_width = ft_find_len(data->map.map) * T_SIZE;
	data->win_height = ft_matlen(data->map.map) * T_SIZE;
	data->mlx = mlx_init();
	load_all_textures(data);
	data->curr_sprite = &data->sprite1;
	data->anim_frame = 0;
	data->map.ceiling.color = ft_rgb_to_int(data->map.ceiling.r,
			data->map.ceiling.g, data->map.ceiling.b);
	data->map.floor.color = ft_rgb_to_int(data->map.floor.r,
			data->map.floor.g, data->map.floor.b);
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	if (data->win == NULL)
		return (1);
	data->main_img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->main_img.img == NULL)
		return (1);
	data->main_img.addr = mlx_get_data_addr(data->main_img.img,
			&data->main_img.bits_per_pixel,
			&data->main_img.line_length, &data->main_img.endian);
	ft_player_init(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	if (argc != 2)
		ft_error("Invalid number of arguments");
	ft_init_map(&data.map, argv[1]);
	if (ft_parsing(&data.map))
		return (ft_free_struct(&data.map), 1);
	if (ft_img_init(&data))
		return (ft_free_struct(&data.map), 1);
	mlx_mouse_move(data.mlx, data.win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(data.win, KeyPress, KeyPressMask, ft_button_down, &data);
	mlx_mouse_hook(data.win, ft_mouse_hook, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, ft_button_up, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
		ft_exit_window, &data);
	mlx_loop_hook(data.mlx, ft_start_game, &data);
	mlx_loop(data.mlx);
	ft_free_struct(&data.map);
	return (0);
}
