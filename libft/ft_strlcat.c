/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:56:28 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:49 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends a C string to a sized buffer like BSD strlcat.
 *
 * Appends src_str to dst_str of total size size_dst. Guarantees NUL-termination
 * if size_dst > 0 and size_dst > initial length of dst. Returns the length
 * it tried to create: initial_len(dst) + len(src).
 *
 * @param dst_str Destination buffer containing initial C string.
 * @param src_str Source C string to append.
 * @param size_dst Total size of destination buffer.
 * @return size_t initial_len(dst) + len(src).
 */
size_t	ft_strlcat(char *dst_str, const char *src_str, size_t size_dst)
{
	size_t	len_dst;
	size_t	len_str;
	size_t	i;
	size_t	j;

	len_dst = 0;
	while (len_dst < size_dst && dst_str[len_dst] != 0)
		len_dst++;
	len_str = ft_strlen(src_str);
	if (size_dst == len_dst)
		return (size_dst + len_str);
	i = 0;
	j = len_dst;
	while (j < size_dst - 1 && i < len_str)
	{
		dst_str[j] = src_str[i];
		j++;
		i++;
	}
	dst_str[j] = '\0';
	return (len_dst + len_str);
}
