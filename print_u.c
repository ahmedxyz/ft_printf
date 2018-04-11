/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:16:15 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 01:28:09 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_u(int left_pad, int leading_zeros, char *u, int right_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (left_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	while (leading_zeros > 0)
	{
		ft_putchar('0');
		chars_printed++;
		leading_zeros--;
	}
	ft_putstr(u);
	chars_printed += ft_strlen(u);
	while (right_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		right_pad--;
	}
	return (chars_printed);
}

void	print_u(t_input *input, t_format *format)
{
	uintmax_t	num;
	char		*str;
	int			leading_zeros;
	int			padding;

	num = get_length_unsigned(input, format);
	str = ft_uitoa_base(num, 10);
	leading_zeros = 0;
	if (format->precision == 0 && num == 0)
		str = "";
	if ((int)ft_strlen(str) < format->precision)
		leading_zeros = format->precision - ft_strlen(str);
	if (format->flag_zero == 1)
	{
		if (leading_zeros < (int)(format->width - ft_strlen(str)))
			leading_zeros += format->width - ft_strlen(str);
	}
	padding = format->width - leading_zeros - ft_strlen(str);
	if (format->flag_minus == 0)
		input->chars_printed += format_u(padding, leading_zeros, str, 0);
	else
		input->chars_printed += format_u(0, leading_zeros, str, padding);
//	free(str);
}
