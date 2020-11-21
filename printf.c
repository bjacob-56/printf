#include "printf.h"

void    str_convert(va_list ap, char **str, int *nb_char)
{
    int tab[4];

    ft_zero(tab, 4);
    while (ft_is_digit(**str) || **str == '-' || **str == '.' || **str == '*')
        fill_tab_indic(ap, str, tab);

/*    for (int i = -1 ; i < 4 ; ++i)
        printf("i = %d, tab[i] = %d\n", i, tab[i]); */
//    printf("\np1\n"); ///////////////////////////////////////////////////////////////////////////
    if (**str == 'c')
        str_char(ap, nb_char, tab);
    if (**str == 's')
        str_string(ap, nb_char, tab);
    if (**str == 'p')
        str_add_hexa(ap, nb_char, tab);
    if (**str == 'i' || **str == 'd')
        str_int(ap, nb_char, tab);
    if (**str == 'u')
        str_decimal(ap, nb_char, tab);
    if (**str == 'x' || **str == 'X')
        str_unsigned_hexa(ap, str, nb_char, tab);
    if (**str == '%')
        str_percent(nb_char);

    // erreur a retourner ici ?
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