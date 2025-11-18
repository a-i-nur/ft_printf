/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakhmeto <aakhmeto@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:48:47 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/18 17:49:47 by aakhmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_argument
{
	unsigned char	type;
	int				len;
}				t_argument;
int			ft_printf(const char *format, ...);
t_argument	ft_get_arg_info(const char *format, int index);
int			ft_print_types(va_list *arguments, t_argument arg_info);
int			ft_print_c_type(va_list *arguments);
int			ft_print_p_type(va_list *arguments);
int			ft_print_s_type(va_list *arguments);
int			ft_print_di_type(va_list *arguments);
int			ft_print_u_type(va_list *arguments);
int			ft_print_x_type(va_list *arguments, char type);
int			ft_len_num_base(unsigned long number, int base);
int			ft_putnbr_base_fd(unsigned long n,
				char *digits_base, int base, int fd);
int			ft_putchar_fd_ret(char c, int fd);
int			ft_putstr_fd_ret(char *s, int fd);
int			ft_putnbr_fd_ret(int n, int fd);

#endif
