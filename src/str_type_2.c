/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_type_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:57:24 by bjacob            #+#    #+#             */
/*   Updated: 2020/12/01 07:02:39 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	fill_tab_indic(va_list ap, char **str, int *tab)
{
	int	etoile;

	if (ft_is_digit(**str) && !tab[1])
		ft_add_digit_to_tab(ap, str, tab);
	if (**str == '-')
	{
		tab[1] = ft_abs(ft_atoi_simplify(ap, str));
		tab[0] = 0;
	}
	if (**str == '.')
		tab[2] = ft_atoi_simplify(ap, str);
	if (**str == '*')
	{
		etoile = ft_atoi_simplify(ap, str);
		if (etoile < 0)
			tab[1] = -etoile;
		else
			tab[4] = etoile;
	}
	if (tab[0] < 0)
	{
		tab[1] = tab[0] * (-1);
		tab[0] = 0;
	}
}

void	str_add_hexa(va_list ap, int *nb_char, int *tab)
{
	void			*p;
	unsigned long	add;
	int				len;
	int				nb;

	nb = 0;
	p = va_arg(ap, void*);
	add = (unsigned long)(p);
	len = ft_nbrlen_base_add(add, 16);
	if (tab[0] < 0)
	{
		tab[0] *= -1;
		nb += ft_putspace(1, STDOUT);
	}
	nb += ft_put_zero_and_space_add(tab, len, STDOUT);
	nb += print_base_fd(add, tab, STDOUT, "0123456789abcdef");
	nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
	*nb_char += nb;
}

void	str_unsigned_hexa(va_list ap, char **str, int *nb_char, int *tab)
{
	unsigned int	x;
	int				len;
	int				nb;

	nb = 0;
	x = va_arg(ap, unsigned int);
	len = ft_nbrlen_base(x, 16);
	nb += ft_put_zero_and_space(x, tab, len, STDOUT);
	if (**str == 'x')
		nb += print_base_fd(x, tab, STDOUT, "0123456789abcdef");
	if (**str == 'X')
		nb += print_base_fd(x, tab, STDOUT, "0123456789ABCDEF");
	nb += ft_putspace(ft_max(tab[1] - nb, 0), STDOUT);
	*nb_char += nb;
}

int		ft_putchar_and_space_fd(int *tab, char c, int fd)
{
	int	nb_space;
	int	nb_zero;
	int nb;

	nb_zero = ft_max(tab[0] - 1, 0);
	nb_space = ft_max(tab[4] - 1, 0);
	nb = 0;
	nb += ft_putzero(nb_zero, fd);
	nb += ft_putspace(nb_space, fd);
	nb += ft_putchar_fd(c, fd);
	return (nb);
}

int		ft_putstr_and_space_fd(int *tab, char *s, int fd)
{
	int	len;
	int	nb_space;
	int	nb_c;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (tab[2] < 0)
		tab[2] = len;
	nb_c = ft_min(len, tab[2]);
	nb_space = ft_max(ft_max(tab[0], tab[4]) - nb_c, 0);
	return (ft_putspace(nb_space, fd) + ft_putstrn_fd(s, nb_c, fd));
}
