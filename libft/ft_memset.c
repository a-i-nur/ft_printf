/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:57:10 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:17 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills a block of memory with a byte value.
 *
 * Writes the low 8 bits of @p symbol into
 * the first @p num_bytes of @p mem_area.
 * The pointer must be valid for writing at least @p num_bytes bytes.
 *
 * @param mem_area Destination memory area.
 * @param symbol   Byte value (only lower 8 bits are used).
 * @param num_bytes Number of bytes to write.
 * @return void* Original @p mem_area.
 */
void	*ft_memset(void *mem_area, int symbol, size_t num_bytes)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)mem_area;
	i = 0;
	while (i < num_bytes)
	{
		tmp[i] = (unsigned char)symbol;
		i++;
	}
	return (mem_area);
}
