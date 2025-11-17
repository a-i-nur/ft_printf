#include "ft_printf.h"

int	ft_len_num_base(unsigned long number, int base)
{
	int	len_number;

	if (number == 0)
		return (1);
	len_number = 0;
	while (number != 0)
	{
		number = number / base;
		len_number++;
	}
	return (len_number);
}
