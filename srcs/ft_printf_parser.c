/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:58:05 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/19 18:13:58 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_internal.h"

static int	parse_len(char *str, t_arg *arg)
{
	if (*str == 'h' && *(str + 1) == 'h')
	{
		arg->length_mod = ft_max(arg->length_mod, hh);
		return (2);
	}
	else if (*str == 'l' && *(str + 1) == 'l')
	{
		arg->length_mod = ft_max(arg->length_mod, ll);
		return (2);
	}
	else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
	{
		if (*str == 'h')
			arg->length_mod = ft_max(arg->length_mod, h);
		else if (*str == 'l')
			arg->length_mod = ft_max(arg->length_mod, l);
		else if (*str == 'j')
			arg->length_mod = ft_max(arg->length_mod, j);
		else if (*str == 'z')
			arg->length_mod = ft_max(arg->length_mod, z);
		return (1);
	}
	return (0);
}

static int	parse_flag(char *str, t_arg *arg)
{
	if (*str == '#')
		arg->flag_alt = 1;
	else if (*str == '0')
		arg->flag_zero = 1;
	else if (*str == '-')
		arg->flag_left = 1;
	else if (*str == ' ')
		arg->flag_space = 1;
	else if (*str == '+')
		arg->flag_sign = 1;
	else
		return (0);
	return (1);
}

static int	parse_num(char *str, t_arg *arg, va_list *lst)
{
	if (*str == '.')
	{
		arg->prec_set = 1;
		arg->precision = ((str[1] == '*') ? \
		get_int_arg(lst) : ft_atoi(str + 1));
		arg->precision = (arg->precision < 0) ? 0 : arg->precision;
		return (1 + idigits(arg->precision, 10) - (ft_isdigit(str[1]) ? 0 : 1));
	}
	else if (ft_isdigit(*str) || *str == '*')
	{
		arg->field_width = ((*str == '*') ? \
		get_int_arg(lst) : ft_atoi(str));
		if (arg->field_width < 0 && \
		(arg->field_width = ft_abs(arg->field_width)))
			arg->flag_left = 1;
		return (idigits(arg->field_width, 10));
	}
	return (0);
}

static int	parse(char *str, t_arg *arg, int len, va_list *lst)
{
	int		idx;
	int		cnt;

	idx = 0;
	while (idx < len)
	{
		if ((cnt = parse_flag(str + idx, arg)) && (idx += cnt))
			continue ;
		else if ((cnt = parse_len(str + idx, arg)) && (idx += cnt))
			continue ;
		else if ((cnt = parse_num(str + idx, arg, lst)) && (idx += cnt))
			continue ;
		return (0);
	}
	if (arg->flag_left)
		arg->flag_zero = 0;
	return (1);
}

int			ft_printf_parse_arg(char *str, t_arg *arg, va_list *lst)
{
	int		idx;
	int		isconv;

	idx = 1;
	isconv = 1;
	while (str[idx] && !ft_strchr(FT_PRINTF_CONVERSION, str[idx]))
	{
		if (!ft_strchr(FT_PRINTF_CSET, str[idx]) && !(isconv = 0))
			break ;
		idx++;
	}
	arg->conversion = str[idx];
	parse(str + 1, arg, idx - 1, lst);
	if (!str[idx])
		idx--;
	return (idx + 1);
}
