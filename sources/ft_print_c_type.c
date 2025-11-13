#include "ft_printf.h"

int ft_print_c_type(va_list *arguments, t_argument arg_info)
{
    char chrctr;
    
    chrctr = (char)va_arg(*arguments, int);
    ft_putchar_fd(chrctr, 1);
    return (1);
}