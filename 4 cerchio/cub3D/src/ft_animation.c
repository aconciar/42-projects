/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:11:38 by aconciar          #+#    #+#             */
/*   Updated: 2024/07/30 16:37:05 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_animation(t_mlx *data)
{
	data->anim_frame++;
	if (data->anim_frame >= 10)
	{
		if (data->curr_sprite == &data->sprite1)
			data->curr_sprite = &data->sprite2;
		else if (data->curr_sprite == &data->sprite2)
			data->curr_sprite = &data->sprite1;
		data->anim_frame = 0;
	}
}
