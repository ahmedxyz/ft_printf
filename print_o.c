/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:57:54 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 01:28:29 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_o(int left_pad, int p, int leading_zeros, char *o, int right_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (left_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	if (p == 1)
	{
		ft_putchar('0');
		chars_printed++;
	}
	while (leading_zeros > 0)
	{
		ft_putchar('0');
		chars_printed++;
		leading_zeros--;
	}
	ft_putstr(o);
	chars_printed += ft_strlen(o);
	while (right_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		right_pad--;
	}
	return (chars_printed);
}

void	print_o(t_input *input, t_format *format)
{
	uintmax_t	num;
	char		*str;
	int			p;
	int			leading_zeros;
	int			padding;

	num = get_length_unsigned(input, format);
	str = ft_uitoa_base(num, 8);
	p = 0;
	leading_zeros = 0;
	if (format->precision == 0 && num == 0)
		str = "";
	if (format->flag_hash == 1 && (num != 0 || format->precision == 0))
		p = 1;
	if ((int)ft_strlen(str) < format->precision)
		leading_zeros = format->precision - ft_strlen(str);
	else if (format->flag_zero == 1)
		leading_zeros += format->width - p - ft_strlen(str);
	padding = format->width - p - leading_zeros - ft_strlen(str);
	if (format->flag_minus == 0)
		input->chars_printed += format_o(padding, p, leading_zeros, str, 0);
	else
		input->chars_printed += format_o(0, p, leading_zeros, str, padding);
//	free(str);
}
