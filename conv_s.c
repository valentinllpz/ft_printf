/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 17:43:09 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/26 00:39:06 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	precision_s(t_printf *var, char **str)
{
	(*str)[var->p_value] = '\0';
	var->f_value = var->f_value - var->p_value;
	var->w_value = var->w_value - var->p_value;
	var->print_precision = TRUE;
}

void	width_s(t_printf *var, char *str)
{
	if (var->print_precision == FALSE)
		var->w_value -= var->s_len;
	print_w_value(var);
	ft_putstr_tracked(str, var);
}

void	zero_s(t_printf *var, char *str)
{
	if (var->print_precision == FALSE)
		var->f_value -= var->s_len;
	print_f_value(var, '0');
	ft_putstr_tracked(str, var);
}

void	minus_s(t_printf *var, char *str)
{
	if (var->print_precision == FALSE)
		var->f_value -= var->s_len;
	ft_putstr_tracked(str, var);
	print_f_value(var, ' ');
}

void	arg_s(t_printf *var, va_list arg)
{
	char	*str;

	str = ft_strdup(va_arg(arg, char *));
	var->s_len = ft_strlen(str);
	if (var->precision == TRUE)
	{
		if (var->p_value_neg > 0)
		{
			print_p_s_value(var, &str);
			return ;
		}
		else if (var->s_len > var->p_value)
			precision_s(var, &str);
	}
	if (var->width == TRUE)
		width_s(var, str);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_s(var, str);
	else if (var->minus == TRUE)
		minus_s(var, str);
	else
		ft_putstr_tracked(str, var);
	free(str);
	str = NULL;
	struct_clean(var);
}
