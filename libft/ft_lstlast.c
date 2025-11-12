/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:06:46 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:43 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Return the last node of a list.
 *
 * Traverses the list starting at @p lst until the final node whose
 * @c next pointer is NULL. If @p lst is NULL, returns NULL.
 *
 * @param lst Pointer to the first node of the list.
 * @return t_list* Pointer to the last node, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst-> next;
	}
	return (lst);
}
