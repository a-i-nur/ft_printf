/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:18:10 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/13 21:32:46 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  ft_check_type(const char *format, int *index, va_list *arguments)
{
    t_argument  arg_info;
    int len_printed;
    
    arg_info = ft_get_arg_info(format, index);
    len_printed = 0;
    if (arg_info.type != 0)
        len_printed += ft_print_types(arguments, arg_info);
    else
    {
        ft_putchar_fd(format[*index], 1);
        len_printed++;
    }
    *index += arg_info.len;
    if (!arguments)
        printf("NO ARGS\n");
    return (len_printed);
}

static int ft_printf_run(const char *format, va_list *arguments)
{
    int len_result;
    int i;

    len_result = 0;
    i = 0;
    while(format[i])
    {
        if (format[i] == '%')
        {
            //printf("\n\ni1 = %d, len = %d\n\n", i, len_result);
            len_result += ft_check_type(format, &i, arguments);
            i++;
            //printf("\n\ni2 = %d, len = %d\n\n", i, len_result);
        } 
        else
        {
            ft_putchar_fd(format[i], 1);
            len_result++;
            i++;
        }
    }
    return (len_result);
}

int	ft_printf(const char *format, ...)
{
	va_list     arguments;
    int len_result;
    
    va_start(arguments, format);
    len_result = ft_printf_run(format, &arguments);
    va_end(arguments);
    return (len_result);
}

// int main()
// {
//     int my = ft_printf("HHELLO %% \n");
//     int org = printf("HELLOO %% \n");
//     printf("my = %d, org = %d\n", my, org);
// }
