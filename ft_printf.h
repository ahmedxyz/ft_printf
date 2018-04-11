/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:01:57 by hahmed            #+#    #+#             */
/*   Updated: 2018/04/11 03:29:13 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

/* DELETE ME */
# include <stdio.h>
/* DELETE ME */

typedef struct		s_input
{
	va_list			arg;
	char			*string;
	int				index;
	int				chars_printed;
}					t_input;

typedef struct		s_format
{
	int				flag_hash;
	int				flag_zero;
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
	int				width;
	int				precision;
	char			length;
	char			conversion;
}					t_format;

/* ft_printf.c */

void	print_specifier(t_input *input, t_format *format);
void	parse_specifier(t_input *input);
void	parse_input(t_input *input);
int		ft_printf(const char *format, ...);

/* ft_check.c */

void	check_flags(t_input *input, t_format *format);
void	check_width(t_input *input, t_format *format);
void	check_precision(t_input *input, t_format *format);
void	check_length(t_input *input, t_format *format);
void	check_conversion(t_input *input, t_format *format);

/* length */

intmax_t	get_length_signed(t_input *input, t_format *format);
intmax_t	get_length_unsigned(t_input *input, t_format *format);

/* print functions */

void	print_d(t_input *input, t_format *format);
void	print_u(t_input *input, t_format *format);
void	print_o(t_input *input, t_format *format);
void	print_x(t_input *input, t_format *format);
void	print_p(t_input *input, t_format *format);
void	print_c(t_input *input, t_format *format);
void	print_s(t_input *input, t_format *format);
void	print_percent(t_input *input, t_format *format);
void	print_invalid(t_input *input, t_format *format);

#endif
