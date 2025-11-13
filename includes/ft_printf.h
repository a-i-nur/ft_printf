/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:48:47 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/13 21:43:54 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_argument
{
    unsigned char   type;
    size_t          len;
} t_argument;
int	ft_printf(const char *format, ...);
static  t_argument ft_get_arg_info(const char *format, int index);
int ft_print_types(va_list *arguments, t_argument arg_info);
int ft_c_type_print(va_list *arguments, t_argument arg_info);
int ft_p_type_print(va_list *arguments, t_argument arg_info);
int ft_s_type_print(va_list *arguments, t_argument arg_info);
int ft_di_type_print(va_list *arguments, t_argument arg_info);
int ft_u_type_print(va_list *arguments, t_argument arg_info);
int ft_x_type_print(va_list *arguments, t_argument arg_info);
int ft_prcnt_print(arg_info);
#endif
