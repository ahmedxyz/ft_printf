/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:06:04 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 03:29:07 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		format_d(int l_pad, char sign, int leading_zeros, char *d, int r_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (l_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		l_pad--;
	}
	if (sign)
	{
		ft_putchar(sign);
		chars_printed++;
	}
	while (leading_zeros > 0)
	{
		ft_putchar('0');
		chars_printed++;
		leading_zeros--;
	}
	ft_putstr(d);
	chars_printed += ft_strlen(d);
	while (r_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		r_pad--;
	}
	return (chars_printed);
}

void	print_d(t_input *input, t_format *format)
{
	intmax_t	num;
	char		*str;
	int			sign;
	int			leading_zeros;
	int			padding;

	num = get_length_signed(input, format);
	str = ft_itoa_base(num, 10);
	sign = 0;
	leading_zeros = 0;
	if (*str == '-')
	{
		str++;
		sign = 1;
	}
	else if (format->flag_plus || format->flag_space)
		sign = 1;
	if ((int)ft_strlen(str) < format->precision)
		leading_zeros = format->precision - ft_strlen(str);
	else if (format->flag_zero == 1)
		leading_zeros = format->width - sign - ft_strlen(str);
	padding = format->width - sign - leading_zeros - ft_strlen(str);
	if (num < 0)
		sign = '-';
	else if (format->flag_plus == 1)
		sign = '+';
	else if (format->flag_space == 1)
		sign = ' ';
	if (format->precision == 0 && num == 0)
	{
		str = "";
		sign = 0;
		padding = format->width;
	}
	if (format->flag_minus == 0)
		input->chars_printed += format_d(padding, sign, leading_zeros, str, 0);
	else
		input->chars_printed += format_d(0, sign, leading_zeros, str, padding);
//	free(str);
}
