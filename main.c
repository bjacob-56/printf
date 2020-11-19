#include "ft_printf.h"

int main()
{
    int nb_char;
    char    *str;
    int     i;
    char    c;
    char    *s;
    unsigned int    u;

    i = 42;
    u = -21474836;
    c = 'f';
    s = "abcd";
    str = "int = %i ou %d\nchar = %c\nstr = %s\nadd = %p\ndec = %u\nhexa = %x\nHEXA = %X\n";

    printf("Ma fonction : \n\n");
    nb_char = ft_printf(str, i, i, c, s, s, u, u, u);
    printf("n = %d\n", nb_char);

    printf("\n ---------- \n\n");

    printf("Real printf : \n\n");
    nb_char = printf(str, i, i, c, s, s, u, u, u);
    printf("n = %d\n", nb_char);
}