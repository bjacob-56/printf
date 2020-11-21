#include "printf.h"

void    str_int(va_list ap, int *nb_char, int *tab)
{
    int i;
    int len;
    int nb;

    nb = 0;
    i = va_arg(ap, int);
    len = ft_nbrlen_base(i, 10);
    if (tab[0] < 0)
    {
        tab[0] *= -1;
        nb += ft_putspace(1, STDOUT);
    }
    nb += ft_put_zero_and_space(tab, len, STDOUT);
    nb += ft_putnbr_fd(i, STDOUT);
    nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
    *nb_char += nb;
}

void    str_char(va_list ap, int *nb_char, int *tab)
{
    int i;
    int nb;

    nb = 0;
    i = va_arg(ap, int);
    nb += ft_putchar_and_space_fd(tab, i, STDOUT);
    nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
    *nb_char += nb;
}

void    str_string(va_list ap, int *nb_char, int *tab)
{
    char    *s;
    int     nb;

    nb = 0;
    s = va_arg(ap, char*);
    nb += ft_putstr_and_space_fd(tab, s, STDOUT);
    nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
    *nb_char += nb;
}

void    str_percent(int *nb_char)
{
    *nb_char += ft_putchar_fd('%', STDOUT);
}

void    str_decimal(va_list ap, int *nb_char, int *tab)
{
    unsigned int    u;
    int             len;
    int             nb;

    nb = 0;
    u = va_arg(ap, unsigned int);
    len = ft_nbrlen_base(u, 10);
    nb += ft_put_zero_and_space(tab, len, STDOUT);
    nb += ft_putnbr_fd(u, STDOUT);
    nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
    *nb_char += nb;
}