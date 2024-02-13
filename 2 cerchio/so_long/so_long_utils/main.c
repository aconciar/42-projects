/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:47:35 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/16 19:15:35 by aconciar         ###   ########.fr       */
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

void	rend_map(t_data *front, int key)
{
	int		x;
	int		y;
	char	*str;
	char	*str2;

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
	str = ft_itoa(front->moves);
	str2 = ft_strjoin("moves : ", str);
	free(str);
	mlx_string_put(front->mlx_ptr, front->win_ptr, 30, 30, 0xFF0000, str2);
	free (str2);
}

void	file_to_image2(t_data *data, int x, int y)
{
	data->img.coll = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/coll.xpm", &x, &y);
	data->img.zero = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/zero.xpm", &x, &y);
	data->img.wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &x, &y);
	data->img.exit = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &x, &y);
	data->img.spinegiu = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/spinegiu.xpm", &x, &y);
	data->img.spinesu = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/spinesu.xpm", &x, &y);
	data->img.trapdoor = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/trapdoor.xpm", &x, &y);
	data->img.morte = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/morte.xpm", &x, &y);
}

void	file_to_image(t_data *data, int x, int y)
{
	data->coll = 0;
	data->img.front = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/front.xpm", &x, &y);
	data->img.frontspine = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/frontspine.xpm", &x, &y);
	data->img.back = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/back.xpm", &x, &y);
	data->img.backspine = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/backspine.xpm", &x, &y);
	data->img.right = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/right.xpm", &x, &y);
	data->img.rightspine = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/rightspine.xpm", &x, &y);
	data->img.left = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/left.xpm", &x, &y);
	data->img.leftspine = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/leftspine.xpm", &x, &y);
	file_to_image2(data, x, y);
}

int	main(int argc, char *argv[])
{
	t_data	front;

	front.moves = 0;
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
