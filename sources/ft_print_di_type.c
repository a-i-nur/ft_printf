#include "ft_printf.h"

int	ft_print_di_type(va_list *arguments)
{
	int		number;
	int		base;
	int		len_num;
	long	num_lng;

	number = va_arg(*arguments, int);
	ft_putnbr_fd(number, 1);
	len_num = 0;
	base = 10;
	if (number < 0)
	{
		len_num++;
		num_lng = (long)number * -1;
	}
	else
		num_lng = (long)number;
	len_num += ft_len_num_base((unsigned long)num_lng, base);
	return (len_num);
}
