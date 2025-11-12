/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:31:12 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:07 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Add a node to the end of a list.
 *
 * Appends @p new to the end of the list pointed to by @p lst.
 * If @p lst is NULL, no action is taken. If *@p lst is NULL,
 * the new node becomes the first element.
 *
 * @param lst Address of the pointer to the first node of the list.
 * @param new Node to append at the end.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new;
	}
	else
	{
		*lst = new;
	}
}
