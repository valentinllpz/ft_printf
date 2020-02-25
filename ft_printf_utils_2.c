/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlugand- <vlugand-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:44:56 by vlugand-          #+#    #+#             */
/*   Updated: 2020/02/26 00:40:00 by vlugand-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p_s_value(t_printf *var, char **str)
{
	while (var->p_value_neg > 0)
	{
		ft_putchar_tracked(' ', var);
		var->p_value_neg--;
	}
	free(*str);
	*str = NULL;
}

void	ft_putnbr_tracked(int nb, t_printf *var)
{
	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
					&& var->print_precision == FALSE && var->nb_di == 0)
		return ;
	if (var->min_flag == TRUE)
	{
		ft_putstr_tracked("2147483648", var);
		return ;
	}
	if (nb < 0)
		nb *= -1;
	if (nb < 10)
		ft_putchar_tracked(nb + '0', var);
	else
	{
		ft_putnbr_tracked(nb / 10, var);
		ft_putnbr_tracked(nb % 10, var);
	}
}

void	ft_putnbr_base_tracked(unsigned long nb, char *base, t_printf *var)
{
	unsigned long long	size;

	if (var->precision == TRUE && var->p_value == 0 && var->nb_di == 0
		&& var->print_precision == FALSE && var->nb_u == 0 && var->nb_p == 0)
		return ;
	size = ft_strlen(base);
	if (nb < size)
		ft_putchar_tracked(base[nb], var);
	else
	{
		ft_putnbr_base_tracked(nb / size, base, var);
		ft_putnbr_base_tracked(nb % size, base, var);
	}
}

int		ft_intlen(int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 1)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int		ft_ulllen_base(unsigned long long nb, int base_size)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb >= 1)
	{
		len++;
		nb /= base_size;
	}
	return (len);
}
