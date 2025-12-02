/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:10:58 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/10 12:50:53 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	long	i;
	int		count;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	i = nb;
	count = 0;
	if (i < 0)
	{
		i *= -1;
		write(1, "-", 1);
		count++;
	}
	if (i > 9)
		count += ft_putnbr(i / 10);
	i = (i % 10) + '0';
	count++;
	write(1, &i, 1);
	return (count);
}

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(int c)
{
	unsigned char	a;

	a = c;
	write(1, &a, 1);
	return (1);
}
