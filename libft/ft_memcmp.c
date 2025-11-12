/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:07:28 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:28 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two memory areas byte by byte.
 *
 * Compares the first @p num_bytes of @p area1 and @p area2 as sequences of
 * unsigned char. The result indicates the lexical ordering of 
 * the first pair of
 * differing bytes, or 0 if all compared bytes are equal. If @p num_bytes is 0,
 * the result is 0.
 *
 * @param area1     Pointer to the first memory block.
 * @param area2     Pointer to the second memory block.
 * @param num_bytes Number of bytes to compare.
 * @return int <0 if area1<area2, 0 if equal, >0 if area1>area2.
 */
int	ft_memcmp(const void *area1, const void *area2, size_t num_bytes)
{
	const unsigned char	*mem_tmp1;
	const unsigned char	*mem_tmp2;
	size_t				i;

	mem_tmp1 = (const unsigned char *)area1;
	mem_tmp2 = (const unsigned char *)area2;
	i = 0;
	while (i < num_bytes)
	{
		if (mem_tmp1[i] != mem_tmp2[i])
			return (mem_tmp1[i] - mem_tmp2[i]);
		i++;
	}
	return (0);
}
