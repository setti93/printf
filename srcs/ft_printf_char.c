/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:27:12 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/17 14:52:12 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(char out, t_arg *arg, int len)
{
	char	c;

	c = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set && arg->precision > 0)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			ft_putchar(out);
			ft_printf_putnchar(c, arg->field_width - len);
		}
		else
		{
			ft_printf_putnchar(c, arg->field_width - len);
			ft_putchar(out);
		}
	}
	else
		ft_putchar(out);
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_char(t_arg *arg, va_list *lst)
{
	char	c;
	size_t	len;

	if (arg->conversion == '%')
		c = '%';
	else
	{
		if (arg->length_mod == l)
			return (ft_printf_wchar(arg, lst));
		c = (char)va_arg(*lst, int);
	}
	len = 1;
	padding(c, arg, len);
	return (len);
}
