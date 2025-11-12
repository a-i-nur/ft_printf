/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:49:33 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:24 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find the last occurrence of a character in a C string.
 *
 * Searches @p str for the final occurrence of the character (converted to
 * unsigned char) @p chrctr. The terminating '\\0' is considered part of the
 * string, so a search for '\\0' will return a pointer to the terminator.
 *
 * @param str     Pointer to a NUL-terminated C string.
 * @param chrctr  Character to locate (passed as int, 
 * converted to unsigned char).
 * @return char*  Pointer to the last occurrence within @p str, 
 * or NULL if not found.
 */
char	*ft_strrchr(const char *str, int chrctr)
{
	size_t			len;
	size_t			i;
	unsigned char	trgt;

	len = ft_strlen(str);
	trgt = (unsigned char)chrctr;
	i = len;
	while (i > 0)
	{
		if ((unsigned char)str[i] == trgt)
			return ((char *)str + i);
		i--;
	}
	if ((unsigned char)str[i] == trgt)
		return ((char *)str + i);
	return (NULL);
}
