#include "ft_printf.h"

int ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
    return (1);
}

int ft_putstrn_fd(char *s, int n, int fd)
{
    int s_len;

    if (!s)
        return (0);
    s_len = MIN(ft_strlen(s), n);
    write(fd, s, s_len);
    return (s_len);
}

int ft_putnbr_fd(long long int n, int fd)
{
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        return (1 + ft_putnbr_fd(-n, fd));
    }
    if (n < 10)
        return (ft_putchar_fd(n + '0', fd));
    else
        return (ft_putnbr_fd(n / 10, fd) + ft_putnbr_fd(n % 10, fd));
}

int print_base_fd(long int add, int fd, char *base)
{
    int l_base;
    int nb;

    l_base = ft_strlen(base);
    nb = 0;
    if (add < l_base)
        return (ft_putchar_fd(base[add], fd));
    nb += print_base_fd(add / l_base, fd, base);
    nb += print_base_fd(add % l_base, fd, base);
    return (nb);
}