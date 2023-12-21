/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:47:35 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/07 19:12:40 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mat(char **mat)
{
	int	y;

	y = 0;
	while (mat[y])
	{
		free(mat[y]);
		y++;
	}
	free(mat);
}

void	put_image(t_data *front, int key, int x, int y)
{
	if (front->mat[y][x] == '1')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.wall, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == '0')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.zero, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'C')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.coll, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'E')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.exit, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'P' && key == 'w')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.back, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'P' && key == 'a')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.left, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'P' && key == 'd')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.right, x * PIXEL, y * PIXEL);
	if (front->mat[y][x] == 'P' && key == 's')
		mlx_put_image_to_window(front->mlx_ptr, front->win_ptr,
			front->img.front, x * PIXEL, y * PIXEL);
}

void	rend_map(t_data *front, int key)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (front->mat[y])
	{
		while (front->mat[y][x])
		{
			put_image(front, key, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	file_to_image(t_data *data, int x, int y)
{
	data->img.front = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/front.xpm", &x, &y);
	data->img.back = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/back.xpm", &x, &y);
	data->img.right = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/right.xpm", &x, &y);
	data->img.left = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/left.xpm", &x, &y);
	data->img.coll = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/coll.xpm", &x, &y);
	data->img.zero = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/zero.xpm", &x, &y);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &x, &y);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &x, &y);
}

int	main(int argc, char *argv[])
{
	t_data	front;

	if (argc != 2)
		return (1);
	front.mat = map(argv[1]);
	if (check_map(&front) != 0)
	{
		ft_printf("Error\nInvalid map");
		return (free_mat(front.mat), 1);
	}
	front.mlx_ptr = mlx_init();
	if (!front.mlx_ptr)
		return (1);
	front.win_ptr = mlx_new_window(front.mlx_ptr, ft_strlen(front.mat[0])
			* PIXEL, matlen(front.mat) * PIXEL, "so_long");
	if (!front.win_ptr)
		return (free(front.mlx_ptr), 1);
	file_to_image(&front, ft_strlen(front.mat[0]), matlen(front.mat));
	rend_map(&front, 's');
	mlx_hook(front.win_ptr, KeyPress, KeyPressMask, ft_keypress, &front);
	mlx_hook(front.win_ptr, 17, 1L << 17, destroy_window, &front);
	mlx_loop(front.mlx_ptr);
	free(front.mlx_ptr);
	return (0);
}
