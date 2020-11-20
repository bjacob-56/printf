#include "ft_printf.h"

void    fill_tab_indic(va_list ap, char **str, int *tab)
{
    if (**str == '0' && !tab[1]) // a voir avec '.'
        tab[0] = ft_atoi_simplify(ap, str);
    if (**str == '-')
    {
        tab[1] = ft_atoi_simplify(ap, str);
        tab[0] = 0; // 0 ou -1 ?
    }
    if (**str == '.')
        tab[2] = ft_atoi_simplify(ap, str);
    if (**str == '*')
        tab[3] = ft_atoi_simplify(ap, str); // a gerer '*' en solo ?
}

void    str_add_hexa(va_list ap, int *nb_char, int *tab)
{
    void        *p;
    long int    add;
    int         len;

    p = va_arg(ap, void*);
    add = (long int)(p);
    len = ft_nbrlen_base(add, 16);
    if (tab[0] < 0)
    {
        tab[0] *= -1;
        *nb_char += ft_putspace(1, STDOUT);
    }
    *nb_char += ft_put_zero_and_space_add(tab, len, STDOUT);
    *nb_char += print_base_fd(add, STDOUT, "0123456789abcdef");

}

void    str_unsigned_hexa(va_list ap, char **str, int *nb_char, int *tab)
{
    unsigned int    x;
    int             len;

    x = va_arg(ap, unsigned int);
    len = ft_nbrlen_base(x, 16);
    *nb_char += ft_put_zero_and_space(tab, len, STDOUT);
    if (**str == 'x')
        *nb_char += print_base_fd(x, STDOUT, "0123456789abcdef");
    if (**str == 'X')
        *nb_char += print_base_fd(x, STDOUT, "0123456789ABCDEF");
}

int     ft_putchar_and_space_fd(int *tab, char c, int fd)
{
    int nb_space;

    nb_space = MAX(ABS(tab[0]) - 1, 0);
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
    nb_c = MIN(len, tab[2]);
    nb_space = MAX(tab[0] - nb_c, 0);
    return (ft_putspace(nb_space, fd) + ft_putstrn_fd(s, nb_c, fd));
}