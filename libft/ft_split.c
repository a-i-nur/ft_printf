/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:33:25 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/07 17:25:22 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Count substrings separated by delimiter @p c.
 *
 * Iterates over @p s up to @p len_s characters and counts how many
 * non-empty segments are separated by the delimiter.
 *
 * @param s Input string.
 * @param c Delimiter character.
 * @param len_s Length of @p s (precomputed).
 * @return size_t Number of resulting substrings.
 */
static size_t	ft_count_numlines(char const *s, char c, size_t len_s)
{
	size_t	num_lines;
	size_t	i;

	num_lines = 0;
	i = 0;
	while (i < len_s)
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			num_lines++;
		}
		i++;
	}
	return (num_lines);
}

/**
 * @brief Free partially created split result.
 *
 * Frees strings in @p arr_str up to @p num_line and then frees the array
 * itself. Used on allocation failure paths.
 *
 * @param arr_str Array of strings to clean up.
 * @param num_line Highest allocated index.
 * @return int Always 0 to signal failure upstream.
 */
static int	ft_liberator(char **arr_str, size_t num_line)
{
	size_t	i;

	i = 0;
	while (i <= num_line)
	{
		free(arr_str[i]);
		i++;
	}
	free(arr_str);
	return (0);
}

/**
 * @brief Copy a substring into a newly allocated buffer.
 *
 * Copies @p str_len characters from @p str into @p str_arr and terminates
 * the result with NUL.
 *
 * @param str Source pointer.
 * @param str_arr Destination buffer.
 * @param str_len Number of characters to copy.
 */
static void	ft_copy_line(const char *str, char *str_arr, size_t str_len)
{
	size_t	i;

	i = 0;
	while (i < str_len)
	{
		str_arr[i] = *(str + i);
		i++;
	}
	str_arr[i] = '\0';
}

/**
 * @brief Populate the output array with substrings.
 *
 * Iterates over @p s, allocates each substring bounded by delimiter @p c,
 * and stores it in @p arr_str. On allocation failure, cleans up via
 * ft_liberator().
 *
 * @param arr_str Destination array sized to @p len_arr.
 * @param len_arr Expected number of substrings.
 * @param s Input string.
 * @param c Delimiter character.
 * @return int 1 on success, 0 if allocation failed.
 */
static int	ft_create_lines(char **arr_str, size_t len_arr,
	char const *s, char c)
{
	size_t	i;
	size_t	num_line;
	size_t	size_line;

	i = 0;
	num_line = 0;
	while (num_line < len_arr)
	{
		size_line = 0;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			size_line++;
		}
		if (size_line != 0)
		{
			arr_str[num_line] = (char *)malloc((size_line +1) * sizeof(char));
			if (!arr_str[num_line])
				return (ft_liberator(arr_str, num_line));
			ft_copy_line(s + i - size_line, arr_str[num_line], size_line);
			num_line++;
		}
		i++;
	}	
	return (1);
}

/**
 * @brief Split a string by a delimiter into an array of strings.
 *
 * Splits @p s on delimiter character @p c into a NULL-terminated array
 * of newly allocated tokens. Consecutive delimiters produce no empty tokens
 * (i.e., they are skipped). Returns NULL on allocation failure.
 *
 * @param s Input string (NUL-terminated).
 * @param c Delimiter character.
 * @return char** NULL-terminated array of newly allocated strings, or NULL.
 */
char	**ft_split(char const *s, char c)
{
	char	**arr_str;
	size_t	len_s;
	size_t	num_lines;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	num_lines = ft_count_numlines(s, c, len_s);
	arr_str = (char **)malloc((num_lines + 1) * sizeof(char *));
	if (!arr_str)
		return (NULL);
	arr_str[num_lines] = NULL;
	if (ft_create_lines(arr_str, num_lines, s, c) == 0)
		return (NULL);
	return (arr_str);
}
