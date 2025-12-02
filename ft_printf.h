/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etchipoq <etchipoq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:02:27 by etchipoq          #+#    #+#             */
/*   Updated: 2025/11/10 12:50:41 by etchipoq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_printstr(const char *str);
int	ft_putchar(int c);
int	ft_putnbr(int nb);
int	dec_hex(unsigned int hex);
int	dec_hex_up(unsigned int hex);
int	print_p(void *ptr);
int	ft_putnbr_p(unsigned int nb);

#endif
