/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:25:24 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/26 00:36:31 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision_p(t_printf *var)
{
	if (var->p_value_neg > 0)
	{
		ft_putstr_tracked("0x", var);
		ft_putnbr_base_tracked(var->nb_p, "0123456789abcdef", var);
		while (var->p_value_neg > var->nb_len && var->p_value_neg-- > 0)
			ft_putchar_tracked(' ', var);
		return (-1);
	}
	else if (var->nb_len < var->p_value)
	{
		var->p_value = var->p_value - var->nb_len + 2;
		var->f_value = var->f_value - var->nb_len - var->p_value;
		var->w_value = var->w_value - var->nb_len - var->p_value;
		var->print_precision = TRUE;
	}
	return (1);
}

void	width_p(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->w_value = var->w_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_p == 0)
		var->w_value++;
	print_w_value(var);
	ft_putstr_tracked("0x", var);
	if (var->print_precision == TRUE)
		print_p_value(var);
	ft_putnbr_base_tracked(var->nb_p, "0123456789abcdef", var);
}

void	zero_p(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->f_value = var->f_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_p == 0)
		var->f_value++;
	if (var->precision == TRUE)
	{
		print_f_value(var, ' ');
		ft_putstr_tracked("0x", var);
		if (var->print_precision == TRUE)
			print_p_value(var);
	}
	else
	{
		ft_putstr_tracked("0x", var);
		print_f_value(var, '0');
	}
	ft_putnbr_base_tracked(var->nb_p, "0123456789abcdef", var);
}

void	minus_p(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->f_value = var->f_value - var->nb_len;
	if ((var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
						&& var->print_precision == FALSE) && var->nb_p == 0)
		var->f_value++;
	ft_putstr_tracked("0x", var);
	if (var->print_precision == TRUE)
		print_p_value(var);
	ft_putnbr_base_tracked(var->nb_p, "0123456789abcdef", var);
	print_f_value(var, ' ');
}

void	arg_p(t_printf *var, va_list arg)
{
	var->nb_p = va_arg(arg, unsigned long);
	var->nb_len = ft_ulllen_base(var->nb_p, 16) + 2;
	if (var->precision == TRUE && precision_p(var) == -1)
		return ;
	if (var->width == TRUE)
		width_p(var);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_p(var);
	else if (var->minus == TRUE)
		minus_p(var);
	else
	{
		ft_putstr_tracked("0x", var);
		if (var->print_precision == TRUE)
			print_p_value(var);
		ft_putnbr_base_tracked(var->nb_p, "0123456789abcdef", var);
	}
	struct_clean(var);
}
