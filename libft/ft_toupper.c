/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:04:14 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:13:09 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert an ASCII lowercase letter to uppercase.
 *
 * If @p chrctr is in the range 'a'..'z' (ASCII), it is converted to the
 * corresponding uppercase letter. All other values are returned unchanged.
 *
 * @note The behavior matches classic C ASCII semantics (no locale).
 *
 * @param chrctr Integer value of a character (typically an 
 * unsigned char cast to int).
 * @return int Uppercased character if applicable, otherwise the original value.
 */
int	ft_toupper(int chrctr)
{
	if (chrctr >= 'a' && chrctr <= 'z')
		chrctr = chrctr - ('a' - 'A');
	return (chrctr);
}
