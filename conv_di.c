/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 18:49:26 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/26 00:35:34 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision_di(t_printf *var)
{
	if (var->p_value_neg > 0)
	{
		ft_putnbr_tracked(var->nb_di, var);
		while (var->p_value_neg > var->nb_len && var->p_value_neg-- > 0)
			ft_putchar_tracked(' ', var);
		return (-1);
	}
	else if ((var->nb_len - var->nb_neg) < var->p_value)
	{
		var->p_value = var->p_value - var->nb_len + var->nb_neg;
		var->f_value = var->f_value - var->nb_len - var->p_value;
		var->w_value = var->w_value - var->nb_len - var->p_value;
		var->print_precision = TRUE;
	}
	return (1);
}

void	width_di(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->w_value = var->w_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_di == 0)
		var->w_value++;
	print_w_value(var);
	if (var->nb_neg == TRUE)
		ft_putchar_tracked('-', var);
	if (var->print_precision == TRUE)
		print_p_value(var);
	ft_putnbr_tracked(var->nb_di, var);
}

void	zero_di(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->f_value = var->f_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_di == 0)
		var->f_value++;
	if (var->precision == TRUE)
	{
		print_f_value(var, ' ');
		if (var->nb_neg == TRUE)
			ft_putchar_tracked('-', var);
		if (var->print_precision == TRUE)
			print_p_value(var);
	}
	else
	{
		if (var->nb_neg == TRUE)
			ft_putchar_tracked('-', var);
		print_f_value(var, '0');
	}
	ft_putnbr_tracked(var->nb_di, var);
}

void	minus_di(t_printf *var)
{
	if (var->print_precision == FALSE)
		var->f_value = var->f_value - var->nb_len;
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_di == 0)
		var->f_value++;
	if (var->nb_neg == TRUE)
		ft_putchar_tracked('-', var);
	if (var->print_precision == TRUE)
		print_p_value(var);
	ft_putnbr_tracked(var->nb_di, var);
	print_f_value(var, ' ');
}

void	arg_di(t_printf *var, va_list arg)
{
	var->nb_di = va_arg(arg, int);
	if (var->nb_di < 0)
	{
		var->nb_neg = TRUE;
		if (var->nb_di == INT_MIN)
			var->min_flag = TRUE;
	}
	var->nb_len = ft_intlen(var->nb_di);
	if (var->precision == TRUE && precision_di(var) == -1)
		return ;
	if (var->width == TRUE)
		width_di(var);
	else if (var->zero == TRUE && var->minus == FALSE)
		zero_di(var);
	else if (var->minus == TRUE)
		minus_di(var);
	else
	{
		if (var->nb_neg == TRUE)
			ft_putchar_tracked('-', var);
		if (var->print_precision == TRUE)
			print_p_value(var);
		ft_putnbr_tracked(var->nb_di, var);
	}
	struct_clean(var);
}
