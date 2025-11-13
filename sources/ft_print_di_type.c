#include "ft_printf.h"

static int fr_len_num(int number)
{
    long num;
    int len_num;

    num = (long)number;
    if (num == 0)
        return (1);
    len_num = 0;
    if (num < 0)
    {
        len_num++;
        num *= -1;
    }
    while (num != 0)
    {
        num = num / 10;
        len_num++;
    }
    return (len_num);
}

int ft_print_di_type(va_list *arguments, t_argument arg_info)
{
    int number;

    number = va_arg(*arguments, int);
    ft_putnbr_fd(number, 1);
    return (ft_len_num(number));
}