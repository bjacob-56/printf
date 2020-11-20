#include "ft_printf.h"

void    ft_zero(void *s, size_t n)
{
    size_t  i;
    int *ptr;

    ptr = (int*)s;
    i = 0;
    while (i < n)
        ptr[i++] = 0;
    ptr[2] = -1;
}

int     ft_strlen(const char *str)
{
    int nb;

    nb = 0;
    while (*(str + nb) != '\0')
    {
        nb = nb + 1;
    }
    return (nb);
}

int     ft_nbrlen_base(long int i, int l_base)
{
    int nb;

    if (i < 0)
        return (1 + ft_nbrlen_base(-i, l_base));
    if (i < l_base)
        return (1);
    return (1 + ft_nbrlen_base(i / l_base, l_base));
}