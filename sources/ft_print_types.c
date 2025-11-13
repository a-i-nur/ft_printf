#include "ft_printf.h"

int ft_print_types(va_list *arguments, t_argument arg_info)
{
    if (arg_info.type == 'c')
		retrurn(ft_c_type_print(arguments, arg_info));
    if (arg_info.type == 'p')
		retrurn(ft_p_type_print(arguments, arg_info));
    if (arg_info.type == 's')
		retrurn(ft_s_type_print(arguments, arg_info));
    if (arg_info.type == 'd' || arg_info.type == 'i')
		retrurn(ft_di_type_print(arguments, arg_info));
	if (arg_info.type == 'u')
		retrurn(ft_u_type_print(arguments, arg_info));
	if (arg_info.type == 'x' || arg_info.type == 'X')
		retrurn(ft_x_type_print(arguments, arg_info));
	if (arg_info.type == '%')
		retrurn(ft_prcnt_print(arg_info));
}
