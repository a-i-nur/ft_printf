#include "ft_printf.h"

int	ft_print_u_type(va_list *arguments)
{
	unsigned int	number;
	int				base;
	char			*digits;

	number = va_arg(*arguments, unsigned int);
	base = 10;
	digits = "0123456789";
	ft_putnbr_base_fd((unsigned long)number, digits, base, 1);
	return (ft_len_num_base((unsigned  long)number, base));
}
