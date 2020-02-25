/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:18:11 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/25 18:42:59 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	va_list			arg;
	t_printf		var;
	static void		(*fct_conv[])(t_printf*, va_list) = {arg_c, arg_s, arg_p,
									arg_di, arg_di, arg_u, arg_x, arg_x, arg_c};

	va_start(arg, s);
	struct_init(&var);
	while (s[var.i])
	{
		if (s[var.i] == '%')
		{
			var.i++;
			while (s[var.i] && (s[var.i] == '.' || s[var.i] == '*' ||
					s[var.i] == '-' || (s[var.i] >= '0' && s[var.i] <= '9')))
				format_parsing(&var, s, arg);
			if ((var.conv = find_index(s[var.i], var.conv_set)) != -1)
				(*fct_conv[var.conv])(&var, arg);
		}
		else
			ft_putchar_tracked(s[var.i], &var);
		if (s[var.i])
			var.i++;
	}
	va_end(arg);
	return (var.len);
}
