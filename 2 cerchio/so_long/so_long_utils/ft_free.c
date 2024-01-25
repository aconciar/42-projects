/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:31:22 by aconciar          #+#    #+#             */
/*   Updated: 2024/01/09 17:31:39 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img(t_data *front)
{
	mlx_destroy_image(front->mlx_ptr, front->img.front);
	mlx_destroy_image(front->mlx_ptr, front->img.frontspine);
	mlx_destroy_image(front->mlx_ptr, front->img.zero);
	mlx_destroy_image(front->mlx_ptr, front->img.back);
	mlx_destroy_image(front->mlx_ptr, front->img.backspine);
	mlx_destroy_image(front->mlx_ptr, front->img.coll);
	mlx_destroy_image(front->mlx_ptr, front->img.exit);
	mlx_destroy_image(front->mlx_ptr, front->img.left);
	mlx_destroy_image(front->mlx_ptr, front->img.leftspine);
	mlx_destroy_image(front->mlx_ptr, front->img.right);
	mlx_destroy_image(front->mlx_ptr, front->img.rightspine);
	mlx_destroy_image(front->mlx_ptr, front->img.wall);
	mlx_destroy_image(front->mlx_ptr, front->img.spinegiu);
	mlx_destroy_image(front->mlx_ptr, front->img.spinesu);
	mlx_destroy_image(front->mlx_ptr, front->img.trapdoor);
	mlx_destroy_image(front->mlx_ptr, front->img.morte);
	free_mat(front->mat);
}

int	destroy_window(t_data *front)
{
	mlx_destroy_window(front->mlx_ptr, front->win_ptr);
	free_img(front);
	mlx_destroy_display(front->mlx_ptr);
	free(front->mlx_ptr);
	exit(0);
	return (0);
}
