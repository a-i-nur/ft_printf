#include "ft_printf.h"

int	ft_print_types(va_list *arguments, t_argument arg_info)
{
	if (arg_info.type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	if (arg_info.type == 'c')
		return (ft_print_c_type(arguments));
	if (arg_info.type == 'p')
		return (ft_print_p_type(arguments));
	if (arg_info.type == 's')
		return (ft_print_s_type(arguments));
	if (arg_info.type == 'd' || arg_info.type == 'i')
		return (ft_print_di_type(arguments));
	if (arg_info.type == 'u')
		return (ft_print_u_type(arguments));
	if (arg_info.type == 'x' || arg_info.type == 'X')
		return (ft_print_x_type(arguments, arg_info.type));
	return (0);
}
