/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:09:01 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/25 18:10:26 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_parsing(t_printf *var, const char *s)
{
	if (s[var->i] == '0')
	{
		var->zero = TRUE;
		var->i++;
	}
	if (s[var->i] == '-')
	{
		var->minus = TRUE;
		var->i++;
	}
	var->f_value = 0;
	while (s[var->i] && (s[var->i] >= '0' && s[var->i] <= '9'))
	{
		var->f_value = 10 * var->f_value + (s[var->i] - '0');
		var->i++;
	}
}

void	precision_parsing(t_printf *var, const char *s)
{
	int neg_flag;

	neg_flag = FALSE;
	var->precision = TRUE;
	var->i++;
	if (s[var->i] == '-')
	{
		var->i++;
		neg_flag = TRUE;
	}
	var->p_value = 0;
	while (s[var->i] && ((s[var->i] >= '0' && s[var->i] <= '9')))
	{
		var->p_value = 10 * var->p_value + (s[var->i] - '0');
		var->i++;
	}
	if (neg_flag == TRUE)
	{
		var->p_value_neg = var->p_value;
		var->p_value = 0;
	}
}

void	width_parsing(t_printf *var, const char *s)
{
	var->width = TRUE;
	var->w_value = 0;
	while (s[var->i] && (s[var->i] >= '0' && s[var->i] <= '9'))
	{
		var->w_value = 10 * var->w_value + (s[var->i] - '0');
		var->i++;
	}
}

void	format_parsing(t_printf *var, const char *s, va_list arg)
{
	if (s[var->i] == '*')
		asterisk_parsing(var, s, arg);
	if ((s[var->i] >= '1' && s[var->i] <= '9') && (s[var->i - 1] == '%'))
		width_parsing(var, s);
	if ((s[var->i] == '0' && s[var->i - 1] == '%') || s[var->i] == '-')
		flags_parsing(var, s);
	if (s[var->i] == '.')
		precision_parsing(var, s);
}
