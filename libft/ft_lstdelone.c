/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:00:17 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:48 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Delete a single node and free its content.
 *
 * Calls @p del on @p lst->content and then frees the node.
 * Does not free the next node. If @p lst or @p del is NULL,
 * no action is taken.
 *
 * @param lst Node to delete.
 * @param del Function used to free the node's content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
