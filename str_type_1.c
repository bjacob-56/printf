#include "ft_printf.h"

void    str_int(va_list ap, int *nb_char)
{
    int i;

    i = va_arg(ap, int);
    *nb_char += ft_putnbr_fd(i, STDOUT);
}

void    str_char(va_list ap, int *nb_char)
{
    int i;

    i = va_arg(ap, int);
    *nb_char += ft_putchar_fd(i, STDOUT);
}

void    str_string(va_list ap, int *nb_char)
{
    char    *s;

    s = va_arg(ap, char*);
    *nb_char += ft_putstr_fd(s, STDOUT);
}

void    str_percent(int *nb_char)
{
    *nb_char += ft_putchar_fd('%', STDOUT);
}

void    str_decimal(va_list ap, int *nb_char)
{
    unsigned int    u;

    u = va_arg(ap, unsigned int);
    *nb_char += ft_putnbr_fd(u, STDOUT);
}