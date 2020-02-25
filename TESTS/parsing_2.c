/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:00:55 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/24 18:29:36 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	asterisk_width(t_printf *var, va_list arg)
{
	var->w_value = va_arg(arg, int);
	var->width = TRUE;
	if (var->w_value < 0)
	{
		var->minus = TRUE;
		var->f_value = -var->w_value;
		var->w_value = FALSE;
		var->width = FALSE;
	}
}

void	asterisk_precision(t_printf *var, va_list arg)
{
	var->precision = TRUE;
	var->p_value = va_arg(arg, int);
	if (var->p_value < 0)
		var->precision = FALSE;
}

void	asterisk_flags(t_printf *var, va_list arg)
{
	var->f_value = va_arg(arg, int);
	if (var->f_value < 0)
	{
		var->minus = TRUE;
		var->f_value = -var->f_value;
	}
}

void	asterisk_parsing(t_printf *var, const char *s, va_list arg)
{
	if (s[var->i - 1] == '%')
		asterisk_width(var, arg);
	if (s[var->i - 1] == '.')
		asterisk_precision(var, arg);
	if (s[var->i - 1] == '0' || s[var->i - 1] == '-')
		asterisk_flags(var, arg);
	var->i++;
}
