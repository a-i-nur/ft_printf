#include "ft_printf.h"

void	ft_putnbr_base_fd(unsigned long n, char *digits_base, int base, int fd)
{
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n >= (unsigned long)base)
		ft_putnbr_base_fd((n / base), digits_base, base, fd);
	ft_putchar_fd(digits_base[n % base], fd);
}
