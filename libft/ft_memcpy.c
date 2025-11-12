/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 12:14:32 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:23 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies bytes from source to destination (no overlap allowed).
 *
 * Copies @p num_bytes from @p src_mem to @p dst_mem. Behavior is undefined
 * if the memory areas overlap. For overlapping regions use ft_memmove().
 *
 * @param dst_mem Destination buffer.
 * @param src_mem Source buffer.
 * @param num_bytes Number of bytes to copy.
 * @return void* Original @p dst_mem.
 */
void	*ft_memcpy(void *dst_mem, const void *src_mem, size_t num_bytes)
{
	const unsigned char	*src_tmp;
	unsigned char		*dst_tmp;
	size_t				i;

	src_tmp = (const unsigned char *)src_mem;
	dst_tmp = (unsigned char *)dst_mem;
	i = 0;
	if (!dst_mem && !src_mem)
		return (NULL);
	if (dst_mem == src_mem || num_bytes == 0)
		return (dst_mem);
	while (i < num_bytes)
	{
		dst_tmp[i] = src_tmp[i];
		i++;
	}
	return (dst_mem);
}
