#include "ft_printf.h"

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
%03.13i\n ou = \
%03.13d\ncha = \
%03.13c\nstr = \
%03.13s\nadd = \
%03.13p\ndec = \
%03.13u\nhex = \
%03.13x\nHEX = \
%03.13X\n";

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