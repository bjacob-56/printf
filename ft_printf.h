#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include <stdio.h> // A RETIRER

# define MAX(x, y) (x >= y ? x : y)
# define MIN(x, y) (x <= y ? x : y)
# define ABS(x) (x >= 0 ? x : -x)


void    str_convert(va_list ap, char **str, int *nb_char);
void    str_process(va_list ap, char **str, int *nb_char);
int     ft_printf(const char *format, ...);

void    str_int(va_list ap, int *nb_char, int *tab);
void    str_char(va_list ap, int *nb_char, int *tab);
void    str_string(va_list ap, int *nb_char, int *tab);
void    str_percent(int *nb_char);
void    str_decimal(va_list ap, int *nb_char, int *tab);

void    fill_tab_indic(va_list ap, char **str, int *tab);
void    str_add_hexa(va_list ap, int *nb_char, int *tab);
void    str_unsigned_hexa(va_list ap, char **str, int *nb_char, int *tab);
int     ft_putchar_and_space_fd(int *tab, char c, int fd);
int     ft_putstr_and_space_fd(int *tab, char *s, int fd);

int     ft_putchar_fd(char c, int fd);
int     ft_putstrn_fd(char *s, int n, int fd);
int     ft_putnbr_fd(long long int n, int fd);
int     print_base_fd(long int add, int fd, char *base);

int     ft_atoi_simplify(va_list ap, char **str);
int     ft_putspace(int nb, int fd);
int     ft_putzero(int nb, int fd);
int     ft_put_zero_and_space(int *tab, int l_i, int fd);
int     ft_put_zero_and_space_add(int *tab, int len, int fd);

void    ft_zero(void *s, size_t n);
int     ft_strlen(const char *str);
int     ft_nbrlen_base(long int i, int l_base);

#ifndef STDOUT
# define STDOUT 1
#endif

#endif