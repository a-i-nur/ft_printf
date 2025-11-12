/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:43:32 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:36 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two C strings up to a maximum number of bytes.
 *
 * Compares @p str1 and @p str2 lexicographically as sequences of unsigned char,
 * but examines at most @p num bytes. Comparison stops at the first difference,
 * at a NUL byte, or after @p num bytes. If @p num is 0, the result is 0.
 *
 * @param str1 First NUL-terminated C string.
 * @param str2 Second NUL-terminated C string.
 * @param num  Maximum number of bytes to compare.
 * @return int <0 if str1<str2, 0 if equal within @p num, >0 if str1>str2.
 */
int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	const unsigned char	*strng1;
	const unsigned char	*strng2;
	size_t				i;

	strng1 = (const unsigned char *)str1;
	strng2 = (const unsigned char *)str2;
	i = 0;
	while (i < num)
	{
		if (strng1[i] != strng2[i] || strng1[i] == '\0' || strng2[i] == '\0')
			return (strng1[i] - strng2[i]);
		i++;
	}
	return (0);
}
