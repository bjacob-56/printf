#include "ft_printf.h"

void    str_hexa(va_list ap, int *nb_char)
{
    void        *p;
    long int    add;

    p = va_arg(ap, void*);
    add = (long int)(p);
    *nb_char += ft_putstr_fd("0x", STDOUT);
    *nb_char += print_base_fd(add, STDOUT, "0123456789abcdef");

}

void    str_unsigned_hexa(va_list ap, char **str, int *nb_char)
{
    unsigned int    x;

    x = va_arg(ap, unsigned int);
    if (**str == 'x')
        *nb_char += print_base_fd(x, STDOUT, "0123456789abcdef");
    if (**str == 'X')
        *nb_char += print_base_fd(x, STDOUT, "0123456789ABCDEF");
}