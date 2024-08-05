/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconciar <aconciar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:07:31 by fdonati           #+#    #+#             */
/*   Updated: 2024/05/21 15:16:06 by aconciar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_list_clear(t_token **lst, void (*del)(void*))
{
	t_token	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_listdel_one(*lst, del);
		*lst = tmp;
	}
}

/*Parameters
	lst: The address of a pointer to a node.
	del: The address of the function used to delete
	the content of the node.
Return value
	None
External functs
	free
Description
	Deletes and frees the given node and every
	successor of that node, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.*/