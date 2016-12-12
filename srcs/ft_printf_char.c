/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:27:12 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/12 12:15:20 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(char out, t_arg *arg, int len)
{
	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			ft_putchar(out);
			ft_printf_putnchar(' ', arg->field_width - len);
		}
		else 
		{
			ft_printf_putnchar(' ', arg->field_width - len);
			ft_putchar(out);
		}
	}
	else
		ft_putchar(out);
}

int			ft_printf_char(t_arg *arg, va_list *lst)
{
	char	c;
	size_t		len;

	if (arg->length_mod == l)
		return (ft_printf_wchar(arg, lst));
	c = (char)va_arg(*lst, int);
	len = 1;
	padding(c, arg, len);
	return (len);
}