#include "ft_printf.h"

int	ft_print_p_type(va_list *arguments)
{
	void			*pntr;
	unsigned long	number;
	int				len_pntr;
	int				base;
	char			*null_answer;

	pntr = (void *)va_arg(*arguments, void *);
	null_answer = "(nil)";
	if (!pntr)
	{
		ft_putstr_fd(null_answer, 1);
		return (ft_strlen(null_answer));
	}
	number = (unsigned long)pntr;
	len_pntr = 2;
	base = 16;
	ft_putstr_fd("0x", 1);
	ft_putnbr_base_fd((unsigned long)number, "0123456789abcdef", base, 1);
	len_pntr += ft_len_num_base((unsigned long)number, base);
	return (len_pntr);
}
