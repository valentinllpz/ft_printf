/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:30:27 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/24 18:53:37 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_tracked(char c, t_printf *var)
{
	write(1, &c, 1);
	var->len++;
}

void	ft_putstr_tracked(char *s, t_printf *var)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_tracked(s[i], var);
			i++;
		}
	}
}

void	print_p_value(t_printf *var)
{
	while (var->p_value > 0)
	{
		ft_putchar_tracked('0', var);
		var->p_value--;
	}
}

void	print_w_value(t_printf *var)
{
	while (var->w_value > 0)
	{
		ft_putchar_tracked(' ', var);
		var->w_value--;
	}
}

void	print_f_value(t_printf *var, char c)
{
	while (var->f_value > 0)
	{
		ft_putchar_tracked(c, var);
		var->f_value--;
	}
}
