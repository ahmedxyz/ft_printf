/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:01:57 by hahmed            #+#    #+#             */
/*   Updated: 2018/11/09 23:06:21 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/inc/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

typedef struct	s_format
{
	int			flag_hash;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			width;
	int			precision;
	char		length;
	char		conversion;
}				t_format;

/*
** ft_printf.c
*/

int				handle_specifier(va_list arg, t_format *format, char **input);
int				parse_specifier(va_list arg, char **input);
int				parse_input(va_list arg, char **input);
int				ft_printf(const char *input, ...);

/*
** parse.c
*/

void			parse_flags(t_format *format, char **input);
void			parse_width(va_list arg, t_format *format, char **input);
void			parse_precision(va_list arg, t_format *format, char **input);
void			parse_length(t_format *format, char **input);
void			parse_conversion(t_format *format, char **input);

/*
** cast_length.c
*/

intmax_t		cast_length_signed(va_list arg, t_format *format);
intmax_t		cast_length_unsigned(va_list arg, t_format *format);

/*
** string.c
*/

char			*append(char *s, char c);
char			*prepend(char *s, char c);
char			*trim_first(char *s);
char			*ft_strtoupper(char *s);
char			*ft_strjoin_wrapper(char *s1, char *s2);

/*
** format.c
*/

char			*add_sign(t_format *format, char *prefix, int is_negative);
char			*add_prefix(t_format *format, char *prefix);
char			*add_leading_zeros(t_format *format, char *str, int prefix_len);

/*
** conversion functions
*/

int				handle_d(va_list arg, t_format *format);
int				handle_u(va_list arg, t_format *format);
int				handle_o(va_list arg, t_format *format);
int				handle_x(va_list arg, t_format *format);
int				handle_p(va_list arg, t_format *format);
int				handle_c(va_list arg, t_format *format);
int				handle_wc(va_list arg, t_format *format);
int				handle_s(va_list arg, t_format *format);
int				handle_ws(va_list arg, t_format *format);
int				handle_percent(t_format *format);
int				handle_invalid(char **input);

/*
** print_with_padding.c
*/

int				print_with_padding_nstr(t_format *format, char *str, int n);
int				print_with_padding_nstr_wrapper(t_format *format, char *str);
int				print_with_padding_nwstr(t_format *format, wchar_t *str, int n);
int				print_with_padding_char(t_format *format, char c);
int				print_with_padding_wchar(t_format *format, wchar_t c);

#endif
