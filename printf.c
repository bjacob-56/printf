#include "ft_printf.h"

void    str_convert(va_list ap, char **str, int *nb_char)
{
    if (**str == 'c')
        str_char(ap, nb_char);
    if (**str == 's')
        str_string(ap, nb_char);
    if (**str == 'p')
        str_hexa(ap, nb_char);
    if (**str == 'i' || **str == 'd')
        str_int(ap, nb_char);
    if (**str == 'u')
        str_decimal(ap, nb_char);
    if (**str == 'x' || **str == 'X')
        str_unsigned_hexa(ap, str, nb_char);
    if (**str == '%')
        str_percent(nb_char);
}


void    str_process(va_list ap, char **str, int *nb_char)
{
    if (*(*str) == '%')
        {
            (*str)++;
            str_convert(ap, str, nb_char);
        }
    else
        *nb_char += ft_putchar_fd(**str, STDOUT);
    (*str)++;
}


int ft_printf(const char *format, ...)
{
    va_list ap;
    char    *str;
    int     nb_char;
    
    str = (char*)format;
    va_start(ap, format);
    nb_char = 0;
    while (*str)
        str_process(ap, &str, &nb_char);

    va_end(ap);
    return (nb_char);
}