#include "ft_printf.h"

int	ft_print_s_type(va_list *arguments)
{
	char	*str;
	char	*null_answer;

	str = va_arg(*arguments, char *);
	null_answer = "(null)";
	if (!str)
		str = null_answer;
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
