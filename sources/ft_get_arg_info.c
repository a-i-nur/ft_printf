#include "ft_printf.h"

static char	ft_get_type(const char *format, int index, int *arg_len)
{
	index++;
	while (format[index] && format[index] != '%')
	{
		(*arg_len)++;
		if (format[index] == 'c')
			return ('c');
		if (format[index] == 's')
			return ('s');
		if (format[index] == 'p')
			return ('p');
		if (format[index] == 'i')
			return ('i');
		if (format[index] == 'd')
			return ('d');
		if (format[index] == 'u')
			return ('u');
		if (format[index] == 'x')
			return ('x');
		if (format[index] == 'X')
			return ('X');
		index++;
	}
	*arg_len = 0;
	return (0);
}

t_argument	ft_get_arg_info(const char *format, int index)
{
	t_argument	arg_inf;

	arg_inf.len = 0;
	if (format[index + 1] == '%')
	{
		arg_inf.type = '%';
		arg_inf.len = 1;
		return (arg_inf);
	}
	arg_inf.type = ft_get_type(format, index, &arg_inf.len);
	return (arg_inf);
}
