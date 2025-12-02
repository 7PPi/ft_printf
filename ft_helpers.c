/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:02:13 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/10 12:50:57 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(unsigned int nb)
{
	unsigned long	i;
	int				count;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb > UINT_MAX)
		return (0);
	i = nb;
	count = 0;
	if (i > 9)
		count += ft_putnbr_p(i / 10);
	i = (i % 10) + '0';
	write(1, &i, 1);
	count++;
	return (count);
}

int	dec_hex(unsigned int hex)
{
	char	h1;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (hex >= 16)
		count += dec_hex(hex / 16);
	h1 = base[hex % 16];
	count++;
	write(1, &h1, 1);
	return (count);
}

int	dec_hex_up(unsigned int hex)
{
	char	h1;
	int		count;
	char	*base;

	base = "0123456789ABCDEF";
	count = 0;
	if (hex >= 16)
		count += dec_hex_up(hex / 16);
	h1 = base[hex % 16];
	count++;
	write(1, &h1, 1);
	return (count);
}

int	p_hex(unsigned long hex)
{
	char	h1;
	int		count;
	char	*base;

	base = "0123456789abcdef";
	if (!hex)
		return (0);
	count = 0;
	if (hex >= 16)
		count += p_hex(hex / 16);
	h1 = base[hex % 16];
	count++;
	write(1, &h1, 1);
	return (count);
}

int	print_p(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)ptr;
	count = 2;
	write(1, "0x", 2);
	count += p_hex(addr);
	return (count);
}
