/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:27:38 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/09 01:42:57 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_wc(int left_pad, wchar_t wc, int right_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (left_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	ft_putwchar(wc);
	chars_printed += ft_wcharlen(wc);
	while (right_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		right_pad--;
	}
	return (chars_printed);
}

int		format_c(int left_pad, char c, int right_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (left_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	ft_putchar(c);
	chars_printed++;
	while (right_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		right_pad--;
	}
	return (chars_printed);
}

void	print_c(t_input *input, t_format *format)
{
	intmax_t	c;
	int			padding;

	padding = format->width - 1;
	if (format->conversion == 'C' || format->length == 'l')
	{
		c = va_arg(input->arg, wint_t);
		if (format->flag_minus == 0)
			input->chars_printed += format_wc(padding, c, 0);
		else
			input->chars_printed += format_wc(0, c, padding);
	}
	else if (format->conversion == 'c')
	{
		c = va_arg(input->arg, int);
		if (format->flag_minus == 0)
			input->chars_printed += format_c(padding, c, 0);
		else
			input->chars_printed += format_c(0, c, padding);
	}
}
