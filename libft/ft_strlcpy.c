/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:15:44 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:45 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies a C string into a sized buffer like BSD strlcpy.
 *
 * Copies up to dst_size-1 bytes from @p src_str into @p dst_str,
 * NUL-terminates if dst_size > 0. Returns total length of @p src_str.
 * Safe for all inputs; no overlap handling is specified.
 *
 * @param dst_str Destination buffer.
 * @param src_str Source C string (must be NUL-terminated).
 * @param dst_size Size of destination buffer in bytes.
 * @return size_t Total length of src_str (not the number copied).
 */
size_t	ft_strlcpy(char *dst_str, const char *src_str, size_t dst_size)
{
	size_t	len_src;
	size_t	i;

	i = 0;
	len_src = ft_strlen(src_str);
	if (dst_size == 0)
		return (len_src);
	while (i < len_src && i < dst_size - 1)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	dst_str[i] = '\0';
	return (len_src);
}
