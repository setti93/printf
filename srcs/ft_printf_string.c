/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 12:10:12 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/11 17:37:01 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(const char *out, t_arg *arg, int len)
{
	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			write(1, out, len);
			ft_printf_putnchar(' ', arg->field_width - len);
		}
		else 
		{
			ft_printf_putnchar(' ', arg->field_width - len);
			write(1, out, len);
		}
	}
	else
		ft_putstr(out);
}

int			ft_printf_string(t_arg *arg, va_list *lst)
{
	const char	*str;
	size_t		len;

	if (arg->length_mod == l)
		return (ft_printf_wstring(arg, lst));
	str = va_arg(*lst, char*);
	len = ft_strlen(str);
	padding(str, arg, len);
	return (len);
}
