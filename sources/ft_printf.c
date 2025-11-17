/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:18:10 by aakhmeto          #+#    #+#             */
/*   Updated: 2025/11/17 17:03:31 by dev              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(const char *format, int *index, va_list *arguments)
{
	t_argument	arg_info;
	int			len_printed;

	arg_info = ft_get_arg_info(format, *index);
	len_printed = 0;
	if (arg_info.type != 0)
		len_printed += ft_print_types(arguments, arg_info);
	else
	{
		ft_putchar_fd(format[*index], 1);
		len_printed++;
	}
	*index += arg_info.len;
	return (len_printed);
}

static int	ft_printf_run(const char *format, va_list *arguments)
{
	int	len_result;
	int	i;

	len_result = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len_result += ft_check_type(format, &i, arguments);
			i++;
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
	va_list	arguments;
	int		len_result;

	va_start(arguments, format);
	len_result = ft_printf_run(format, &arguments);
	va_end(arguments);
	return (len_result);
}

// int main(void)
// {
//     int             my;
//     int             org;
//
//     char            c = 'A';
//     char            c_zero = '\0';
//     char            *s = "строка";
//     char            *s_empty = "";
//     char            *s_null = NULL;
//     void            *p = s;
//     void            *p_null = NULL;
//     int             d_neg = -1234;
//     int             d_zero = 0;
//     int             d_pos = 5678;
//     int             d_int_max = INT_MAX;
//     int             d_int_min = INT_MIN;
//     unsigned int    u_small = 42u;
//     unsigned int    u_zero = 0u;
//     unsigned int    u_big = 4000000000u;
//     unsigned int    u_uint_max = UINT_MAX;
//     unsigned int    x_val = 0xDEADBEEF;
//     unsigned int    x_zero = 0u;
//     unsigned int    x_small = 15u;

//     /* 1. Базовый смешанный тест из примера */
//     printf("========== BASIC MIXED TEST ==========\n");
//     my = ft_printf("ft : c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
//                    c, s, p, d_neg, d_pos, u_big, x_val, x_val);
//     org = printf("org: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
//                  c, s, p, d_neg, d_pos, u_big, x_val, x_val);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     /* 2. %c — обычные и нулевой символ */
//     printf("========== %%c TESTS ==========\n");
//     my = ft_printf("ft : c='%c'\n", c);
//     org = printf("org: c='%c'\n", c);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : zero char[%c]\n", c_zero);
//     org = printf("org: zero char[%c]\n", c_zero);
//     printf("ret: ft=%d org=%d (длина должна учитывать невидимый '\\0')\n\n", 
// 		my, org);

//     /* 3. %s — обычная, пустая и NULL строки */
//     printf("========== %%s TESTS ==========\n");
//     my = ft_printf("ft : s=\"%s\"\n", s);
//     org = printf("org: s=\"%s\"\n", s);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : empty=\"%s\"\n", s_empty);
//     org = printf("org: empty=\"%s\"\n", s_empty);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : null=\"%s\"\n", s_null);
//     org = printf("org: null=\"%s\"\n", s_null);
//     printf("ret: ft=%d org=%d (обычно печатается \"(null)\")\n\n", my, org);

//     /* 4. %p — нормальный, NULL и «левый» указатель */
//     printf("========== %%p TESTS ==========\n");
//     my = ft_printf("ft : p=%p\n", p);
//     org = printf("org: p=%p\n", p);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : p_null=%p\n", p_null);
//     org = printf("org: p_null=%p\n", p_null);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : p_minus1=%p\n", (void *)-1);
//     org = printf("org: p_minus1=%p\n", (void *)-1);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     /* 5. %d и %i — разные значения, включая границы int */
//     printf("========== %%d / %%i TESTS ==========\n");
//     my = ft_printf("ft : d_zero=%d d_pos=%d d_neg=%d\n", d_zero, d_pos, d_neg);
//     org = printf("org: d_zero=%d d_pos=%d d_neg=%d\n", d_zero, d_pos, d_neg);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : INT_MAX=%d INT_MIN=%d\n", d_int_max, d_int_min);
//     org = printf("org: INT_MAX=%d INT_MIN=%d\n", d_int_max, d_int_min);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : i_zero=%i i_pos=%i i_neg=%i\n", d_zero, d_pos, d_neg);
//     org = printf("org: i_zero=%i i_pos=%i i_neg=%i\n", d_zero, d_pos, d_neg);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     /* 6. %u — 0, маленькое, большое и UINT_MAX */
//     printf("========== %%u TESTS ==========\n");
//     my = ft_printf("ft : u_zero=%u u_small=%u\n", u_zero, u_small);
//     org = printf("org: u_zero=%u u_small=%u\n", u_zero, u_small);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : u_big=%u UINT_MAX=%u\n", u_big, u_uint_max);
//     org = printf("org: u_big=%u UINT_MAX=%u\n", u_big, u_uint_max);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     /* 7. %x и %X — 0, маленькое, большое значение */
//     printf("========== %%x / %%X TESTS ==========\n");
//     my = ft_printf("ft : x_zero=%x x_small=%x x_val=%x\n", x_zero, 
// 		x_small, x_val);
//     org = printf("org: x_zero=%x x_small=%x x_val=%x\n", x_zero, 
// 		x_small, x_val);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : X_zero=%X X_small=%X X_val=%X\n", x_zero, 
// 		x_small, x_val);
//     org = printf("org: X_zero=%X X_small=%X X_val=%X\n", x_zero, 
// 		x_small, x_val);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     /* 8. %% — разные комбинации процентов */
//     printf("========== %%%% TESTS ==========\n");
//     my = ft_printf("ft : single %%\n");
//     org = printf("org: single %%\n");
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     my = ft_printf("ft : many %%%% %%%% %%%% end\n");
//     org = printf("org: many %%%% %%%% %%%% end\n");
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     /* 9. Комбинированный стресс-тест одной строкой */
//     printf("========== COMBINED STRESS TEST ==========\n");
//     my = ft_printf("ft : c=%c s=%s null_s=%s p=%p p0=%p d=%d "
//       "i=%i u=%u x=%x X=%X %% int_max=%d int_min=%d uint_max=%u\n",
//                    c, s, s_null, p, p_null,
//                    d_neg, d_pos, u_big, x_val, x_val,
//                    d_int_max, d_int_min, u_uint_max);
//     org = printf("org: c=%c s=%s null_s=%s p=%p p0=%p d=%d i=%i u=%u "
//       "x=%x X=%X %% int_max=%d int_min=%d uint_max=%u\n",
//                  c, s, s_null, p, p_null,
//                  d_neg, d_pos, u_big, x_val, x_val,
//                  d_int_max, d_int_min, u_uint_max);
//     printf("ret: ft=%d org=%d\n\n", my, org);

//     return 0;
// }

