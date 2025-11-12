/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:06:27 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:22 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a value is a valid ASCII code (0–127).
 *
 * Unlike the standard `isascii()` extension, this function strictly
 * returns 1 for valid ASCII values and 0 otherwise.
 *
 * @param symbol Integer to test.
 * @return 1 if the value is within ASCII range, 0 otherwise.
 */
int	ft_isascii(int symbol)
{
	if (symbol >= 0 && symbol <= 127)
		return (1);
	return (0);
}
