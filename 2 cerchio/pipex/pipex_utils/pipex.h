/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:13:27 by andrea            #+#    #+#             */
/*   Updated: 2024/03/28 18:58:01 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifdef PIPEX_H
// # define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../libft/libft.h"

void	ft_execute(char *argv, char *envp[]);
void	ft_error(char *str);

// #endif
