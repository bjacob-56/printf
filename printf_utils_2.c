#include "ft_printf.h"

int	ft_atoi_simplify(va_list ap, char **str)
{
	int     res;
    int     signe;

	res = 0;
    signe = 1;
    if (**str == '0' || **str == '-' || **str == '.')
        (*str)++;
    while (**str == ' ')
    {
		(*str)++;
        signe = -1;
    }
    if (**str == '*')
    {
        res = va_arg(ap, int);
        (*str)++;
        return (res * signe);
    }
	while (**str >= '0' && **str <= '9')
		res = 10 * res + (*(*str)++ - '0');
	return (res * signe);
}

int ft_putspace(int nb, int fd)
{
    char    c;

    c = ' ';
    if (nb == 0)
        return (0);
    write (fd, &c, 1);
    return (1 + ft_putspace(nb - 1, fd));
}

int ft_putzero(int nb, int fd)
{
    char    c;

    c = '0';
    if (nb == 0)
        return (0);
    write (fd, &c, 1);
    return (1 + ft_putzero(nb - 1, fd));
}

int ft_put_zero_and_space(int *tab, int len, int fd)
{
    int nb_zero;
    int nb_space;

    nb_space = 0;
    nb_zero = MAX(tab[0] - len, 0);
    if (tab[2] > 0)
    {
        nb_zero = MAX(tab[2] - len, 0);
        if (len < tab[2])
            nb_space = MAX(tab[0] - tab[2], 0);
        else
            nb_space = MAX(MIN(tab[0] - len, tab[0] - len), 0);
    }
    return (ft_putspace(nb_space, fd) + ft_putzero(nb_zero, fd));
}

int ft_put_zero_and_space_add(int *tab, int len, int fd)
{
    int nb_zero;
    int nb_space;

    nb_space = 0;
    nb_zero = MAX(tab[0] - len - 2, 0);
    if (tab[2] >= 0)
    {
        nb_zero = MAX(tab[2] - len, 0);
        if (tab[0] >  tab[2])
            nb_space = MAX(tab[0] - (nb_zero + len + 2),0); 
        else
            nb_space = MAX(tab[2] - (nb_zero + len + 2),0);
    }
    ft_putspace(nb_space, fd);
    ft_putstrn_fd("0x", 2, fd);
    ft_putzero(nb_zero, fd);
    return (nb_space + 2 + nb_zero);
}