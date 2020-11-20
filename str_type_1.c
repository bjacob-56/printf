#include "ft_printf.h"

void    str_int(va_list ap, int *nb_char, int *tab)
{
    int i;
    int len;

    i = va_arg(ap, int);
    len = ft_nbrlen_base(i, 10);
    if (tab[0] < 0)
    {
        tab[0] *= -1;
        *nb_char += ft_putspace(1, STDOUT);
    }
    *nb_char += ft_put_zero_and_space(tab, len, STDOUT);
    *nb_char += ft_putnbr_fd(i, STDOUT);
}

void    str_char(va_list ap, int *nb_char, int *tab)
{
    int i;

    i = va_arg(ap, int);
    *nb_char += ft_putchar_and_space_fd(tab, i, STDOUT);
}

void    str_string(va_list ap, int *nb_char, int *tab)
{
    char    *s;

    s = va_arg(ap, char*);
    *nb_char += ft_putstr_and_space_fd(tab, s, STDOUT);
}

void    str_percent(int *nb_char)
{
    *nb_char += ft_putchar_fd('%', STDOUT);
}

void    str_decimal(va_list ap, int *nb_char, int *tab)
{
    unsigned int    u;
    int             len;

    u = va_arg(ap, unsigned int);
    len = ft_nbrlen_base(u, 10);
    *nb_char += ft_put_zero_and_space(tab, len, STDOUT);
    *nb_char += ft_putnbr_fd(u, STDOUT);
}