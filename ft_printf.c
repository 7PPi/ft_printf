/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:02:23 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/12 17:05:07 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_argu(const char s, va_list args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (s == 'p')
		count += print_p(va_arg(args, void *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (s == 'u')
		count += ft_putnbr_p(va_arg(args, unsigned int));
	else if (s == 'x')
		count += dec_hex(va_arg(args, unsigned int));
	else if (s == 'X')
		count += dec_hex_up(va_arg(args, unsigned int));
	else if (s == '%')
	{
		count++;
		write(1, &s, 1);
	}
	return (count);
}

int	isconv(int s)
{
	if (s == 'c')
		return (1);
	else if (s == 's')
		return (1);
	else if (s == 'p')
		return (1);
	else if (s == 'd' || s == 'i')
		return (1);
	else if (s == 'u')
		return (1);
	else if (s == 'x')
		return (1);
	else if (s == 'X')
		return (1);
	else if (s == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s || (s[0] == '%' && !s[1]))
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && isconv(s[i + 1]))
		{
			count += ft_argu(s[i + 1], args);
			i += 2;
		}
		else if (s[i] != '%')
			count += write(1, &s[i++], 1);
		else
			i++;
	}
	va_end(args);
	return (count);
}
/* #include <stdio.h>
#include <limits.h>
#include <stdint.h>

int	main(void)
{

ft_printf("%p\n",s);
printf("%p\n",s);
} */
