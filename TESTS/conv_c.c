/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 15:25:32 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/26 00:36:05 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		precision_c(t_printf *var, char c)
{
	if (var->p_value_neg > 0)
	{
		var->p_value_neg--;
		ft_putchar_tracked(c, var);
		while (var->p_value_neg-- > 0)
			ft_putchar_tracked(' ', var);
		return (-1);
	}
	return (1);
}

void	width_c(t_printf *var, char c)
{
	var->w_value--;
	print_w_value(var);
	ft_putchar_tracked(c, var);
}

void	zero_c(t_printf *var, char c)
{
	var->f_value--;
	print_f_value(var, '0');
	ft_putchar_tracked(c, var);
}

void	minus_c(t_printf *var, char c)
{
	var->f_value--;
	ft_putchar_tracked(c, var);
	print_f_value(var, ' ');
}

void	arg_c(t_printf *var, va_list arg)
{
	char	c;

	if (var->conv == 8)
		c = '%';
	else
		c = va_arg(arg, int);
	if (var->precision == TRUE && precision_c(var, c) == -1)
		return ;
	if (var->width == TRUE && var->w_value > 1)
		width_c(var, c);
	else if (var->zero == TRUE && var->minus == FALSE && var->f_value > 1)
		zero_c(var, c);
	else if (var->minus == TRUE && var->f_value > 1)
		minus_c(var, c);
	else
		ft_putchar_tracked(c, var);
	struct_clean(var);
}
