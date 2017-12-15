/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlavaury <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:30:53 by dlavaury          #+#    #+#             */
/*   Updated: 2017/12/15 16:01:35 by dlavaury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(t_data *data)
{
	/*if ((data->s = (char)va_arg(data->ap, unsigned)))
		ft_buffering(data, "(null)", 6);*/
}

void	ft_putstr_printf(t_data *data)
{
	data->s = (char*)va_arg(data->ap, unsigned*);
	if (data->s)
		ft_buffering(data, data->s, ft_strlen(data->s));
	else
		ft_buffering(data, "(null)", 6);
}
