/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 00:17:01 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 02:09:59 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	get_length_signed(t_input *input, t_format *format)
{
	if (format->length == 'H')
		return ((char)va_arg(input->arg, int));
	else if (format->length == 'h')
		return ((short)va_arg(input->arg, int));
	else if (format->length == 'l')
		return ((long)va_arg(input->arg, long));
	else if (format->length == 'L')
		return ((long long)va_arg(input->arg, long));
	else if (format->length == 'j')
		return ((intmax_t)va_arg(input->arg, intmax_t));
	else if (format->length == 'z')
		return ((ssize_t)va_arg(input->arg, ssize_t));
	else
		return ((int)va_arg(input->arg, int));
}

intmax_t	get_length_unsigned(t_input *input, t_format *format)
{
	if (format->length == 'H')
		return ((unsigned char)va_arg(input->arg, unsigned int));
	else if (format->length == 'h')
		return ((unsigned short)va_arg(input->arg, unsigned int));
	else if (format->length == 'l')
		return ((unsigned long)va_arg(input->arg, unsigned long));
	else if (format->length == 'L')
		return ((unsigned long long)va_arg(input->arg, unsigned long));
	else if (format->length == 'j')
		return ((uintmax_t)va_arg(input->arg, uintmax_t));
	else if (format->length == 'z')
		return ((size_t)va_arg(input->arg, size_t));
	else
		return ((unsigned int)va_arg(input->arg, unsigned int));
}
