/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:27:38 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/09 20:30:05 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_c(va_list arg, t_format *format)
{
	char	c;

	c = va_arg(arg, int);
	return (print_with_padding_char(format, c));
}
