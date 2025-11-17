#include "ft_printf.h"

int	ft_print_x_type(va_list *arguments, char type)
{
	unsigned int	number;
	int				base;
	char			*digits_upper;
	char			*digits_capital;

	number = (unsigned int)va_arg(*arguments, unsigned int);
	base = 16;
	if (number == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	digits_upper = "0123456789abcdef";
	digits_capital = "0123456789ABCDEF";
	if (type == 'x')
		ft_putnbr_base_fd((unsigned long)number, digits_upper, base, 1);
	else if (type == 'X')
		ft_putnbr_base_fd((unsigned long)number, digits_capital, base, 1);
	return (ft_len_num_base((unsigned long)number, base));
}
