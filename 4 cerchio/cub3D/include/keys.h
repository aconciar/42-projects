/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucolla <ucolla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:41:38 by ucolla            #+#    #+#             */
/*   Updated: 2024/08/01 15:02:26 by ucolla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/* EXIT */
# define ESCAPE 0xff1b
/* MOVE */
# define FORWARD 0x077
# define BACKWARD 0x073
# define LEFT 0x061
# define RIGHT 0x064
/* ROTATE */
# define R_LEFT 65361
# define R_RIGHT 65363
/* OPEN & CLOSE */
# define TOGGLE_DOOR 1
# define TOGGLE_DOOR_KEY 0x20 
/* RECENTER MOUSE */
# define RECENTER 3
# define RECENTER_KEY 0x65

#endif