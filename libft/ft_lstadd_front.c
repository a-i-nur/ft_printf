/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:47:09 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:04 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Add a node to the front of a list.
 *
 * Inserts @p new as the first element of the list pointed to by @p lst.
 * If @p lst or @p new is NULL, no action is taken.
 *
 * @param lst Address of the pointer to the first node of the list.
 * @param new Node to prepend to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
