/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:40:07 by aconciar          #+#    #+#             */
/*   Updated: 2023/12/12 18:12:23 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

# ifndef PIXEL
#  define PIXEL 32
# endif

typedef struct s_img
{
	void	*front;
	void	*back;
	void	*left;
	void	*right;
	void	*coll;
	void	*exit;
	void	*wall;
	void	*zero;
}				t_img;	

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**mat;
	char	**tmp;
	int		coll;
	t_img	img;
	t_point	size;
	t_point	p;
}				t_data;

char	**map(char *fd);
int		check_map(t_data *data);
void	print_map(char **mat);
int		matlen(char **mat);
int		destroy_window(t_data *front);
int		ft_keypress(int key, t_data *front);
void	rend_map(t_data *front, int key);
void	free_mat(char **mat);
void	flood_fill(char **tab, t_point size, t_point begin);

#endif
