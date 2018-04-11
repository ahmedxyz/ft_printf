/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:58:52 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 01:28:44 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_x(int l_pad, char p, int leading_zeros, char *x, int r_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (l_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		l_pad--;
	}
	if (p > 2)
	{
		ft_putchar('0');
		p == 3 ? ft_putchar('x') : ft_putchar('X');
		chars_printed += 2;
	}
	while (leading_zeros > 0)
	{
		ft_putchar('0');
		chars_printed++;
		leading_zeros--;
	}
	while (*x)
	{
		p % 2 == 1 ? ft_putchar(*x) : ft_putchar(ft_toupper(*x));
		chars_printed++;
		x++;
	}
	while (r_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		r_pad--;
	}
	return (chars_printed);
}

void	print_x(t_input *input, t_format *format)
{
	uintmax_t	num;
	char		*str;
	char		p;
	int			leading_zeros;
	int			padding;

	num = get_length_unsigned(input, format);
	str = ft_uitoa_base(num, 16);
	p = 0;
	leading_zeros = 0;
	if (format->precision == 0 && num == 0)
		str = "";
	if (format->flag_hash == 1 && num != 0)
		p = 2;
	if ((int)ft_strlen(str) < format->precision)
		leading_zeros = format->precision - ft_strlen(str);
	if (format->flag_zero == 1)
	{
		if (leading_zeros < (int)(format->width - p - ft_strlen(str)))
			leading_zeros += format->width - p - ft_strlen(str);
	}
	padding = format->width - p - leading_zeros - ft_strlen(str);
	if (format->conversion == 'x')
		p = 1;
	if (format->conversion == 'X')
		p = 2;
	if (format->flag_hash == 1 && num != 0)
		p += 2;
	if (format->flag_minus == 0)
		input->chars_printed += format_x(padding, p, leading_zeros, str, 0);
	else
		input->chars_printed += format_x(0, p, leading_zeros, str, padding);
//	free(str);
}
