/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:35:20 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/09 20:33:40 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_s(va_list arg, t_format *format)
{
	char	*str;
	int		precision;

	if (!(str = (char*)va_arg(arg, char*)))
		str = "(null)";
	precision = format->precision;
	if (precision < 0 || (int)ft_strlen(str) < precision)
		precision = ft_strlen(str);
	return (print_with_padding_nstr(format, str, precision));
}
