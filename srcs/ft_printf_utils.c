/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:52:38 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/17 16:17:21 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_internal.h"

void	ft_printf_putnchar(char c, int times)
{
	while (times--)
		write(1, &c, 1);
}

int		idigits(intmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int		udigits(uintmax_t n, int base)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

int		get_int_arg(va_list *lst)
{
	int		res;

	res = va_arg(*lst, int);
	return (res);
}
