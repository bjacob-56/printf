#include "printf.h"

void    fill_tab_indic(va_list ap, char **str, int *tab)
{
    if (ft_is_digit(**str) && !tab[1]) // a voir avec '.'
        tab[0] = ft_atoi_simplify(ap, str);
    if (**str == '-')
    {
        tab[1] = ft_atoi_simplify(ap, str);
        tab[0] = 0; // 0 ou -1 ?
    }
    if (**str == '.')
        tab[2] = ft_atoi_simplify(ap, str);
    if (**str == '*')
        tab[0] = ft_atoi_simplify(ap, str); // a gerer '*' en solo ?
}

void    str_add_hexa(va_list ap, int *nb_char, int *tab)
{
    void        *p;
    long int    add;
    int         len;
    int         nb;

    nb = 0;
    p = va_arg(ap, void*);
    add = (long int)(p);
    len = ft_nbrlen_base(add, 16);
    if (tab[0] < 0)
    {
        tab[0] *= -1;
        nb += ft_putspace(1, STDOUT);
    }
    nb += ft_put_zero_and_space_add(tab, len, STDOUT);
    nb += print_base_fd(add, STDOUT, "0123456789abcdef");
    nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
    *nb_char += nb;
}

void    str_unsigned_hexa(va_list ap, char **str, int *nb_char, int *tab)
{
    unsigned int    x;
    int             len;
    int             nb;

    nb = 0;
    x = va_arg(ap, unsigned int);
    len = ft_nbrlen_base(x, 16);
    nb += ft_put_zero_and_space(tab, len, STDOUT);
    if (**str == 'x')
        nb += print_base_fd(x, STDOUT, "0123456789abcdef");
    if (**str == 'X')
        nb += print_base_fd(x, STDOUT, "0123456789ABCDEF");
    nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
    *nb_char += nb;
}

int     ft_putchar_and_space_fd(int *tab, char c, int fd)
{
    int nb_space;

    nb_space = ft_max(ft_abs(tab[0]) - 1, 0);
    return (ft_putspace(nb_space, fd) + ft_putchar_fd(c, fd));
}

int     ft_putstr_and_space_fd(int *tab, char *s, int fd)
{
    int len;
    int nb_space;
    int nb_c;

    len = ft_strlen(s);
    if (tab[2] == -1)
        tab[2] = len;
    nb_c = ft_min(len, tab[2]);
    nb_space = ft_max(tab[0] - nb_c, 0);
    return (ft_putspace(nb_space, fd) + ft_putstrn_fd(s, nb_c, fd));
}