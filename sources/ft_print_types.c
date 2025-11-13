#include "ft_printf.h"

int ft_print_types(va_list *arguments, t_argument arg_info)
{
    if (arg_info.type == 'c')
		retrurn(ft_print_c_type(arguments, arg_info));
    if (arg_info.type == 'p')
		retrurn(ft_print_p_type(arguments, arg_info));
    if (arg_info.type == 's')
		retrurn(ft_print_s_type(arguments, arg_info));
    if (arg_info.type == 'd' || arg_info.type == 'i')
		retrurn(ft_print_di_type(arguments, arg_info));
	if (arg_info.type == 'u')
		retrurn(ft_print_u_type(arguments, arg_info));
	if (arg_info.type == 'x' || arg_info.type == 'X')
		retrurn(ft_print_x_type(arguments, arg_info));
}
