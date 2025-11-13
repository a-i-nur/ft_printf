#include "ft_printf.h"

int ft_print_s_type(va_list *arguments, t_argument arg_info)
{
    char *str;
    
    str = va_arg(*arguments, char *);
    if (str == NULL)
        str = "(null)";
    ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}