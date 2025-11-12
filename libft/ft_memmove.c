/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:07:34 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:21 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies bytes between possibly overlapping memory areas safely.
 *
 * Copies @p num_bytes from @p src_mem to @p dst_mem. Handles overlap by
 * choosing copy direction: forward if dst < src, backward otherwise.
 *
 * @param dst_mem Destination buffer.
 * @param src_mem Source buffer.
 * @param num_bytes Number of bytes to copy.
 * @return void* Original @p dst_mem.
 */
void	*ft_memmove(void *dst_mem, const void *src_mem, size_t num_bytes)
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
	if (dst_tmp < src_tmp)
	{
		while (i++ < num_bytes)
			dst_tmp[i - 1] = src_tmp[i - 1];
	}
	else
	{
		i = num_bytes;
		while (i-- > 0)
			dst_tmp[i] = src_tmp[i];
	}
	return (dst_mem);
}
