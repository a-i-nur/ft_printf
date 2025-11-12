/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:10:45 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:19:06 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert an ASCII uppercase letter to lowercase.
 *
 * If @p chrctr is in the range 'A'..'Z' (ASCII), it is converted to the
 * corresponding lowercase letter. All other values are returned unchanged.
 *
 * @note The behavior matches classic C ASCII semantics (no locale).
 *
 * @param chrctr Integer value of a character (typically an 
 * unsigned char cast to int).
 * @return int Lowercased character if applicable, otherwise the original value.
 */
int	ft_tolower(int chrctr)
{
	if (chrctr >= 'A' && chrctr <= 'Z')
		chrctr = chrctr + ('a' - 'A');
	return (chrctr);
}
