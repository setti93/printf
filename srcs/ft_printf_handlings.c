/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handlings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:46:29 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/08 17:51:50 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"
#include "ft_printf_handler.h"

extern t_handler g_table[];

void	ft_printf_handler(t_arg *arg, va_list *lst)
{
	int i;

	i = 0;
	while (g_table[i].conv != 0)
	{
		if (g_table[i].conv == arg->conversion)
		{
			g_table[i].f(arg, lst);
			return ;
		}
		i++;
	}
}