/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:53:15 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/06 13:31:08 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count leading ASCII whitespace characters.
 *
 * Walks over spaces, tabs, and other standard ASCII whitespace characters
 * at the beginning of @p str.
 *
 * @param str Input C-string.
 * @return int Index of the first non-whitespace character.
 */
static int	ft_checkspace(const char *str)
{
	int	count;

	count = 0;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\t'
		|| str[count] == '\r' || str[count] == '\f' || str[count] == '\v')
		count++;
	return (count);
}

/**
 * @brief Convert initial part of a string to int (ASCII, no locale).
 *
 * Skips leading whitespace, then an optional '+' or '-' sign, then
 * consumes consecutive decimal digits to produce an int result.
 * Stops at the first non-digit. Overflow behavior matches standard atoi
 * (implementation-defined / undefined).
 *
 * @param str NUL-terminated input string.
 * @return int Parsed integer value.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	i = ft_checkspace(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0') * sign;
		i++;
	}
	return (num);
}
