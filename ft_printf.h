/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:19:24 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/26 00:40:52 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0

typedef struct		s_printf
{
	const char		*conv_set;
	char			*hexa_set;
	int				asterisk;
	int				zero;
	int				minus;
	int				f_value;
	int				precision;
	int				p_value;
	int				p_value_neg;
	int				print_precision;
	int				width;
	int				w_value;
	int				i;
	int				len;
	int				nb_neg;
	int				min_flag;
	int				conv;
	int				nb_di;
	unsigned int	nb_u;
	unsigned long	nb_p;
	int				nb_len;
	int				s_len;
}					t_printf;

int					ft_printf(const char *s, ...);
int					precision_c(t_printf *var, char c);
void				width_c(t_printf *var, char c);
void				zero_c(t_printf *var, char c);
void				minus_c(t_printf *var, char c);
void				arg_c(t_printf *var, va_list arg);
int					precision_di(t_printf *var);
void				width_di(t_printf *var);
void				zero_di(t_printf *var);
void				minus_di(t_printf *var);
void				no_flags_di(t_printf *var);
void				arg_di(t_printf *var, va_list arg);
int					precision_p(t_printf *var);
void				width_p(t_printf *var);
void				zero_p(t_printf *var);
void				minus_p(t_printf *var);
void				arg_p(t_printf *var, va_list arg);
void				precision_s(t_printf *var, char **str);
void				width_s(t_printf *var, char *str);
void				zero_s(t_printf *var, char *str);
void				minus_s(t_printf *var, char *str);
void				arg_s(t_printf *var, va_list arg);
int					precision_u(t_printf *var);
void				width_u(t_printf *var);
void				zero_u(t_printf *var);
void				minus_u(t_printf *var);
void				arg_u(t_printf *var, va_list arg);
int					precision_x(t_printf *var);
void				width_x(t_printf *var);
void				zero_x(t_printf *var);
void				minus_x(t_printf *var);
void				arg_x(t_printf *var, va_list arg);
void				flags_parsing(t_printf *var, const char *s);
void				precision_parsing(t_printf *var, const char *s);
void				width_parsing(t_printf *var, const char *s);
void				format_parsing(t_printf *var, const char *s, va_list arg);
void				asterisk_width(t_printf *var, va_list arg);
void				asterisk_precision(t_printf *var, va_list arg);
void				asterisk_flags(t_printf *var, va_list arg);
void				asterisk_parsing(t_printf *var, const char *s, va_list arg);
void				ft_putchar_tracked(char c, t_printf *var);
void				ft_putstr_tracked(char *s, t_printf *var);
void				print_p_value(t_printf *var);
void				print_w_value(t_printf *var);
void				print_f_value(t_printf *var, char c);
void				print_p_s_value(t_printf *var, char **str);
void				ft_putnbr_tracked(int nb, t_printf *var);
void				ft_putnbr_base_tracked(unsigned long nb, char *base,
																t_printf *var);
int					ft_intlen(int nb);
int					ft_ulllen_base(unsigned long long nb, int base_size);
void				struct_init(t_printf *var);
void				struct_clean(t_printf *var);
int					find_index(char c, const char *set);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);

#endif
