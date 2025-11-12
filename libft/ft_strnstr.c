/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:28:38 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:30 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate a substring within a limited-length prefix of a C string.
 *
 * Searches for the first occurrence of the NUL-terminated @p lit_str within
 * the first @p num characters of @p big_str. Characters after @p num are not
 * inspected. If @p lit_str is empty, @p big_str is returned.
 *
 * @param big_str Pointer to the haystack (NUL-terminated).
 * @param lit_str Pointer to the needle (NUL-terminated).
 * @param num     Maximum number of characters of @p big_str to search.
 * @return char*  Pointer to the beginning of the match in @p big_str, 
 * or NULL if not found.
 */
char	*ft_strnstr(const char *big_str, const char *lit_str, size_t num)
{
	size_t	i;
	size_t	len_lit;

	if (*lit_str == '\0')
		return ((char *)big_str);
	i = 0;
	len_lit = ft_strlen(lit_str);
	while (i < num && big_str[i] != '\0')
	{
		if (big_str[i] == lit_str[0])
		{
			if (len_lit <= num - i
				&& !ft_strncmp(big_str + i, lit_str, len_lit))
				return ((char *)(big_str + i));
		}
		i++;
	}
	return (NULL);
}
