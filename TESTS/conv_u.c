/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 13:53:12 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/26 00:41:55 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision_u(t_printf *var)
{
	if (var->p_value_neg > 0)
	{
		ft_putnbr_base_tracked(var->nb_u, "0123456789", var);
		while (var->p_value_neg > var->nb_len && var->p_value_neg-- > 0)
			ft_putchar_tracked(' ', var);
		return (-1);
	}
	else if (var->nb_len < var->p_value)
	{
		var->p_value = var->p_value - var->nb_len;
		var->f_value = var->f_value - var->nb_len - var->p_value;
		var->w_value = var->w_value - var->nb_len - var->p_value;
		var->print_precision = TRUE;
	}
	return (1);
}

void	width_u(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->w_value = var->w_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_u == 0)
		var->w_value++;
	print_w_value(var);
	if (var->print_precision == TRUE)
		print_p_value(var);
	ft_putnbr_base_tracked(var->nb_u, "0123456789", var);
}

void	zero_u(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->f_value = var->f_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_u == 0)
		var->f_value++;
	if (var->precision == TRUE)
	{
		print_f_value(var, ' ');
		if (var->print_precision == TRUE)
			print_p_value(var);
	}
	else
		print_f_value(var, '0');
	ft_putnbr_base_tracked(var->nb_u, "0123456789", var);
}

void	minus_u(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->f_value = var->f_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_u == 0)
		var->f_value++;
	if (var->print_precision == TRUE)
		print_p_value(var);
	ft_putnbr_base_tracked(var->nb_u, "0123456789", var);
	print_f_value(var, ' ');
}

void	arg_u(t_printf *var, va_list arg)
{
	var->nb_u = va_arg(arg, int);
	var->nb_len = ft_ulllen_base(var->nb_u, 10);
	if (var->precision == TRUE && precision_u(var) == -1)
		return ;
	if (var->width == TRUE)
		width_u(var);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_u(var);
	else if (var->minus == TRUE)
		minus_u(var);
	else
	{
		if (var->print_precision == TRUE)
			print_p_value(var);
		ft_putnbr_base_tracked(var->nb_u, "0123456789", var);
	}
	struct_clean(var);
}
