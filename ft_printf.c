/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:02:07 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 03:29:09 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifier(t_input *input, t_format *format)
{
	if (format->conversion == 0)
		print_invalid(input, format);
	else if (format->conversion == '%')
		print_percent(input, format);
	else if (format->conversion == 'd' || format->conversion == 'i' ||
			format->conversion == 'D')
		print_d(input, format);
	else if (format->conversion == 'u' || format->conversion == 'U')
		print_u(input, format);
	else if (format->conversion == 'o' || format->conversion == 'O')
		print_o(input, format);
	else if (format->conversion == 'x' || format->conversion == 'X')
		print_x(input, format);
	else if (format->conversion == 'p')
		print_p(input, format);
	else if (format->conversion == 'c' || format->conversion == 'C')
		print_c(input, format);
	else if (format->conversion == 's' || format->conversion == 'S')
		print_s(input, format);
}

void	parse_specifier(t_input *input)
{
	t_format	*format;

	format = (t_format*)malloc(sizeof(t_format));
	check_flags(input, format);
	check_width(input, format);
	check_precision(input, format);
	check_length(input, format);
	check_conversion(input, format);
	print_specifier(input, format);
	free(format);
}

void	parse_input(t_input *input)
{
	while ((input->string)[input->index] != '\0')
	{
		if ((input->string)[input->index] == '%')
		{
			input->index++;
			if ((input->string)[input->index] != '\0')
				parse_specifier(input);
		}
		else
		{
			ft_putchar((input->string)[input->index]);
			input->chars_printed++;
			input->index++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_input		*input;
	int			ret;

	input = (t_input*)malloc(sizeof(t_input));
	input->string = (char*)format;
	input->index = 0;
	input->chars_printed = 0;
	va_start(input->arg, format);
	parse_input(input);
	va_end(input->arg);
	ret = input->chars_printed;
	free(input);
	return (ret);
}
