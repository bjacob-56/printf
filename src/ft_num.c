/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacob <bjacob@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:28:09 by bjacob            #+#    #+#             */
/*   Updated: 2020/11/26 17:28:13 by bjacob           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_max(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

int	ft_min(int x, int y)
{
	if (x <= y)
		return (x);
	return (y);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_is_digit(int i)
{
	return (i >= '0' && i <= '9');
}
