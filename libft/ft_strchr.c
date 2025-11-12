/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:21:23 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:13:01 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Find the first occurrence of a character in a C string.
 *
 * Searches @p str for the first occurrence of the character (converted to
 * unsigned char) @p chrctr. The terminating '\\0' is considered part of the
 * string, so a search for '\\0' will return a pointer to the terminator.
 *
 * @param str     Pointer to a NUL-terminated C string.
 * @param chrctr  Character to locate (passed as int, 
 * converted to unsigned char).
 * @return char*  Pointer to the first occurrence within @p str, 
 * or NULL if not found.
 */
char	*ft_strchr(const char *str, int chrctr)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char)str[i] == (unsigned char)chrctr)
			return ((char *)str + i);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)chrctr)
		return ((char *)str + i);
	return (NULL);
}
