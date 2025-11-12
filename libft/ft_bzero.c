/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:11:05 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:31 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Sets a block of memory to zero.
 *
 * Writes zero bytes to the first @p num_bytes of @p mem_area.
 * Equivalent to `memset(mem_area, 0, num_bytes)`.
 *
 * @param mem_area Memory area to zero.
 * @param num_bytes Number of bytes to write.
 */
void	ft_bzero(void *memblock, size_t numbytes)
{
	ft_memset(memblock, 0, numbytes);
}
