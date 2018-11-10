/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:02:07 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/09 20:29:27 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_specifier(va_list arg, t_format *format, char **input)
{
	if (format->conversion == 'd' || format->conversion == 'i')
		return (handle_d(arg, format));
	else if (format->conversion == 'u')
		return (handle_u(arg, format));
	else if (format->conversion == 'o')
		return (handle_o(arg, format));
	else if (format->conversion == 'x' || format->conversion == 'X')
		return (handle_x(arg, format));
	else if (format->conversion == 'p')
		return (handle_p(arg, format));
	else if (format->conversion == 'c' && format->length == 'l')
		return (handle_wc(arg, format));
	else if (format->conversion == 'c')
		return (handle_c(arg, format));
	else if (format->conversion == 's' && format->length == 'l')
		return (handle_ws(arg, format));
	else if (format->conversion == 's')
		return (handle_s(arg, format));
	else if (format->conversion == '%')
		return (handle_percent(format));
	else
		return (handle_invalid(input));
}

int		parse_specifier(va_list arg, char **input)
{
	t_format	*format;
	int			chars_printed;

	format = (t_format*)malloc(sizeof(t_format));
	parse_flags(format, input);
	parse_width(arg, format, input);
	parse_precision(arg, format, input);
	parse_length(format, input);
	parse_conversion(format, input);
	chars_printed = handle_specifier(arg, format, input);
	free(format);
	return (chars_printed);
}

int		parse_input(va_list arg, char **input)
{
	int		chars_printed;

	chars_printed = 0;
	while (**input != '\0')
	{
		if (**input == '%')
		{
			(*input)++;
			chars_printed += parse_specifier(arg, input);
		}
		else
		{
			ft_putchar(**input);
			chars_printed++;
			(*input)++;
		}
	}
	return (chars_printed);
}

int		ft_printf(const char *input, ...)
{
	va_list	arg;
	int		chars_printed;

	va_start(arg, input);
	chars_printed = parse_input(arg, (char**)&input);
	va_end(arg);
	return (chars_printed);
}
