/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:35:20 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 01:29:09 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_ws(int left_pad, wchar_t *ws, int precision, int right_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (left_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	while (precision > 0)
	{
		ft_putwchar(*ws);
		chars_printed += ft_wcharlen(*ws);
		precision -= ft_wcharlen(*ws);
		ws++;
	}
	while (right_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	return (chars_printed);
}

int		format_s(int left_pad, char *s, int precision, int right_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (left_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	while (precision > 0)
	{
		ft_putchar(*s);
		chars_printed++;
		s++;
		precision--;
	}
	while (right_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		right_pad--;
	}
	return (chars_printed);
}

void	print_s(t_input *input, t_format *format)
{
	void		*str;
	int			precision;
	int			padding;

	if (format->conversion == 'S' || format->length == 'l')
	{
		str = (wchar_t*)va_arg(input->arg, wchar_t*);
		if (!str)
			str = L"(null)";
		if (-1 < format->precision && format->precision < (int)ft_wstrlen(str))
			precision = format->precision;
		else
			precision = ft_wstrlen(str);
		padding = format->width - precision;
		if (format->flag_minus == 0)
			input->chars_printed += format_ws(padding, str, precision, 0);
		else
			input->chars_printed += format_ws(0, str, precision, padding);
	}
	else if (format->conversion == 's')
	{
		str = (char*)va_arg(input->arg, char*);
		if (!str)
			str = "(null)";
		if (-1 < format->precision && format->precision < (int)ft_strlen(str))
			precision = format->precision;
		else
			precision = ft_strlen(str);
		padding = format->width - precision;
		if (format->flag_minus == 0)
			input->chars_printed += format_s(padding, str, precision, 0);
		else
			input->chars_printed += format_s(0, str, precision, padding);
	}
}
