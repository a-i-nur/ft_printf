/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:51:19 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:20 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a character is a digit (0-9).
 *
 * Equivalent behavior to the standard `isdigit()` function.
 *
 * @param symbol Integer representing the character to check.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return (1);
	return (0);
}
