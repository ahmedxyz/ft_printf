/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 01:37:02 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 02:14:25 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_flags(t_input *input, t_format *format)
{
	format->flag_hash = 0;
	format->flag_zero = 0;
	format->flag_minus = 0;
	format->flag_plus = 0;
	format->flag_space = 0;
	while (ft_strchr("#0-+ ", (input->string)[input->index]) != NULL)
	{
		if ((input->string)[input->index] == '#')
			format->flag_hash = 1;
		if ((input->string)[input->index] == '0')
			format->flag_zero = 1;
		if ((input->string)[input->index] == '-')
			format->flag_minus = 1;
		if ((input->string)[input->index] == '+')
			format->flag_plus = 1;
		if ((input->string)[input->index] == ' ')
			format->flag_space = 1;
		input->index++;
	}
	if (format->flag_minus == 1 && format->flag_zero == 1)
		format->flag_zero = 0;
	if (format->flag_plus == 1 && format->flag_space == 1)
		format->flag_space = 0;
}

void	check_width(t_input *input, t_format *format)
{
	format->width = 0;
	while (ft_isdigit((input->string)[input->index]) != 0)
	{
		format->width *= 10;
		format->width += (input->string)[input->index] - '0';
		input->index++;
	}
}

void	check_precision(t_input *input, t_format *format)
{
	format->precision = -1;
	if ((input->string)[input->index] == '.')
	{
		format->precision = 0;
		input->index++;
		while (ft_isdigit((input->string)[input->index]) != 0)
		{
			format->precision *= 10;
			format->precision += (input->string)[input->index] - '0';
			input->index++;
		}
	}
}

void	check_length(t_input *input, t_format *format)
{
	format->length = 0;
	if ((input->string)[input->index] == 'h' &&
			(input->string)[input->index + 1] == 'h')
	{
		format->length = 'H';
		input->index += 2;
	}
	else if ((input->string)[input->index] == 'l' &&
			(input->string)[input->index + 1] == 'l')
	{
		format->length = 'L';
		input->index += 2;
	}
	else if (ft_strchr("hljz", (input->string)[input->index]))
	{
		format->length = (input->string)[input->index];
		input->index++;
	}
}

void		check_conversion(t_input *input, t_format *format)
{
	format->conversion = 0;
	if (ft_strchr("sSpdDioOuUxXcC%", (input->string)[input->index]) != NULL)
	{
		format->conversion = (input->string)[input->index];
		input->index++;
	}
	if (ft_strchr("SDOUC", format->conversion) != NULL)
		format->length = 'l';
}
