/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:38:31 by ucolla            #+#    #+#             */
/*   Updated: 2024/07/30 16:34:28 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_texture(t_mlx *data)
{
	ft_free_matrix(data->map.map);
	free(data->map.no.path);
	free(data->map.so.path);
	free(data->map.ea.path);
	free(data->map.we.path);
	free(data->map.door.path);
	free(data->sprite1.path);
	free(data->sprite2.path);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_load_texture(t_texture *texture, t_mlx *data)
{
	texture->width = 64;
	texture->height = 64;
	texture->img_ptr = mlx_xpm_file_to_image(data->mlx, texture->path,
			&texture->width, &texture->height);
	if (texture->img_ptr == NULL)
	{
		free_texture(data);
		ft_error("Failed loading texture");
	}
	texture->data = (int *)mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (texture->data == NULL)
	{
		free_texture(data);
		ft_error("Failed getting texture data");
	}
}
