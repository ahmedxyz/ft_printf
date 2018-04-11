/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:50:26 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/09 01:34:21 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_percent(int left_pad, int right_pad)
{
	int		chars_printed;

	chars_printed = 0;
	while (left_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		left_pad--;
	}
	ft_putchar('%');
	chars_printed++;
	while (right_pad > 0)
	{
		ft_putchar(' ');
		chars_printed++;
		right_pad--;
	}
	return (chars_printed);
}

void	print_percent(t_input *input, t_format *format)
{
	int	padding;

	padding = format->width - 1;
	if (format->flag_minus == 0)
		input->chars_printed += format_percent(padding, 0);
	else
		input->chars_printed += format_percent(0, padding);
}
