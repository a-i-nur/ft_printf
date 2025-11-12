/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:07:32 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/12 18:14:44 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compute the length of the textual representation of an int.
 *
 * Determines how many characters are required to print @p num in base 10,
 * including a potential minus sign, and updates @p sign to -1 if the number
 * is negative.
 *
 * @param num Value to measure.
 * @param sign Output parameter receiving 1 or -1 for the sign.
 * @return int Number of characters required.
 */
static int	ft_count_symb(int num, int *sign)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		*sign = -1;
	}
	else if (num == 0)
		count++;
	while (num != 0)
	{
		num = (num - num % 10) / 10;
		count++;
	}
	return (count);
}

/**
 * @brief Write the digits of an int into a buffer.
 *
 * Fills @p num with the decimal digits of @p n, using @p sign to handle the
 * negative case and assuming the buffer has length @p len_num.
 *
 * @param n Value to convert.
 * @param num Destination buffer.
 * @param len_num Number of characters to fill (excluding terminator).
 * @param sign 1 for positive numbers, -1 for negative numbers.
 */
static void	ft_trans(int n, char *num, int len_num, int sign)
{
	int	digit;
	int	i;

	i = len_num - 1;
	while (i >= 0)
	{
		if (sign < 0 && i == 0)
		{
			num[i] = '-';
			break ;
		}
		digit = n % 10;
		num[i] = (digit * sign) + '0';
		n = (n - digit) / 10;
		i--;
	}
}

/**
 * @brief Convert an int to a newly allocated string.
 *
 * Produces the decimal textual representation of @p n (base 10) including
 * a leading '-' for negative values. Returns NULL on allocation failure.
 *
 * @param n Integer to convert.
 * @return char* Newly allocated string representation, or NULL.
 */
char	*ft_itoa(int n)
{
	char	*num;
	int		len_num;
	int		sign;

	sign = 1;
	len_num = ft_count_symb(n, &sign);
	num = (char *)malloc((len_num + 1) * sizeof(char));
	if (!num)
		return (NULL);
	ft_trans(n, num, len_num, sign);
	num[len_num] = '\0';
	return (num);
}
