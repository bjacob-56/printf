#ifndef PRINTF2_H
# define PRINTF2_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#include <stdio.h> // A RETIRER

void    str_convert(va_list ap, char **str, int *nb_char);
void    str_process(va_list ap, char **str, int *nb_char);
int     ft_printf(const char *format, ...);

void    str_int(va_list ap, int *nb_char);
void    str_char(va_list ap, int *nb_char);
void    str_string(va_list ap, int *nb_char);
void    str_percent(int *nb_char);
void    str_decimal(va_list ap, int *nb_char);

void    str_hexa(va_list ap, int *nb_char);
void    str_unsigned_hexa(va_list ap, char **str, int *nb_char);

int     ft_putchar_fd(char c, int fd);
int     ft_strlen(const char *str);
int     ft_putstr_fd(char *s, int fd);
int     ft_putnbr_fd(long long int n, int fd);
int     print_base_fd(long int add, int fd, char *base);

#ifndef STDOUT
# define STDOUT 1
#endif

#endif