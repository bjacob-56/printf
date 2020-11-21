#include "printf.h"

int main()
{
    int nb_char;
    char    *str;
    int     i;
    char    c;
    char    *s;
    unsigned int    u;
    char *flag;

    nb_char = 0;

    flag = "05";
    i = 1234567;
 //   i = 42;
    u = 21474836;
    c = 'f';
    s = "abcd";
    str = "int = %i ou %d\nchar = %c\nstr = %s\nadd = %p\ndec = %u\nhexa = %x\nHEXA = %X\n%% = %%\n";
    str = "int = \
%-18.10i\n ou = \
%-18.10d\ncha = \
%-18.10c\nstr = \
%-18.10s\nadd = \
%-18.10p\ndec = \
%-18.10u\nhex = \
%-18.10x\nHEX = \
%-18.10X\n\n";

//str = "s = '%018s'\n";

//printf("p1\n"); ///////////////////////////////////////////////////////////////////////////

    printf("Ma fonction : \n\n");
    nb_char = ft_printf(str, i, i, c, s, s, u, u, u);
//    nb_char = ft_printf(str, s);
    printf("n = %d\n", nb_char);

    printf("\n ---------- \n\n");

    printf("Real printf : \n\n");
    nb_char = printf(str, i, i, c, s, s, u, u, u);
//    nb_char = printf(str, s);
    printf("n = %d\n", nb_char);
}