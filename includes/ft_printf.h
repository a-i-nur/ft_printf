/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:48:47 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 19:01:06 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
/*# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>*/

typedef struct s_argument
{
	unsigned char	type;
	int				len;
}				t_argument;
/**
 * @brief Print formatted output like printf.
 * @param format Format string.
 * @return Bytes written or -1 on write error.
 */
int			ft_printf(const char *format, ...);
/**
 * @brief Parse specifier starting at % and return its metadata.
 * @param format Format string.
 * @param index Index of the % character.
 * @return Parsed argument description.
 */
t_argument	ft_get_arg_info(const char *format, int index);
/**
 * @brief Dispatch parsed argument to the proper print helper.
 * @param arguments Variadic arguments list.
 * @param arg_info Parsed specifier info.
 * @return Bytes written or -1 when write fails.
 */
int			ft_print_types(va_list *arguments, t_argument arg_info);
/**
 * @brief Print %c conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int			ft_print_c_type(va_list *arguments);
/**
 * @brief Print %p conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int			ft_print_p_type(va_list *arguments);
/**
 * @brief Print %s conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int			ft_print_s_type(va_list *arguments);
/**
 * @brief Print %d and %i conversions.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int			ft_print_di_type(va_list *arguments);
/**
 * @brief Print %u conversion.
 * @param arguments Variadic arguments list.
 * @return Bytes written or -1 when write fails.
 */
int			ft_print_u_type(va_list *arguments);
/**
 * @brief Print %x and %X conversions.
 * @param arguments Variadic arguments list.
 * @param type Requested hex variant.
 * @return Bytes written or -1 when write fails.
 */
int			ft_print_x_type(va_list *arguments, char type);
/**
 * @brief Return digits count of number in given base.
 * @param number Number to measure.
 * @param base Numerical base (>=2).
 * @return Amount of digits in that base.
 */
int			ft_len_num_base(unsigned long number, int base);
/**
 * @brief Print unsigned long in given base to fd.
 * @param n Number to print.
 * @param digits_base Digits string for the base.
 * @param base Numerical base (>=2).
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int			ft_putnbr_base_fd(unsigned long n,
				char *digits_base, int base, int fd);
/**
 * @brief Write char to fd and return bytes or -1.
 * @param c Character to print.
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int			ft_putchar_fd_ret(char c, int fd);
/**
 * @brief Write string to fd and return status.
 * @param s String to print (can be NULL).
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int			ft_putstr_fd_ret(char *s, int fd);
/**
 * @brief Write signed int to fd and return status.
 * @param n Number to print.
 * @param fd Destination file descriptor.
 * @return 1 on success, -1 on write failure.
 */
int			ft_putnbr_fd_ret(int n, int fd);

#endif
