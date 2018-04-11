/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:59:23 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 01:28:56 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_p(int l_pad, char sign, int leading_zeros, char *p, int r_pad)
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
	ft_putstr("0x");
	chars_printed += 2;
	while (leading_zeros > 0)
	{
		ft_putchar('0');
		chars_printed++;
		leading_zeros--;
	}
	ft_putstr(p);
	chars_printed += ft_strlen(p);
	while (r_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		r_pad--;
	}
	return (chars_printed);
}

void	print_p(t_input *input, t_format *format)
{
	uintmax_t	num;
	char		*str;
	int			sign;
	int			leading_zeros;
	int			padding;

	num = (uintmax_t)va_arg(input->arg, void*);
	str = ft_uitoa_base(num, 16);
	sign = 0;
	leading_zeros = 0;
	if (format->flag_plus == 1 || format->flag_space == 1)
		sign = 1;
	if ((int)ft_strlen(str) < format->precision)
		leading_zeros = format->precision - ft_strlen(str);
	else if (format->flag_zero == 1)
		leading_zeros += format->width - sign - 2 - ft_strlen(str);
	padding = format->width - sign - 2 - leading_zeros - ft_strlen(str);
	if (format->flag_plus == 1)
		sign = '+';
	if (format->flag_space == 1)
		sign = ' ';
	if (format->precision == 0 && num == 0)
	{
		str = "";
		padding = format->width - 2;
		sign = 0;
		leading_zeros = 0;
	}
	if (format->flag_minus == 0)
		input->chars_printed += format_p(padding, sign, leading_zeros, str, 0);
	else
		input->chars_printed += format_p(0, sign, leading_zeros, str, padding);
//	free(str);
}
