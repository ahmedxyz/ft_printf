/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 22:59:23 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/09 20:32:30 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_p(va_list arg, t_format *format)
{
	uintmax_t	num;
	char		*prefix;
	char		*str;

	num = (uintmax_t)va_arg(arg, void*);
	prefix = add_sign(format, ft_strnew(0), 0);
	prefix = add_prefix(format, prefix);
	str = ft_uitoa_base(num, 16);
	str = add_leading_zeros(format, str, ft_strlen(prefix));
	str = ft_strjoin_wrapper(prefix, str);
	return (print_with_padding_nstr_wrapper(format, str));
}
