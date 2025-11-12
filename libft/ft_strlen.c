/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:39:34 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:55 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the length of a C string (number of bytes 
 * before the first '\0').
 *
 * Counts bytes up to, but not including, the terminating null byte.
 * Behavior is undefined if @p str is NULL or not null-terminated.
 *
 * @param str Pointer to a null-terminated string.
 * @return size_t Number of bytes before '\0'.
 */
size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (counter[str] != '\0')
		counter++;
	return (counter);
}
