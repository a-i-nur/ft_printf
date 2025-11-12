/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:18:05 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:47 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is printable, including space.
 *
 * Equivalent behavior to the `isprint()` function for ASCII inputs.
 *
 * @param symbol Integer representing the character.
 * @return 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int symbol)
{
	if (symbol >= 32 && symbol <= 126)
		return (1);
	return (0);
}
